//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Alan Touring
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured, packet length: %d\n", header->len);
}

int main()
{
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int packet_count_limit = 1; // capture only 1 packet
    int timeout_limit = 10000; // in milliseconds
    bpf_u_int32 net_mask;
    bpf_u_int32 net_ip;
    struct bpf_program filter;
    char filter_exp[] = "tcp port 80"; // capture only TCP packets with destination port 80

    if (pcap_lookupnet("eth0", &net_ip, &net_mask, error_buffer) == -1) {
        printf("Error looking up network: %s\n", error_buffer);
        return 1;
    }

    handle = pcap_open_live("eth0", BUFSIZ, 1, timeout_limit, error_buffer);
    if (handle == NULL) {
        printf("Error opening device: %s\n", error_buffer);
        return 1;
    }

    if (pcap_compile(handle, &filter, filter_exp, 0, net_ip) == -1) {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    pcap_loop(handle, packet_count_limit, packet_handler, NULL);

    pcap_close(handle);
    return 0;
}