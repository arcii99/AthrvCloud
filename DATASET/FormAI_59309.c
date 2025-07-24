//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* Define the callback function */
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    /* Print packet timestamp and length */
    printf("Packet timestamp: %ld.%06ld\n", header->ts.tv_sec, header->ts.tv_usec);
    printf("Packet length: %d\n\n", header->len);

    /* Process packet data */
    // TODO: add packet data processing code here
}

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    /* Open the packet capture device */
    handle = pcap_open_live("eth0", 65536, 1, 1000, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    /* Set the filter to capture TCP packets */
    struct bpf_program filter;
    char tcp_filter_exp[] = "tcp";
    if (pcap_compile(handle, &filter, tcp_filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1)
    {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        exit(EXIT_FAILURE);
    }
    if (pcap_setfilter(handle, &filter) == -1)
    {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        exit(EXIT_FAILURE);
    }

    /* Start the capture loop */
    if (pcap_loop(handle, 0, packet_handler, NULL) == -1)
    {
        fprintf(stderr, "Error during capture: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        exit(EXIT_FAILURE);
    }

    /* Cleanup */
    pcap_close(handle);
    return EXIT_SUCCESS;
}