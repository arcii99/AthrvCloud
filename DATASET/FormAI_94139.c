//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Ken Thompson
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printPacket(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    int i = 0;
    printf("Packet Capture Length: %d\n", header->caplen);
    printf("Packet Total Length: %d\n", header->len);
    for(i=0;i<header->caplen;i++) {
        printf("%02x ", packet[i]);
        if((i+1)%16==0) {
            printf("\n");
        }
     }
     printf("\n");
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    char *devname = pcap_lookupdev(errbuf);
    pcap_t *handle;
    int packetCount = 0;

    if(devname == NULL) {
        printf("Error finding default device: %s\n", errbuf);
        exit(1);
    }
    printf("Device found: %s\n", devname);

    handle = pcap_open_live(devname, BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL) {
        printf("Error opening device: %s\n", errbuf);
        exit(1);
    }

    pcap_loop(handle, -1, printPacket, NULL);
    pcap_close(handle);

    return 0;
}