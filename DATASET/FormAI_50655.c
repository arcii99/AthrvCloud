//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define BUFFER_SIZE 65535

void ProcessPacket(unsigned char *, int);

int sock, n;
unsigned char buffer[BUFFER_SIZE]; 

int main()
{
    sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if(sock < 0) {
        perror("socket");
        return 1;
    }

    while(1) {
        int len = sizeof(struct sockaddr);
        n = recvfrom(sock, buffer, BUFFER_SIZE, 0, NULL, (socklen_t *)&len);
        if(n < 0) {
            perror("recvfrom");
            return 1;
        }
        ProcessPacket(buffer, n);
    }

    return 0;
}

void ProcessPacket(unsigned char *buffer, int size) {
    struct ethhdr *eth = (struct ethhdr *)(buffer);
    if(ntohs(eth->h_proto) != ETH_P_IP) {
        printf("Not an IP packet\n");
        return;
    }
    struct iphdr *ip = (struct iphdr *)(buffer + sizeof(struct ethhdr));
    if(ip->protocol == IPPROTO_TCP) {
        unsigned int tcp_offset = sizeof(struct ethhdr) + sizeof(struct iphdr);
        struct tcphdr *tcp = (struct tcphdr *)(buffer + tcp_offset);
        printf("Source IP: %s:%d | Dest IP: %s:%d | Flags: %08X\n", inet_ntoa((struct in_addr){.s_addr = ip->saddr}),
            ntohs(tcp->source), inet_ntoa((struct in_addr){.s_addr = ip->daddr}), ntohs(tcp->dest), ntohl(tcp->ack_seq) & 0x17);
    }
    else if(ip->protocol == IPPROTO_UDP)
        printf("UDP packet\n");
    else if(ip->protocol == IPPROTO_ICMP)
        printf("ICMP packet\n");
}