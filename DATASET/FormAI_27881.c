//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: optimized
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer) {
    int size = header->len;
    struct ether_header *eth_header = (struct ether_header *) buffer;

    if (ntohs(eth_header->ether_type) == ETHERTYPE_IP) {
        struct iphdr *ip_header = (struct iphdr *) (buffer + sizeof(struct ether_header));
        if (ip_header->protocol == IPPROTO_TCP) {
            printf("\n\nPacket captured of size: %d\n", size);
            printf("------------------------------------------\n");

            printf("Ethernet header:\n");
            printf("\tDestination MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n", eth_header->ether_dhost[0], eth_header->ether_dhost[1], eth_header->ether_dhost[2], eth_header->ether_dhost[3], eth_header->ether_dhost[4], eth_header->ether_dhost[5]);
            printf("\tSource MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n", eth_header->ether_shost[0], eth_header->ether_shost[1], eth_header->ether_shost[2], eth_header->ether_shost[3], eth_header->ether_shost[4], eth_header->ether_shost[5]);
            printf("\tProtocol: %hu\n", ntohs(eth_header->ether_type));

            printf("IP header:\n");
            printf("\tSource IP address: %s\n", inet_ntoa(*(struct in_addr *) &ip_header->saddr));
            printf("\tDestination IP address: %s\n", inet_ntoa(*(struct in_addr *) &ip_header->daddr));

            struct tcphdr *tcp_header = (struct tcphdr *) (buffer + sizeof(struct ether_header) + sizeof(struct iphdr));
            printf("TCP header:\n");
            printf("\tSource port: %hu\n", ntohs(tcp_header->source));
            printf("\tDestination port: %hu\n", ntohs(tcp_header->dest));
            printf("\tSequence number: %u\n", ntohl(tcp_header->seq));
            printf("\tAcknowledge number: %u\n", ntohl(tcp_header->ack_seq));

            printf("\nPayload:\n");
            const u_char *payload = buffer + sizeof(struct ether_header) + sizeof(struct iphdr) + sizeof(struct tcphdr);
            int payload_size = size - (sizeof(struct ether_header) + sizeof(struct iphdr) + ntohs(ip_header->tot_len) - sizeof(struct tcphdr));
            for (int i = 0; i < payload_size ; i++) {
                if (i % 16 == 0) {
                    printf("\n");
                }
                printf("%02X ", payload[i]);
            }
            printf("\n");
        }
    }
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program filter;
    bpf_u_int32 netmask, network;
    char filter_exp[] = "tcp";
    int num_packets = 1;

    if (argc < 2) {
        printf("Usage: %s [pcap filename]\n", argv[0]);
        return -1;
    }

    // Open pcap file for reading
    handle = pcap_open_offline(argv[1], errbuf);

    // Compile the filter
    if (pcap_compile(handle, &filter, filter_exp, 0, network) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return -1;
    }

    // Set the filter
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return -1;
    }

    // Capture packets
    pcap_loop(handle, num_packets, process_packet, NULL);

    // Clean up
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}