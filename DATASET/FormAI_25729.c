//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define SNAP_LEN 65535

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char const *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    char *devname;
    pcap_t *dev;

    // find the first available network device
    devname = pcap_lookupdev(errbuf);
    if (devname == NULL) {
        fprintf(stderr, "pcap_lookupdev() failed: %s\n", errbuf);
        exit(1);
    }

    // open the network device for capturing
    dev = pcap_open_live(devname, SNAP_LEN, 1, 1000, errbuf);
    if (dev == NULL) {
        fprintf(stderr, "pcap_open_live() failed: %s\n", errbuf);
        exit(1);
    }

    printf("Listening on %s...\n", devname);

    // start the packet capture loop
    pcap_loop(dev, -1, process_packet, NULL);

    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // process the packet here
    printf("Received a packet\n");
}