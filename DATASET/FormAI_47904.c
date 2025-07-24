//FormAI DATASET v1.0 Category: Firewall ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

int main()
{
    /* Create a raw socket */
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);

    if (sockfd < 0) {
        printf("Could not create socket!\n");
        return -1;
    }

    /* Configure the socket to receive TCP packets */
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = INADDR_ANY;
    sa.sin_port = htons(0);

    if (bind(sockfd, (struct sockaddr *)&sa, sizeof(sa)) < 0) {
        printf("Could not bind to socket!\n");
        return -1;
    }

    /* Start capturing packets */
    printf("Starting packet capture...\n");

    while (1) {
        char buf[1024];
        struct sockaddr_in source;
        socklen_t len = sizeof(source);

        int n = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&source, &len);

        if (n < sizeof(struct iphdr) + sizeof(struct tcphdr)) {
            printf("Packet is too short!\n");
            continue;
        }

        struct iphdr *ip = (struct iphdr *)buf;

        if (ip->protocol != IPPROTO_TCP) {
            printf("Not a TCP packet!\n");
            continue;
        }

        /* Analyze the TCP packet */
        struct tcphdr *tcp = (struct tcphdr *)(buf + sizeof(struct iphdr));

        printf("TCP packet received!\n");
        printf("Source IP: %s\n", inet_ntoa(source.sin_addr));
        printf("Source port: %d\n", ntohs(tcp->source));
        printf("Destination port: %d\n", ntohs(tcp->dest));
    }

    close(sockfd);

    return 0;
}