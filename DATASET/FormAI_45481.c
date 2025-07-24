//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Handle each incoming packet here
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = NULL;
    int snaplen = 65535;
    int promisc = 1;
    int ret;

    // Check if enough arguments are provided
    if (argc < 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        exit(1);
    }

    // Open the capture device
    handle = pcap_open_live(argv[1], snaplen, promisc, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        exit(1);
    }

    // Set a filter (optional)
    struct bpf_program fp;
    char filter_exp[] = "tcp port 80";
    if (pcap_compile(handle, &fp, filter_exp, 0, 0) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        exit(1);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Start capturing packets
    ret = pcap_loop(handle, 0, packet_handler, NULL);
    if (ret == -1) {
        fprintf(stderr, "Error capturing packets: %s\n", pcap_geterr(handle));
    }

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}