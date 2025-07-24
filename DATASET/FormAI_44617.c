//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: grateful
#include <pcap.h>
#include <stdlib.h>
#include <stdio.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {

    char *dev = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle;

    dev = pcap_lookupdev(errbuf);

    if(dev == NULL) {
        printf("pcap_lookupdev() failed: %s\n", errbuf);
        exit(1);
    }

    printf("Listening on device: %s\n", dev);

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

    if(handle == NULL) {
        printf("pcap_open_live() failed: %s\n", errbuf);
        exit(1);
    }

    if(pcap_datalink(handle) != DLT_EN10MB) {
        printf("This program only supports Ethernet networks\n");
        exit(1);
    }

    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_close(handle);
    printf("Capture complete.\n");

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {

    static int packet_count = 0;

    printf("Packet %d:\n", ++packet_count);

    printf("\tTimestamp: %ld.%06ld\n", header->ts.tv_sec, header->ts.tv_usec);
    printf("\tLength: %d bytes\n", header->len);

    for(int i=0; i<header->len; i++) {
        printf("%02x ", packet[i]);
        if((i + 1) % 16 == 0) printf("\n");
    }

    printf("\n\n");
}