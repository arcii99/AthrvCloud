//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

// Function to process each captured packet
void process_packet(u_char *arg, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
    printf("Packet Captured.\n");

    // Print the length of the packet
    printf("Packet length: %d\n", pkthdr->len);

    // Print the content of the packet
    for (int i=0; i<pkthdr->len; i++) {
        printf("%02x ", packet[i]);
        if ((i+1) % 16 == 0)
            printf("\n");
    }
    printf("\n\n");
}

int main() {
    // Declare variables
    char errbuf[PCAP_ERRBUF_SIZE]; // Error buffer
    pcap_t *pcap_handle; // Packet capture handle
    int timeout_limit = 10000; // In milliseconds

    // Find a capture device
    char *device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        fprintf(stderr, "Error finding a capture device: %s\n", errbuf);
        exit(1);
    }

    // Open the capture device
    pcap_handle = pcap_open_live(device, BUFSIZ, 1, timeout_limit, errbuf);
    if (pcap_handle == NULL) {
        fprintf(stderr, "Error opening capture device %s: %s\n", device, errbuf);
        exit(1);
    }

    // Compile the filter expression
    struct bpf_program filter;
    char filter_exp[] = "tcp port 80"; // Filter for HTTP traffic
    int ret = pcap_compile(pcap_handle, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN);
    if (ret == -1) {
        fprintf(stderr, "Error compiling filter expression: %s\n", pcap_geterr(pcap_handle));
        exit(1);
    }

    // Set the filter expression
    ret = pcap_setfilter(pcap_handle, &filter);
    if (ret == -1) {
        fprintf(stderr, "Error setting filter expression: %s\n", pcap_geterr(pcap_handle));
        exit(1);
    }

    // Start capturing packets
    printf("Monitoring network packets on device %s...\n", device);
    pcap_loop(pcap_handle, -1, process_packet, NULL);

    // Close the capture device
    pcap_close(pcap_handle);

    return 0;
}