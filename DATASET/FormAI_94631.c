//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* callback function for packet capture */
void packet_handler(u_char *user_args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured of length %d\n", header->len);
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];

    /* open network interface for packet capture */
    pcap_t *handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        return 1;
    }

    /* set the filter for TCP packets */
    struct bpf_program filter;
    char filter_exp[] = "tcp";
    if (pcap_compile(handle, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN) < 0) {
        fprintf(stderr, "Error compiling filter\n");
        pcap_perror(handle, "Compile");
        pcap_close(handle);
        return 1;
    }

    if (pcap_setfilter(handle, &filter) < 0) {
        fprintf(stderr, "Error setting filter\n");
        pcap_perror(handle, "Setfilter");
        pcap_close(handle);
        return 1;
    }

    /* start packet capture */
    int num_packets = 10;
    pcap_loop(handle, num_packets, packet_handler, NULL);

    /* cleanup */
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}