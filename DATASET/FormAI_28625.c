//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    static int packetCount = 0; // Count packets we've seen

    printf("Packet %d:\n", ++packetCount); // Print out the packet number
    printf("    Length: %d bytes\n", pkthdr->len); // Print out the length of the packet

    for (int i = 0; i < pkthdr->len; i++) {
        printf("%02x ", packet[i]); // Print out the packet data
    }

    printf("\n\n"); // Print a blank line to separate packets
}

int main() {
    char* device = "eth0"; // The device to capture network packets

    pcap_t* handle;
    char errbuf[PCAP_ERRBUF_SIZE]; // Error message buffer

    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf); // Open the capture device with a buffer size of BUFSIZ
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, errbuf);
        exit(1);
    }

    if (pcap_datalink(handle) != DLT_EN10MB) { // Make sure we're capturing Ethernet packets
        fprintf(stderr, "Device %s doesn't capture Ethernet packets\n", device);
        exit(1);
    }

    pcap_loop(handle, -1, packetHandler, NULL); // Start capturing packets

    pcap_close(handle); // Close the capture device

    return 0;
}