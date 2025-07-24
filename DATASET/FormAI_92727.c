//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *arg, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *capture_handle;
    int packet_count_limit = 10; // limit the number of packets to 10

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // open the capture device
    capture_handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (capture_handle == NULL) {
        fprintf(stderr, "Error opening capture device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // set a filter to capture only TCP packets
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    if (pcap_compile(capture_handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Error compiling filter expression: %s\n", pcap_geterr(capture_handle));
        exit(EXIT_FAILURE);
    }
    if (pcap_setfilter(capture_handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(capture_handle));
        exit(EXIT_FAILURE);
    }

    // start capturing packets
    printf("Starting capture on interface %s...\n", argv[1]);
    pcap_loop(capture_handle, packet_count_limit, packet_handler, NULL);

    // cleanup
    pcap_freecode(&fp);
    pcap_close(capture_handle);

    return EXIT_SUCCESS;
}

void packet_handler(u_char *arg, const struct pcap_pkthdr *header, const u_char *packet) {
    // handle the packet here
    printf("Packet captured with length: %d\n", header->len);
}