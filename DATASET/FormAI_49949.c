//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

void packet_handler(unsigned char *buffer, int size)
{
    struct ethhdr *eth = (struct ethhdr*)buffer;
    struct iphdr *ip = (struct iphdr*)(buffer + sizeof(struct ethhdr));
    int source_port, dest_port;

    if (eth->h_proto == htons(ETH_P_IP))
    {
        if (ip->protocol == IPPROTO_TCP)
        {
            struct tcphdr *tcp = (struct tcphdr*)(buffer + sizeof(struct ethhdr) + sizeof(struct iphdr));

            source_port = ntohs(tcp->source);
            dest_port = ntohs(tcp->dest);

            printf("TCP packet received from: %s:%d to %s:%d\n", inet_ntoa(*(struct in_addr*)&ip->saddr), source_port, inet_ntoa(*(struct in_addr*)&ip->daddr),dest_port);
        }
        else if (ip->protocol == IPPROTO_UDP)
        {
            struct udphdr *udp = (struct udphdr*)(buffer + sizeof(struct ethhdr) + sizeof(struct iphdr));

            source_port = ntohs(udp->source);
            dest_port = ntohs(udp->dest);

            printf("UDP packet received from: %s:%d to %s:%d\n", inet_ntoa(*(struct in_addr*)&ip->saddr), source_port, inet_ntoa(*(struct in_addr*)&ip->daddr),dest_port);
        }
    }
}

int main()
{
    int sock_raw;
    struct sockaddr_in saddr;
    unsigned char *buffer = (unsigned char *)malloc(65536);
    
    if (buffer == NULL)
    {
        printf("Memory allocation error\n");
        return 1;
    }

    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    
    if (sock_raw < 0)
    {
        printf("Socket creation error\n");
        return 1;
    }

    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(0);
    saddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock_raw, (struct sockaddr *)&saddr, sizeof(saddr)) < 0)
    {
        printf("Bind error\n");
        close(sock_raw);
        return 1;
    }

    printf("Packet monitoring started...\n");

    while(1)
    {
        int recv_size = recvfrom(sock_raw, buffer, 65536, 0, NULL, NULL);
        packet_handler(buffer, recv_size);
    }

    close(sock_raw);
    free(buffer);

    return 0;
}