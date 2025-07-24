//FormAI DATASET v1.0 Category: Firewall ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    struct sockaddr_in source_address;
    struct sockaddr_in destination_address;
    char buffer[65536];

    int data_size;
    while (1) {
        data_size = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
        if (data_size < 0) {
            perror("ERROR on recvfrom");
            exit(1);
        }

        struct iphdr *ipheader = (struct iphdr*) buffer;
        if (ipheader->protocol == IPPROTO_TCP) {
            struct tcphdr *tcpheader = (struct tcphdr*) (buffer + sizeof(struct iphdr));
            if (tcpheader->dest == htons(80)) {
                printf("HTTP traffic from %s to %s dropped\n",
                       inet_ntoa(source_address.sin_addr),
                       inet_ntoa(destination_address.sin_addr));
                continue;
            }
        }

        source_address.sin_addr.s_addr = ipheader->saddr;
        destination_address.sin_addr.s_addr = ipheader->daddr;

        printf("Packet from %s to %s allowed\n",
               inet_ntoa(source_address.sin_addr),
               inet_ntoa(destination_address.sin_addr));
    }

    close(sockfd);
    return 0;
}