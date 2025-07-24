//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: retro
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

int main()
{
    int sock, n;
    unsigned char buffer[2048];
    struct sockaddr_in source, dest;
    struct ethhdr *eth_header;
    struct iphdr *ip_header;
    struct tcphdr *tcp_header; 

    sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock < 0)
    {
        printf("Error: Could not create socket\n");
        return -1;
    }
    
    while(1)
    {
        memset(buffer, 0, sizeof(buffer));
        n = recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);
        if (n < 0)
        {
            printf("Error: Packet receive failed\n");
            return -1;
        }

        eth_header = (struct ethhdr*)buffer;
        if(ntohs(eth_header->h_proto) != ETH_P_IP)
            continue;

        ip_header = (struct iphdr*)(buffer + sizeof(struct ethhdr));
        memset(&source, 0, sizeof(source));
        source.sin_addr.s_addr = ip_header->saddr;
        memset(&dest, 0, sizeof(dest));
        dest.sin_addr.s_addr = ip_header->daddr;

        if(ip_header->protocol != IPPROTO_TCP)
            continue;

        tcp_header = (struct tcphdr*)(buffer + sizeof(struct ethhdr) + sizeof(struct iphdr));
        printf("Source: %s:%d\n", inet_ntoa(source.sin_addr), ntohs(tcp_header->source));
        printf("Destination: %s:%d\n", inet_ntoa(dest.sin_addr), ntohs(tcp_header->dest));
        printf("Flags: %d\n", tcp_header->syn | tcp_header->ack | tcp_header->fin);
    }

    return 0;
}