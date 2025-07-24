//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *user, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
    printf("Received a packet of length %d\n", pkthdr->len);
    // Do some analysis on the packet here
}

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char *dev;
    bpf_u_int32 net, mask;
    struct bpf_program filter;
    char *filter_exp = "tcp port 80";
    const int packets_to_capture = 10;

    // Get default device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 1;
    }

    // Get network and mask
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get network and mask for device %s: %s\n", dev, errbuf);
        return 1;
    }

    // Open device for sniffing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }

    // Set filter expression
    if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter expression %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // Apply filter
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // Start packet capturing
    pcap_loop(handle, packets_to_capture, packet_handler, NULL);

    // Close device handle
    pcap_close(handle);

    return 0;
}