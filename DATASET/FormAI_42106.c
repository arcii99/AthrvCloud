//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: portable
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>

void my_packet_handler(
    u_char *args,
    const struct pcap_pkthdr *header,
    const u_char *packet
);

int main(int argc, char **argv) {

    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 net;
    bpf_u_int32 mask;

    // Find a device to capture packets on
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n",
            errbuf);
        return(1);
    }

    // Get the network and mask information for the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n",
            dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open the capture device
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(1);
    }

    // Compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n",
            filter_exp, pcap_geterr(handle));
        return(1);
    }

    // Apply the filter expression
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n",
            filter_exp, pcap_geterr(handle));
        return(1);
    }

    // Start capturing packets
    pcap_loop(handle, 0, my_packet_handler, NULL);

    // Close the capture device and free the memory
    pcap_freecode(&fp);
    pcap_close(handle);

    printf("Packet capture complete.\n");

    return(0);
}

void my_packet_handler(
    u_char *args,
    const struct pcap_pkthdr *header,
    const u_char *packet
) {
    static int packet_count = 0;

    // Print if a packet is IPv4
    if (packet[12] == 0x08 && packet[13] == 0x00) {
        printf("\nIPv4 Packet #%d:\n", ++packet_count);
        printf("\tSource MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n",
            packet[6],packet[7],packet[8],packet[9],packet[10],packet[11]);
        printf("\tDestination MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n",
            packet[0],packet[1],packet[2],packet[3],packet[4],packet[5]);
        printf("\tSource IP address: %d.%d.%d.%d\n",
            packet[26],packet[27],packet[28],packet[29]);
        printf("\tDestination IP address: %d.%d.%d.%d\n",
            packet[30],packet[31],packet[32],packet[33]);
        printf("\tProtocol: %d\n", packet[23]);
        printf("\tPacket length: %d\n", header->len);
    }
}