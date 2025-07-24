//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define MAX_PACKET_LEN 65535 

int main(int argc, char **argv) {

    char *dev;  
    char errbuf[PCAP_ERRBUF_SIZE]; 
    pcap_t *handle; 
    struct pcap_pkthdr header; 
    const u_char *packet; 

    // Configuration options
    int snaplen = MAX_PACKET_LEN;   
    int promiscmode = 1;  
    int timeout = 1000;  

    // Initialize Pcap
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 1;
    }

    handle = pcap_open_live(dev, snaplen, promiscmode, timeout, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }

    // Sniff packets
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) continue; // If no packet captured, continue
        printf("Packet captured!\n");
        // Insert the logic to process/analyze the packet here.
    }

    pcap_close(handle);
    return 0;
}