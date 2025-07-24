//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

#define ETH_HEADER_SIZE 14

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer);

int main(int argc, char **argv) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 net, mask;

    // Get default network interface
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        printf("ERROR: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }
    printf("Sniffing on device: %s\n", dev);

    // Get network interface information (sub-net mask, etc)
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        printf("ERROR: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Open network interface
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("ERROR: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Compile filter expression
    if (pcap_compile(handle, &fp, "tcp", 0, net) == -1) {
        printf("ERROR: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Apply compiled filter expression to network interface
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("ERROR: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Capture and process packets indefinitely
    printf("Starting packet capture...\n");
    pcap_loop(handle, -1, process_packet, NULL);

    // Close network interface
    pcap_close(handle);

    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer) {
    struct ethhdr *eth_header;
    struct iphdr *ip_header;
    struct tcphdr *tcp_header;
    struct udphdr *udp_header;

    int size_ip, size_tcp, size_udp;

    // Fetch ethernet header
    eth_header = (struct ethhdr *) buffer;

    // Fetch IP header
    ip_header = (struct iphdr *)(buffer + ETH_HEADER_SIZE);
    size_ip = ip_header->ihl * 4;

    // If packet is malformed, exit function
    if (size_ip < 20) {
        printf("Malformed packet: IP header too short.\n");
        return;
    }

    // Fetch TCP header
    if (ip_header->protocol == IPPROTO_TCP) {
        tcp_header = (struct tcphdr *)(buffer + ETH_HEADER_SIZE + size_ip);
        size_tcp = tcp_header->doff * 4;

        // If packet is malformed, exit function
        if (size_tcp < 20) {
            printf("Malformed packet: TCP header too short.\n");
            return;
        }

        // Print packet information
        printf("TCP packet: %s:%d -> ", inet_ntoa(*(struct in_addr *)&ip_header->saddr), ntohs(tcp_header->source));
        printf("%s:%d\n", inet_ntoa(*(struct in_addr *)&ip_header->daddr), ntohs(tcp_header->dest));
    }

    // Fetch UDP header
    else if (ip_header->protocol == IPPROTO_UDP) {
        udp_header = (struct udphdr *)(buffer + ETH_HEADER_SIZE + size_ip);
        size_udp = sizeof(struct udphdr);

        // If packet is malformed, exit function
        if (size_udp < 8) {
            printf("Malformed packet: UDP header too short.\n");
            return;
        }

        // Print packet information
        printf("UDP packet: %s:%d -> ", inet_ntoa(*(struct in_addr *)&ip_header->saddr), ntohs(udp_header->source));
        printf("%s:%d\n", inet_ntoa(*(struct in_addr *)&ip_header->daddr), ntohs(udp_header->dest));
    }
}