//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: distributed
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define MAXBYTES2CAPTURE 2048 

void process_packet(u_char *arg, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    int *counter = (int *)arg;
    printf("Packet Count: %d\n", ++(*counter));
    printf("Received Packet Size: %d\n", pkthdr->len);
    struct ether_header *eth_header = (struct ether_header *)packet;
    if (ntohs(eth_header->ether_type) == ETHERTYPE_IP) { // Check the IP packet
        struct ip *ip_packet = (struct ip *)(packet + sizeof(struct ether_header)); // Extract IP header
        if (ip_packet->ip_p == IPPROTO_TCP) { // Check the TCP protocol
            struct tcphdr *tcp_packet = (struct tcphdr *)(packet + sizeof(struct ether_header) + sizeof(struct ip)); // Extract TCP header
            printf("Source IP: %s\n", inet_ntoa(ip_packet->ip_src));
            printf("Destination IP: %s\n", inet_ntoa(ip_packet->ip_dst));
            printf("Source Port: %d\n", ntohs(tcp_packet->source));
            printf("Destination Port: %d\n", ntohs(tcp_packet->dest));
        }
    }
    printf("--------------------\n");
}

int main(int argc, char **argv) {
    int count = 0;
    pcap_t *descr = NULL; // Pointer to pcap_t structure
    char errbuf[PCAP_ERRBUF_SIZE + 1]; // Error buffer
    memset(errbuf, 0, sizeof(errbuf));

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <device>\n", argv[0]);
        return (2);
    }

    if ((descr = pcap_open_live(argv[1], MAXBYTES2CAPTURE, 1, 512, errbuf)) == NULL) {
        fprintf(stderr, "Error: pcap_open_live() failed. %s\n", errbuf);
        return (2);
    }

    if (pcap_datalink(descr) != DLT_EN10MB) { // Check the link layer
        fprintf(stderr, "Error: This program only works on Ethernet networks.\n");
        return (2);
    }

    if (pcap_loop(descr, -1, process_packet, (u_char *)&count) < 0) { // Loop forever and capture packets
        fprintf(stderr, "Error: pcap_loop() failed: %s\n", pcap_geterr(descr));
        return (2);
    }

    return (0);
}