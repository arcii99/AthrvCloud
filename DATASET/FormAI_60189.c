//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Claude Shannon
#include <pcap.h>
#include <stdio.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main()
{
    pcap_t *handle;
    char error_buffer[PCAP_ERRBUF_SIZE];
    struct bpf_program filter;
    char filter_exp[] = "port 80";
    bpf_u_int32 subnet_mask, ip;

    // Open the network interface for capture.
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, error_buffer);

    // Compile and apply the filter expression.
    pcap_compile(handle, &filter, filter_exp, 0, ip);
    pcap_setfilter(handle, &filter);

    // Capture packets continuously.
    pcap_loop(handle, 0, packet_handler, NULL);

    // Closing the handle and freeing allocated resources.
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured length: %d\n", header->len);
    // Do what you want with the packet data.
}