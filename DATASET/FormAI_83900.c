//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void capture_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured with length %d\n", header->len);
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    char *dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Unable to find a valid device: %s\n", errbuf);
        return 1;
    }

    pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }

    if (pcap_datalink(handle) != DLT_EN10MB) {
        fprintf(stderr, "Device %s doesn't provide Ethernet headers - not supported\n", dev);
        return 1;
    }

    if (pcap_loop(handle, -1, capture_packet, NULL) < 0) {
        fprintf(stderr, "Couldn't start packet capture: %s\n", pcap_geterr(handle));
        return 1;
    }

    pcap_close(handle);
    return 0;
}