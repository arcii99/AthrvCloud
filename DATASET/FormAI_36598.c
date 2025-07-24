//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: romantic
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SNAP_LEN 1518
#define SIZE_ETHERNET 14

void packet_handler(u_char *user, const struct pcap_pkthdr *header, const u_char *packet) {
    // This is called for every packet captured
    printf("Packet captured!\n");
}

int main(int argc, char **argv) {
    char *dev = NULL;                  // Device to capture packets from
    char errbuf[PCAP_ERRBUF_SIZE];     // Error buffer
    pcap_t *handle;                    // Handle to the pcap session
    struct bpf_program filter;         // The compiled BPF filter
    bpf_u_int32 mask;                  // The netmask of the sniffing device
    bpf_u_int32 net;                   // The IP address of the sniffing device

    // Get the device to capture packets from
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }
    printf("Device: %s\n", dev);

    // Get the netmask and IP address of the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask and IP address: %s\n", errbuf);
        net = 0;
        mask = 0;
    }
    printf("Netmask: %u\n", mask);
    printf("IP address: %u\n", net);

    // Open the session in promiscuous mode
    handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Compile and apply the filter
    if (pcap_compile(handle, &filter, "udp port 53", 1, net) == -1) {
        fprintf(stderr, "Couldn't parse filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Couldn't install filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Capture packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // Clean up
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}