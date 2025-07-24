//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *user, const struct pcap_pkthdr *header, const u_char *packet) {
    // Do something with packet data
    printf("Received a packet\n");
}

int main(int argc, char **argv) {
    char *dev = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = NULL;
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;

    // Find a suitable device to capture packets on
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 1;
    }

    // Open the network device for capturing packets
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }

    // Get the network address and mask for the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Compile the filter expression
    if (pcap_compile(handle, &fp, "port 80", 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter expression: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Apply the compiled filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // Clean up
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}