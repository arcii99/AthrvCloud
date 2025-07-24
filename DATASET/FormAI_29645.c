//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: decentralized
/*
 * A decentralized packet capturer example program using the pcap library.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define SNAP_LEN 65535
#define PROMISC_MODE 1
#define TIMEOUT_MS 1000

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // insert your packet processing logic here
    printf("Received a %d byte packet\n", header->len);
}

int main(int argc, char *argv[]) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 mask, net;

    // find a suitable network interface
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // get the network address and netmask of the selected interface
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // open the capture handle
    handle = pcap_open_live(dev, SNAP_LEN, PROMISC_MODE, TIMEOUT_MS, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        exit(EXIT_FAILURE);
    }

    // set the filter expression if provided
    if (argc == 2) {
        if (pcap_compile(handle, &fp, argv[1], 0, net) == -1) {
            fprintf(stderr, "Couldn't parse filter %s: %s\n", argv[1], pcap_geterr(handle));
            exit(EXIT_FAILURE);
        }
        if (pcap_setfilter(handle, &fp) == -1) {
            fprintf(stderr, "Couldn't install filter %s: %s\n", argv[1], pcap_geterr(handle));
            exit(EXIT_FAILURE);
        }
    }

    // start the packet capture loop
    pcap_loop(handle, -1, process_packet, NULL);

    // cleanup resources
    pcap_freecode(&fp);
    pcap_close(handle);

    return EXIT_SUCCESS;
}