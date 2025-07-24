//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h> // pcap library header

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    printf("Packet Captured!\n");
    int i=0;
    for(i=0; i<pkthdr->len; i++) {
        printf(" %.2x", packet[i]);
        if((i%16==15) || (i==pkthdr->len-1))
            printf("\n");
    }
}

int main(int argc, char **argv) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* descr;
    struct pcap_pkthdr hdr;
    struct ether_header *eptr;
    const u_char* packet;
    
    // Step 1: Find a live device to capture packets from using pcap_lookupdev()
    dev = pcap_lookupdev(errbuf);
    if(dev == NULL) {
        printf("%s\n", errbuf);
        exit(1);
    }
    
    // Step 2: Open the device for capturing using pcap_open_live()
    descr = pcap_open_live(dev, BUFSIZ, 1, -1, errbuf);
    if(descr == NULL) {
        printf("pcap_open_live(): %s\n", errbuf);
        exit(1);
    }
    
    // Step 3: Capture packets using pcap_loop()
    if(pcap_loop(descr, 10, packet_handler, NULL) < 0) {
        printf("pcap_loop failed: %s\n", pcap_geterr(descr));
        exit(1);
    }
    
    // Step 4: Close the device using pcap_close()
    pcap_close(descr);
    printf("Packet capture completed.\n");
    return 0;
}