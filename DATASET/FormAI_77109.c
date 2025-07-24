//FormAI DATASET v1.0 Category: Firewall ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>

#define PACKET_SIZE 65536

int main(void)
{
    int s, packet_len;
    char packet_buffer[PACKET_SIZE];

    s = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (s < 0)
    {
        printf("Error creating socket.\n");
        exit(1);
    }

    while (1)
    {
        packet_len = recvfrom(s , packet_buffer , PACKET_SIZE , 0 , NULL, NULL);
        if (packet_len < 0)
        {
            printf("Error receiving packets.\n");
            exit(1);
        }

        struct iphdr *ip_header = (struct iphdr*) packet_buffer;
        if (ip_header->protocol != IPPROTO_TCP)
            continue;

        struct tcphdr *tcp_header = (struct tcphdr*) (packet_buffer + ip_header->ihl*4);
        if (ntohs(tcp_header->dest) != 80)
            continue;

        printf("Received a packet matching the firewall's criteria.\n");
        // Add your own firewall rules here.

    }

    close(s);
    return 0;
}