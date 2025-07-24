//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* This program uses pcap library to capture network packets. */

#define SNAP_LEN 1518

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet capture length: %d\n", header->caplen);
    printf("Packet total length:   %d\n", header->len);
}

int main(int argc, char **argv) {
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        printf("ERROR: %s\n", errbuf);
        return 1;
    }
    printf("Device: %s\n", dev);

    handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("ERROR: %s\n", errbuf);
        return 1;
    }

    if (pcap_datalink(handle) != DLT_EN10MB) {
        printf("ERROR: This program only works on Ethernet networks.\n");
        return 1;
    }

    if (pcap_loop(handle, 0, packet_handler, NULL) == -1) {
        printf("ERROR: %s\n", pcap_geterr(handle));
        return 1;
    }

    pcap_close(handle);
    return 0;
}