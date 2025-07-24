//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* Declare callbacks */
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE]; // Error buffer
    pcap_t *handle; // Session handle
    struct bpf_program fp; // The compiled filter expression
    bpf_u_int32 netmask; // The netmask of our sniffing device
    struct pcap_pkthdr header; // The header that pcap gives us
    const u_char *packet; // The actual packet

    // Get the network device for sniffing
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        printf("Couldn't find default device: %s\n", errbuf);
        return 1;
    }

    // Open the session in promiscuous mode
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }

    // Compile and apply the filter
    if (pcap_compile(handle, &fp, "icmp", 0, netmask) == -1) {
        printf("Couldn't parse filter %s: %s\n", "icmp", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Couldn't install filter %s: %s\n", "icmp", pcap_geterr(handle));
        return 1;
    }

    // Capture packets
    printf("Starting packet capture...\n");
    pcap_loop(handle, 0, packet_handler, NULL);

    // Close the session
    pcap_close(handle);

    return 0;
}

/* Define packet handler */
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    printf("Packet captured!\n");
    printf("Timestamp: %ld.%06ld\n", header->ts.tv_sec, header->ts.tv_usec);
    printf("Length: %d\n", header->len);
    printf("Source MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n",
           pkt_data[6], pkt_data[7], pkt_data[8], pkt_data[9], pkt_data[10], pkt_data[11]);
    printf("Destination MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n",
           pkt_data[0], pkt_data[1], pkt_data[2], pkt_data[3], pkt_data[4], pkt_data[5]);
    printf("Protocol: %04x\n", ntohs(*((unsigned short *)(pkt_data + 12))));
    printf("\n");
}