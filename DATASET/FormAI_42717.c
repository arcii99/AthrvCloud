//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void process_packet(u_char *, const struct pcap_pkthdr *, const u_char *);

int main(int argc, char **argv) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // get the default network device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 1;
    }
    printf("Using device: %s\n", dev);

    // open the device for packet capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }

    // start capturing packets
    printf("Monitoring packets...\n");
    pcap_loop(handle, -1, process_packet, NULL);

    // cleanup
    pcap_close(handle);
    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // print packet length
    printf("Packet length: %d\n", header->len);

    // print each byte of the packet
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
    }
    printf("\n\n");
}