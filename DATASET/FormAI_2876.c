//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/if_ether.h>
#include <sys/types.h>
#include <pcap.h>
#include <errno.h>

void packet_handler(u_char *ptr_packet, const struct pcap_pkthdr *pkt_header, const u_char *packet)
{
    struct ether_header *eth_header = (struct ether_header*) packet;

    // Check if the packet is an IP packet
    if (eth_header->ether_type == htons(ETHERTYPE_IP))
    {
        struct ip *ip_header = (struct ip*) (packet + sizeof(struct ether_header));

        // Check if the IP protocol is TCP
        if (ip_header->ip_p == IPPROTO_TCP)
        {
            struct tcphdr *tcp_header = (struct tcphdr*) (packet + sizeof(struct ether_header) + sizeof(struct ip));

            // Print the TCP packet information
            printf("TCP Packet: Source Port = %u, Destination Port = %u\n", ntohs(tcp_header->source), ntohs(tcp_header->dest));
        }
        // Check if the IP protocol is UDP
        else if (ip_header->ip_p == IPPROTO_UDP)
        {
            struct udphdr *udp_header = (struct udphdr*) (packet + sizeof(struct ether_header) + sizeof(struct ip));

            // Print the UDP packet information
            printf("UDP Packet: Source Port = %u, Destination Port = %u\n", ntohs(udp_header->source), ntohs(udp_header->dest));
        }
    }
}

int main(int argc, char *argv[])
{
    // Check for command line arguments
    if (argc != 2)
    {
        printf("Usage: %s [interface]\n", argv[0]);
        return 1;
    }

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);

    if (!handle)
    {
        fprintf(stderr, "pcap_open_live failed: %s\n", errbuf);
        return 1;
    }

    // Set the packet capture filter
    struct bpf_program filter;
    char filter_exp[] = "ip";
    if (pcap_compile(handle, &filter, filter_exp, 0, 0) == -1)
    {
        fprintf(stderr, "Could not compile filter expression\n");
        return 1;
    }
    if (pcap_setfilter(handle, &filter) == -1)
    {
        fprintf(stderr, "Could not set filter\n");
        return 1;
    }

    // Start the packet capture loop
    pcap_loop(handle, -1, packet_handler, NULL);

    // Clean up
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}