//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: paranoid
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

void pcap_fatal(const char *failed_in, const char *errbuf) {
    printf("Fatal Error in %s: %s\n", failed_in, errbuf);
    exit(1);
}

void got_packet(u_char *args, const struct pcap_pkthdr *header,
        const u_char *packet) {
    printf("Got a packet\n");
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *pcap_handle;
    struct bpf_program filter;
    char *filter_exp = "tcp port 80";
    bpf_u_int32 subnet_mask, ip;
    int packet_count_limit = 1;
    int timeout_limit = 10000; /* In milliseconds */

    pcap_lookupnet("eth0", &ip, &subnet_mask, errbuf);

    pcap_handle = pcap_open_live("eth0", BUFSIZ, 0, timeout_limit, errbuf);

    if (pcap_handle == NULL) {
        pcap_fatal("pcap_open_live", errbuf);
    }

    if (pcap_compile(pcap_handle, &filter, filter_exp, 0, ip) == -1) {
        pcap_fatal("pcap_compile", pcap_geterr(pcap_handle));
    }

    if (pcap_setfilter(pcap_handle, &filter) == -1) {
        pcap_fatal("pcap_setfilter", pcap_geterr(pcap_handle));
    }

    pcap_loop(pcap_handle, packet_count_limit, got_packet, NULL);

    pcap_close(pcap_handle);

    return 0;
}