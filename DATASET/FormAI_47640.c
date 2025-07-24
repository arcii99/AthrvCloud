//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>

#define BUFFER_SIZE 65535

void print_packet(unsigned char* buffer)
{
    struct iphdr *ip_header = (struct iphdr*)buffer;
    if(ip_header->protocol == IPPROTO_TCP) {
        unsigned short ip_head_len = ip_header->ihl*4;
        struct tcphdr *tcp_header = (struct tcphdr*)(buffer + ip_head_len);
        printf("Source IP: %u.%u.%u.%u\n", (unsigned char)(ip_header->saddr), (unsigned char)(ip_header->saddr >> 8), (unsigned char)(ip_header->saddr >> 16), (unsigned char)(ip_header->saddr >> 24));
        printf("Destination IP: %u.%u.%u.%u\n", (unsigned char)(ip_header->daddr), (unsigned char)(ip_header->daddr >> 8), (unsigned char)(ip_header->daddr >> 16), (unsigned char)(ip_header->daddr >> 24));
        printf("Source Port: %d\n", ntohs(tcp_header->source));
        printf("Destination Port: %d\n", ntohs(tcp_header->dest));
        printf("----------------------------------------------\n");
    }
}

int main()
{
    int fd, n = 0;
    unsigned char buffer[BUFFER_SIZE];

    // create a raw socket that listens on all network interfaces
    fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (fd < 0) {
        perror("Error creating raw socket");
        return errno;
    }

    while (1) {
        n = recv(fd, buffer, BUFFER_SIZE, 0);
        if (n == -1) {
            perror("Error receiving packet");
            continue;
        }
        print_packet(buffer);
    }

    close(fd);
    return 0;
}