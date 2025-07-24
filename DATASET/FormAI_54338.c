//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: expert-level
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/if_ether.h>

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    int *counter = (int*)userData; // Cast the user data
    printf("Packet Count: %d\n", ++(*counter)); // Print packet count
    printf("Received packet size: %d\n\n", pkthdr->len); // Print packet size
}

int main(int argc, char **argv) {
    pcap_t *descr;
    char errbuf[PCAP_ERRBUF_SIZE];

    if(argc < 2) {
        printf("Usage: %s [pcap file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    descr = pcap_open_offline(argv[1], errbuf); // Open pcap file for reading

    if(descr == NULL) {
        printf("pcap_open_offline(): %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    printf("Packet capturing started...\n");

    int counter = 0;
    pcap_loop(descr, 0, packet_handler, (u_char*)&counter); // Capture packets infinitely

    printf("Packet capturing ended.\n");

    return 0;
}