//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

int main() {
    int sock, n;
    struct sockaddr_in saddr;
    unsigned char *buffer = malloc(65536);

    sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    while(1) {
        memset(&saddr, 0, sizeof(saddr));
        n = recvfrom(sock, buffer, 65536, 0, NULL, NULL);
        if (n < 0) {
            perror("recvfrom");
            exit(1);
        }

        struct iphdr *iph = (struct iphdr*)(buffer);
        if (iph->protocol == IPPROTO_TCP) {
            struct tcphdr *tcph = (struct tcphdr*)(buffer + (iph->ihl << 2));
            printf("Source IP: %s\n", inet_ntoa((struct in_addr){iph->saddr}));
            printf("Destination IP: %s\n", inet_ntoa((struct in_addr){iph->daddr}));
            printf("Source Port: %d\n", ntohs(tcph->source));
            printf("Destination Port: %d\n", ntohs(tcph->dest));
            printf("Packet Length: %d\n", iph->tot_len);
            printf("\n");
        }
    }

    close(sock);
    return 0;
}