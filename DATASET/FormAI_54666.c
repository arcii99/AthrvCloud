//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: curious
#include <pcap.h>
#include <stdio.h>

void packet_handler(u_char* param, const struct pcap_pkthdr* header, const u_char* pkt_data)
{
    printf("Got a packet!\n");
}

int main()
{
    pcap_t* pcap_handle;    // Handle for live capture session
    char err_buff[PCAP_ERRBUF_SIZE];    // Buffer to store error messages
    struct bpf_program filter_exp;    // Compiled filter expression
    bpf_u_int32 mask;    // Subnet mask
    bpf_u_int32 net;    // IP
    struct pcap_pkthdr header;    // The header that pcap gives us
    const u_char* packet;    // The actual packet
    char filter[] = "tcp";    // Filter expression
    int num_packets = 10;    // Number of packets to capture

    // Open the session in promiscuous mode
    pcap_handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, err_buff);

    // Compile and apply the filter
    pcap_compile(pcap_handle, &filter_exp, filter, 0, net);
    pcap_setfilter(pcap_handle, &filter_exp);

    // Capture packets
    pcap_loop(pcap_handle, num_packets, packet_handler, NULL);

    // Cleanup
    pcap_freecode(&filter_exp);
    pcap_close(pcap_handle);

    return 0;
}