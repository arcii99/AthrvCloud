//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define BUFFER_MAX 2048

// Function to parse ethernet header
void parse_ethernet_header(char *buffer, size_t size) {
    struct ethhdr *eth = (struct ethhdr *)buffer;
    printf("Ethernet Header:\n");
    printf("  |-Source MAC Address  : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X \n",
           eth->h_source[0], eth->h_source[1], eth->h_source[2],
           eth->h_source[3], eth->h_source[4], eth->h_source[5]);
    printf("  |-Destination MAC Address : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X \n",
           eth->h_dest[0], eth->h_dest[1], eth->h_dest[2],
           eth->h_dest[3], eth->h_dest[4], eth->h_dest[5]);
    printf("  |-Protocol : %u \n", eth->h_proto);
}

// Function to parse IP header
void parse_ip_header(char *buffer, size_t size) {
    struct iphdr *ip = (struct iphdr *)(buffer + sizeof(struct ethhdr));
    printf("IP Header:\n");
    printf("  |-Version  : %d\n", (unsigned int)ip->version);
    printf("  |-Header Length : %d Bytes\n", ((unsigned int)ip->ihl)*4);
    printf("  |-Type Of Service : %d\n", (unsigned int)ip->tos);
    printf("  |-Total Length : %d Bytes\n", ntohs(ip->tot_len));
    printf("  |-Identification : %d\n", ntohs(ip->id));
    printf("  |-Time To Live : %d\n", (unsigned int)ip->ttl);
    printf("  |-Protocol : %d\n", (unsigned int)ip->protocol);
    printf("  |-Header Checksum : %d\n", ntohs(ip->check));
    printf("  |-Source IP : %s\n", inet_ntoa(*(struct in_addr *)&ip->saddr));
    printf("  |-Destination IP : %s\n", inet_ntoa(*(struct in_addr *)&ip->daddr));
}

// Function to parse TCP header
void parse_tcp_header(char *buffer, size_t size) {
    struct tcphdr *tcp = (struct tcphdr *)(buffer + sizeof(struct ethhdr) + sizeof(struct iphdr));
    printf("TCP Header:\n");
    printf("  |-Source Port : %u\n", ntohs(tcp->source));
    printf("  |-Destination Port : %u\n", ntohs(tcp->dest));
    printf("  |-Sequence Number : %u\n", ntohl(tcp->seq));
    printf("  |-Acknowledge Number : %u\n", ntohl(tcp->ack_seq));
    printf("  |-Header Length : %d Bytes\n", (unsigned int)tcp->doff*4);
    printf("  |-Urgent Flag : %u\n", (unsigned int)tcp->urg);
    printf("  |-Acknowledgment Flag : %u\n", (unsigned int)tcp->ack);
    printf("  |-Push Flag : %u\n", (unsigned int)tcp->psh);
    printf("  |-Reset Flag : %u\n", (unsigned int)tcp->rst);
    printf("  |-Synchronise Flag : %u\n", (unsigned int)tcp->syn);
    printf("  |-Finish Flag : %u\n", (unsigned int)tcp->fin);
    printf("  |-Window : %u\n", ntohs(tcp->window));
    printf("  |-Checksum : %u\n", ntohs(tcp->check));
    printf("  |-Urgent Pointer : %u\n", tcp->urg_ptr);
}

int main(void) {
    int sockfd, len, n;
    char buffer[BUFFER_MAX];

    // Create raw socket
    sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if(sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Continuously monitor incoming packets
    while(1) {
        len = sizeof(struct sockaddr);
        n = recvfrom(sockfd, (char *)buffer, BUFFER_MAX, 0, NULL, &len);
        if(n == -1) {
            perror("recvfrom");
            return EXIT_FAILURE;
        }
        printf("\nPacket received.\n");
        parse_ethernet_header(buffer, n);
        parse_ip_header(buffer, n);
        parse_tcp_header(buffer, n);
    }
    
    return EXIT_SUCCESS;
}