//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 65535

void packet_handler(u_char *args, const struct pcap_pkthdr *header,
                    const u_char *packet) {
    // TODO: Implement packet handling code
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_expr[] = "tcp port 80";
    bpf_u_int32 net;
    bpf_u_int32 mask;

    // check for proper usage
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [interface]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // get network and mask from the interface
    if (pcap_lookupnet(argv[1], &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Error getting network and mask: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // open the interface for capturing
    handle = pcap_open_live(argv[1], MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening interface: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // filter packets using BPF
    if (pcap_compile(handle, &fp, filter_expr, 0, net) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // start capturing packets
    printf("Starting packet capture on interface %s...\n", argv[1]);
    pcap_loop(handle, -1, packet_handler, NULL);

    // cleanup
    pcap_close(handle);
    return 0;
}