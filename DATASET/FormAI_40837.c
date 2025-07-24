//FormAI DATASET v1.0 Category: Firewall ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

int main(int argc, char const *argv[])
{
    int sock_fd, sockfd, opt = 1;
    struct sockaddr_in host_addr, client_addr;
    socklen_t addr_len = sizeof(struct sockaddr_in);
    char buffer[1024];

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0)
    {
        perror("Socket");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &opt, sizeof(int)) < 0)
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(4444);
    host_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&host_addr, sizeof(struct sockaddr)) < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    printf("Firewall started.\n");

    while (1)
    {
        memset(buffer, 0, 1024);

        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr, &addr_len) < 0)
        {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }

        struct iphdr *ip = (struct iphdr *)buffer;
        struct tcphdr *tcp = (struct tcphdr *)(buffer + sizeof(struct iphdr));

        if (tcp->dest == htons(4444))
        {
            printf("Blocked incoming connection from %s:%d to %s:%d.\n",
                   inet_ntoa(client_addr.sin_addr), ntohs(tcp->source),
                   inet_ntoa(host_addr.sin_addr), ntohs(tcp->dest));
        }
        else
        {
            printf("Allowing incoming connection from %s:%d to %s:%d.\n",
                   inet_ntoa(client_addr.sin_addr), ntohs(tcp->source),
                   inet_ntoa(host_addr.sin_addr), ntohs(tcp->dest));

            if (sendto(sockfd, buffer, sizeof(struct iphdr) + sizeof(struct tcphdr),
                       0, (struct sockaddr *)&host_addr, sizeof(struct sockaddr)) < 0)
            {
                perror("sendto");
                exit(EXIT_FAILURE);
            }
        }
    }

    close(sockfd);
    return 0;
}