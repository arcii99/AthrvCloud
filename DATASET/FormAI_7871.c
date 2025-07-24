//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: romantic
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>

void packet_handler(u_char *user, const struct pcap_pkthdr *header, const u_char *packet)
{
    struct ether_header *eth_header;
    eth_header = (struct ether_header*) packet;

    if (ntohs(eth_header->ether_type) == ETHERTYPE_IP) // Check if IP packet
    {
        printf("Received a new IP packet\n");

        // Extract IP header and process it
        // ...
    }
}

int main()
{
    char error_buffer [PCAP_ERRBUF_SIZE];

    // Open network device for capturing
    pcap_t *handle = pcap_open_live("eth0", 1024, 1, 0, error_buffer);
    if (!handle)
    {
        fprintf(stderr, "Error opening device: %s\n", error_buffer);
        return EXIT_FAILURE;
    }

    // Set capture filter (optional)
    struct bpf_program filter;
    char* filter_exp = "ip src 192.168.0.1";
    bpf_u_int32 net_mask = 0;
    if (pcap_compile(handle, &filter, filter_exp, 0, net_mask) == -1)
    {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &filter) == -1)
    {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return EXIT_FAILURE;
    }
    pcap_freecode(&filter);

    // Start packet capturing loop
    int num_packets = -1;
    pcap_loop(handle, num_packets, packet_handler, NULL);

    pcap_close(handle);
    return EXIT_SUCCESS;
}