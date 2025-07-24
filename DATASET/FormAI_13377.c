//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char **argv) {
    char errbuff[PCAP_ERRBUF_SIZE];
    char *dev = pcap_lookupdev(errbuff);

    if(dev == NULL) {
        printf("No device found. Exiting program.\n");
        exit(1);
    }

    printf("Device found: %s\n", dev);
    
    pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuff);

    if(handle == NULL) {
        printf("Could not open device. Exiting program.\n");
        exit(1);
    }

    struct pcap_pkthdr header;
    const u_char *packet;
    
    while(1) {
        packet = pcap_next(handle, &header);
        printf("Received a packet with length of %d\n", header.len);
        printf("Packet contents:\n");
        for(int i = 0; i < header.len; i++) {
            printf("%x ", packet[i]);
        }
        printf("\n");
    }

    pcap_close(handle);
    return 0;
}