//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define SNAP_LEN 65535
#define SIZE_ETHERNET 14

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char const *argv[]) {
    char *dev = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    const char *filter_exp = "tcp";
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;

    // Checking if a network device name was provided, otherwise use default
    if (argc > 1) {
        dev = argv[1];
    } else {
        dev = pcap_lookupdev(errbuf);
        if (dev == NULL) {
            fprintf(stderr, "Could not find any available network devices. Error: %s\n", errbuf);
            exit(EXIT_FAILURE);
        }
    }

    // Getting network device mask and IP
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Could not get netmask for device %s. Error: %s\n", dev, errbuf);
        exit(EXIT_FAILURE);
    }

    // Opening a live capture handle on the network device
    handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s. Error: %s\n", dev, errbuf);
        exit(EXIT_FAILURE);
    }

    // Compiling the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Could not compile filter. Error: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Applying the compiled filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Could not apply filter. Error: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Start capturing packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close capture handle
    pcap_close(handle);

    return EXIT_SUCCESS;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    static int packet_count = 0;

    // Print out the packet count and its size in bytes
    printf("Packet #%d: %d bytes\n", ++packet_count, header->len);
}