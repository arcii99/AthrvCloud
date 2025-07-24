//FormAI DATASET v1.0 Category: Firewall ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define ETH_ALEN 6
#define ETH_HLEN 14

struct eth_hdr {
    u_char h_dest[ETH_ALEN];
    u_char h_source[ETH_ALEN];
    u_short h_proto;
};

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct eth_hdr *ethernet_header = (struct eth_hdr*) packet;
    // Check if the packet is an IPv4 packet
    if (ntohs(ethernet_header->h_proto) == 0x0800) {
        struct iphdr *ip_header = (struct iphdr*) (packet + ETH_HLEN);
        // Check if the packet is a TCP packet
        if (ip_header->protocol == IPPROTO_TCP) {
            struct tcphdr *tcp_header =  (struct tcphdr*) (packet + ETH_HLEN + sizeof(*ip_header));
            // Check if the source or destination port is 80 (HTTP)
            if (ntohs(tcp_header->source) == 80 || ntohs(tcp_header->dest) == 80) {
                printf("HTTP packet detected: source IP: %s\n", inet_ntoa(*(struct in_addr*)&ip_header->saddr));
                // Block the packet with a TCP RST
                u_char *spoofed_packet = (u_char*) malloc(header->len);
                memcpy(spoofed_packet, packet, header->len);
                struct tcphdr *spoofed_tcp_header = (struct tcphdr*) (spoofed_packet + ETH_HLEN + sizeof(*ip_header));
                spoofed_tcp_header->rst = 1;
                pcap_inject((pcap_t*)args, spoofed_packet, header->len);
                printf("Packet blocked.\n");
                free(spoofed_packet);
            }
        }
    }
}

int main(int argc, char **argv) {
    char *dev = pcap_lookupdev(NULL);
    if (dev == NULL) {
        fprintf(stderr, "Error: pcap_lookupdev failed: %s\n", pcap_geterr(NULL));
        exit(1);
    }
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *pcap_handle = pcap_open_live(dev, BUFSIZ, 0, -1, errbuf);
    if (pcap_handle == NULL) {
        fprintf(stderr, "Error: pcap_open_live failed: %s\n", errbuf);
        exit(1);
    }
    // Filter for HTTP traffic
    struct bpf_program filter;
    char *filter_exp = "tcp port 80";
    if (pcap_compile(pcap_handle, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Error: pcap_compile failed: %s\n", pcap_geterr(pcap_handle));
        exit(1);
    }
    if (pcap_setfilter(pcap_handle, &filter) == -1) {
        fprintf(stderr, "Error: pcap_setfilter failed: %s\n", pcap_geterr(pcap_handle));
        exit(1);
    }
    pcap_loop(pcap_handle, -1, process_packet, (u_char*)pcap_handle);
    return 0;
}