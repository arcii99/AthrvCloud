//FormAI DATASET v1.0 Category: Firewall ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void handle_packet(unsigned char *buffer, int size);
void handle_tcp(unsigned char *buffer, int size);

int main()
{
    int sockfd, newsockfd, c;
    struct sockaddr_in server_address, client_address;
    unsigned char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8888);
    server_address.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("bind");
        exit(1);
    }

    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &(int){1}, sizeof(int)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    printf("Firewall started listening on port 8888...\n");

    while (1) {
        c = sizeof(struct sockaddr_in);
        if (recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &client_address, (socklen_t *) &c) < 0) {
            perror("recvfrom");
            exit(1);
        }
        handle_packet(buffer, c);
    }

    close(sockfd);

    return 0;
}

void handle_packet(unsigned char *buffer, int size)
{
    struct iphdr *ip_header = (struct iphdr *) buffer;

    if (ip_header->protocol == IPPROTO_TCP) {
        handle_tcp(buffer, size);
    }
}

void handle_tcp(unsigned char *buffer, int size)
{
    struct iphdr *ip_header = (struct iphdr *) buffer;
    struct tcphdr *tcp_header = (struct tcphdr *) (buffer + ip_header->ihl * 4);

    if (ntohs(tcp_header->dest) == 80) {
        // Block traffic to port 80 (HTTP)
        printf("Blocked HTTP traffic from %s\n", inet_ntoa(*(struct in_addr *)&ip_header->saddr));
        return;
    }

    printf("Accepted TCP packet from %s:%d to %s:%d\n", inet_ntoa(*(struct in_addr *)&ip_header->saddr),
           ntohs(tcp_header->source), inet_ntoa(*(struct in_addr *)&ip_header->daddr), ntohs(tcp_header->dest));
}