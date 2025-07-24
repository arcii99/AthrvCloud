//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Dennis Ritchie
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[])
{
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program filter;
    char filter_exp[] = "icmp";
    bpf_u_int32 net;
    struct pcap_pkthdr header;
    const u_char *packet;

    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Couldn't open device: %s\n", errbuf);
        return 1;
    }

    if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
        printf("Couldn't compile filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Couldn't set filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            continue;
        }

        printf("Packet length: %d\n", header.len);
    }

    return 0;
}