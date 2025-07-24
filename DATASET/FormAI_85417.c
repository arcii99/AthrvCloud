//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: surprised
#include <stdio.h>
#include <pcap.h>

int main() {
    printf("Welcome to the unique C Packet Capturer program using PCAP library!\n");
    printf("Are you ready to capture some network packets? Let's go!\n");

    char errbuf[PCAP_ERRBUF_SIZE]; // Error buffer for pcap functions
    pcap_t *pcap_handle; // Pointer to the pcap session

    // Find the network interface to capture packets on
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    printf("Network interface found: %s\n", dev);

    // Set up the session with a timeout of 10 seconds
    pcap_handle = pcap_create(dev, errbuf);
    pcap_set_snaplen(pcap_handle, 65535);
    pcap_set_promisc(pcap_handle, 1);
    pcap_set_timeout(pcap_handle, 10000);

    // Activate the session
    if (pcap_activate(pcap_handle) != 0) {
        printf("Error activating the pcap session: %s\n", pcap_geterr(pcap_handle));
        pcap_close(pcap_handle);
        return 1;
    }

    // Start capturing packets
    printf("\nStarting packet capture on interface %s...\n", dev);

    struct pcap_pkthdr header;
    const u_char *packet;

    while (1) {
        packet = pcap_next(pcap_handle, &header);
        if (packet == NULL) {
            printf("No packet captured within the timeout period.\n");
            continue;
        }

        // Print out packet details
        printf("\nPacket captured! Packet length: %d\n", header.len);
        pcap_dump(packet, &header, stdout);
    }

    // Close the session
    pcap_close(pcap_handle);

    return 0;
}