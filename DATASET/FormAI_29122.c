//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    printf("Got a packet\n");
}

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *pcap_handle;
    struct bpf_program filter;

    // Open the network interface for packet capture
    pcap_handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (pcap_handle == NULL) {
        printf("pcap_open_live() failed: %s\n", errbuf);
        exit(1);
    }

    // Compile and apply the packet filter
    if (pcap_compile(pcap_handle, &filter, "tcp port 80", 0, PCAP_NETMASK_UNKNOWN) == -1) {
        printf("pcap_compile() failed\n");
        exit(1);
    }
    if (pcap_setfilter(pcap_handle, &filter) == -1) {
        printf("pcap_setfilter() failed\n");
        exit(1);
    }

    // Start capturing packets
    if (pcap_loop(pcap_handle, 0, packet_handler, NULL) == -1) {
        printf("pcap_loop() failed\n");
        exit(1);
    }

    // Cleanup
    pcap_freecode(&filter);
    pcap_close(pcap_handle);

    return 0;
}