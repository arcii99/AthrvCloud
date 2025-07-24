//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Claude Shannon
#include <pcap.h> // pcap header file for packet capturing!
#include <stdio.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *packet_header, const u_char *packet_data)
{
    printf("Packet Captured: %d\n", ++*(unsigned int *)param);
}

int main()
{
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int packet_count_limit = 10;
    unsigned int packet_count = 0;
    bpf_u_int32 subnet_mask, ip;
    struct bpf_program filter;

    // Open the session in promiscuous mode
    handle = pcap_open_live("enp0s3", BUFSIZ, 1, 1000, error_buffer);

    // Compile and apply the filter
    pcap_compile(handle, &filter, "ip", 0, ip);
    pcap_setfilter(handle, &filter);

    // Capture the packets
    pcap_loop(handle, packet_count_limit, packet_handler, (unsigned char *)&packet_count);

    pcap_close(handle);
    return 0;
}