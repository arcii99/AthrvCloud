//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: lively
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main() {
    pcap_t *pcap_handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    // open a network interface in promiscuous mode
    pcap_handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (pcap_handle == NULL) {
        fprintf(stderr, "Error opening interface: %s\n", errbuf);
        return 1;
    }

    // set a filter to only capture ICMP packets
    struct bpf_program filter;
    char* filter_exp = "icmp";
    if (pcap_compile(pcap_handle, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(pcap_handle));
        return 1;
    }
    if (pcap_setfilter(pcap_handle, &filter) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(pcap_handle));
        return 1;
    }

    // enter into a packet capture loop
    printf("Capturing packets...\n");
    pcap_loop(pcap_handle, -1, packet_handler, NULL);

    // close the capture handle
    pcap_close(pcap_handle);

    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    printf("Packet captured!\n");
    printf("Timestamp: %ld.%06ld\n", header->ts.tv_sec, header->ts.tv_usec);
    printf("Length: %u\n", header->len);
    // more packet analysis here...
}