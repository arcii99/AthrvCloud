//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

void packet_handler(const struct iphdr* ip_header, size_t len)
{
    if (ip_header->protocol == IPPROTO_TCP) {
        const struct tcphdr* tcp_header = (struct tcphdr*)(ip_header + 1);
        len -= sizeof(struct iphdr);
        if (len < sizeof(struct tcphdr))
            return;

        uint16_t source_port = ntohs(tcp_header->source);
        uint16_t dest_port = ntohs(tcp_header->dest);

        printf("TCP packet: %u.%u.%u.%u:%u -> %u.%u.%u.%u:%u\n",
               (ip_header->saddr >> 24) & 0xff,
               (ip_header->saddr >> 16) & 0xff,
               (ip_header->saddr >> 8) & 0xff,
               (ip_header->saddr) & 0xff,
               source_port,
               (ip_header->daddr >> 24) & 0xff,
               (ip_header->daddr >> 16) & 0xff,
               (ip_header->daddr >> 8) & 0xff,
               (ip_header->daddr) & 0xff,
               dest_port);
    }
}

int main(int argc, char** argv)
{
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    int opt = 1;
    setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &opt, sizeof(opt));

    while (1) {
        char buffer[65536];
        ssize_t count = recv(sockfd, buffer, sizeof(buffer), 0);
        if (count == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        struct iphdr* ip_header = (struct iphdr*)buffer;
        packet_handler(ip_header, count);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}