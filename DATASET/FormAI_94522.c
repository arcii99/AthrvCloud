//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Ada Lovelace
#include <pcap.h>
#include <stdio.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main() {
    char errbuf[PCAP_ERRBUF_SIZE]; // Error buffer
    pcap_t *handle; // Session handle
    struct bpf_program fp; // The compiled filter
    char filter_exp[] = "tcp port 80"; // The filter expression
    bpf_u_int32 mask; // The netmask of our sniffing device
    bpf_u_int32 net; // The IP address of our sniffing device
    int num_packets = 10; // Number of packets to capture

    // Get the default network device for packet capture
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 1;
    }
    printf("Device: %s\n", dev);

    // Get the network address and mask of the sniffing device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open the session in promiscuous mode
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }

    // Compile and apply the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets
    pcap_loop(handle, num_packets, packet_handler, NULL);

    // Close the session
    pcap_close(handle);
    printf("\nCapture complete.\n");

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    static int count = 1;

    // Print the packet number
    printf("Packet number %d:\n", count);
    count++;

    // Print the timestamp and length of the packet
    printf("Timestamp: %ld.%06ld seconds\n", header->ts.tv_sec, header->ts.tv_usec);
    printf("Packet Length: %d bytes\n", header->len);
}