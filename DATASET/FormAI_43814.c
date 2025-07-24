//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    printf("Packet received!\n");
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *adhandle;

    // Open the packet capture device
    if ((adhandle = pcap_open_live("eth0", 65536, 1, 1000, errbuf)) == NULL) {
        fprintf(stderr, "Unable to open the adapter: %s\n", errbuf);
        return 1;
    }

    // Compile and apply the filter
    struct bpf_program filter;
    char filter_exp[] = "port 80";
    if (pcap_compile(adhandle, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Unable to compile the packet filter\n");
        return 1;
    }
    if (pcap_setfilter(adhandle, &filter) == -1) {
        fprintf(stderr, "Unable to apply the packet filter\n");
        return 1;
    }

    // Start packet capture loop
    pcap_loop(adhandle, 0, packet_handler, NULL);

    return 0;
}