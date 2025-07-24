//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: lively
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *pkt_header, const u_char *pkt_data) {
    printf("Packet captured with length of %d\n", pkt_header->len);
    
    // Analyze packet data
    // ...

    printf("\n");
}

int main() {
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *pcap_handle = pcap_open_live("eth0", 65535, 1, 1000, error_buffer);

    if (pcap_handle == NULL) {
        printf("Error opening device: %s\n", error_buffer);
        return 1;
    }

    printf("Listening on device: eth0\n");

    // Set filter for only capturing TCP traffic
    struct bpf_program filter;
    pcap_compile(pcap_handle, &filter, "tcp", 1, PCAP_NETMASK_UNKNOWN);
    pcap_setfilter(pcap_handle, &filter);

    // Capture packets
    pcap_loop(pcap_handle, -1, packet_handler, NULL);

    pcap_close(pcap_handle);
    return 0;
}