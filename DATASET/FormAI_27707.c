//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *user_args, const struct pcap_pkthdr *pkt_info, const u_char *pkt_data) {
    printf("Packet Captured of length %d\n", pkt_info->len);
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = NULL;
    struct bpf_program filter;

    char filter_exp[] = "tcp port 80";

    bpf_u_int32 net;
    bpf_u_int32 mask;

    if(pcap_lookupnet("eth0", &net, &mask, errbuf) == -1) {
        printf("Error finding the network. %s\n", errbuf);
        return 1;
    }

    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

    if(handle == NULL) {
        printf("Error opening handle. %s\n", errbuf);
        return 1;
    }

    if(pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
        printf("Error compiling filter. %s\n", pcap_geterr(handle));
        return 1;
    }

    if(pcap_setfilter(handle, &filter) == -1) {
        printf("Error setting filter. %s\n", pcap_geterr(handle));
        return 1;
    }

    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_close(handle);

    return 0;
}