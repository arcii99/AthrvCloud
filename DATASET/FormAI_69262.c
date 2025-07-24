//FormAI DATASET v1.0 Category: Firewall ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define MAX_PACKET_SIZE 65535
#define TCP_PROTOCOL    6

int main() {
    int sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock_fd < 0) {
        perror("Could not create a socket");
        exit(1);
    }

    // Set options for the socket
    int one = 1;
    if (setsockopt(sock_fd, IPPROTO_IP, IP_HDRINCL, &one, sizeof(one)) < 0) {
        perror("Could not set IP_HDRINCL");
        exit(1);
    }

    // Define the firewall rules - accept packets only from 192.168.0.0/24 subnet
    struct in_addr subnet;
    if (inet_aton("192.168.0.0", &subnet) == 0) {
        perror("Could not convert subnet address");
        exit(1);
    }
    unsigned int bitmask = 0xffffff00;
    struct in_addr mask;
    mask.s_addr = htonl(bitmask);
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_addr = subnet;
    subnet.s_addr &= mask.s_addr;
    saddr.sin_addr = subnet;

    // Set up the buffer for receiving packets
    char buffer[MAX_PACKET_SIZE];
    struct sockaddr_in source;
    socklen_t source_len;

    // Loop indefinitely, receiving and dropping packets based on the firewall rules
    while (1) {
        int packet_size = recvfrom(sock_fd, buffer, MAX_PACKET_SIZE, 0,
                                   (struct sockaddr *)&source, &source_len);
        if (packet_size < 0) {
            perror("Could not receive packet");
            exit(1);
        }
        
        struct iphdr *ip_header = (struct iphdr *)buffer;
        if (ip_header->protocol == TCP_PROTOCOL && memcmp(&source.sin_addr, &saddr.sin_addr, 3) == 0) {
            struct tcphdr *tcp_header = (struct tcphdr *)(buffer + (ip_header->ihl * 4));
            if (ntohs(tcp_header->dest) == 22) {
                continue;  // drop SSH packets
            }
        }

        // Accept all other packets
        printf("Received packet from %s\n", inet_ntoa(source.sin_addr));
    }

    return 0;
}