//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: modular
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char *argv[]) {
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Get the name of the first available device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 2;
    }

    printf("Listening on %s...\n", dev);

    pcap_t *handle;
    int timeout_limit = 10000;

    // Open the device for sniffing
    handle = pcap_open_live(dev, BUFSIZ, 1, timeout_limit, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 2;
    }

    // Start capturing packets
    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    int i;
    printf("Packet size: %d bytes\n", header->len);
    for (i=0; i<header->len; i++) {
        printf("%02x ", *(pkt_data + i));
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
    printf("\n\n");
}