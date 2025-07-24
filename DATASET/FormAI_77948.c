//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: innovative
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured!\n");
    return;
}

int main()
{
    pcap_t *handle;
    char error_buffer[PCAP_ERRBUF_SIZE];
    struct bpf_program filter;
    char filter_exp[] = "port 80";
    bpf_u_int32 subnet_mask, ip;

    handle = pcap_open_live("en0", BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL)
    {
        printf("Couldn't open device!");
        return 1;
    }

    if (pcap_compile(handle, &filter, filter_exp, 0, ip) == -1)
    {
        printf("Couldn't compile filter!");
        return 1;
    }

    if (pcap_setfilter(handle, &filter) == -1)
    {
        printf("Couldn't set filter!");
        return 1;
    }

    if (pcap_loop(handle, -1, packet_handler, NULL) == -1)
    {
        printf("Couldn't start packet capture loop!");
        return 1;
    }

    pcap_close(handle);
    return 0;
}