//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: brave
#include <stdio.h>
#include <pcap.h>

/* This program captures and prints the first 5 packets 
   that are received on the first available network interface */

int main(int argc, char *argv[]) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr header;
    const u_char *packet;

    // Get the name of the first available network interface
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 1;
    }

    // Open the network interface for packet capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }

    // Capture and print the first 5 packets
    printf("Listening on device %s...\n", dev);
    for (int i = 0; i < 5; i++) {
        packet = pcap_next(handle, &header);
        printf("Packet %d:\n", i);
        printf("    Length: %d bytes\n", header.len);
        printf("    Packet Contents:\n");
        for (int j = 0; j < header.len; j++) {
            printf("%02x ", packet[j]);
            if ((j + 1) % 8 == 0) printf("\n");
            if ((j + 1) % 16 == 0) printf("\n");
        }
        printf("\n\n");
    }

    // Close the packet capture session
    pcap_close(handle);

    return 0;
}