//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer);

int main(int argc, char *argv[]) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "port 80";
    bpf_u_int32 net;

    if (argc < 2) {
        printf("Please provide an interface name as an argument\n");
        return -1;
    }

    // open interface for capturing
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Couldn't open device %s: %s\n", argv[1], errbuf);
        return -1;
    }

    // compile and apply filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        printf("Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return -1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return -1;
    }

    // start capturing packets
    pcap_loop(handle, -1, process_packet, NULL);

    pcap_close(handle);
    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer) {
    printf("Packet Captured\n");
    // TODO: process packet data here
}