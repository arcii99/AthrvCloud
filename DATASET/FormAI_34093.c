//FormAI DATASET v1.0 Category: Firewall ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define PACKET_SIZE 65536

int main()
{
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0)
    {
        perror("socket");
        exit(1);
    }

    char buffer[PACKET_SIZE];
    struct sockaddr_in saddr;
    int saddr_len = sizeof(saddr);

    while (1)
    {
        memset(buffer, 0, PACKET_SIZE);
        int data_size = recvfrom(sockfd, buffer, PACKET_SIZE, 0, (struct sockaddr *)&saddr, (socklen_t *)&saddr_len);
        if (data_size < 0)
        {
            perror("recvfrom");
            exit(1);
        }

        struct iphdr *iph = (struct iphdr *)buffer;
        if (iph->version == 4 && iph->ihl == 5 && iph->protocol == IPPROTO_TCP)
        {
            struct tcphdr *tcph = (struct tcphdr *)(buffer + iph->ihl * 4);
            if (tcph->dest == htons(80) || tcph->source == htons(80))
            {
                printf("Blocked packet from %s\n", inet_ntoa(saddr.sin_addr));
                continue;
            }
        }

        printf("Forwarding packet from %s\n", inet_ntoa(saddr.sin_addr));
        sendto(sockfd, buffer, data_size, 0, (struct sockaddr *)&saddr, (socklen_t)saddr_len);
    }

    close(sockfd);

    return 0;
}