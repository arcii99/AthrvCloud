//FormAI DATASET v1.0 Category: Firewall ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip.h>

#define BUFFER_SIZE 65536

void analyze_packet(unsigned char* buffer, int size) {
    struct iphdr* iph = (struct iphdr*)buffer;
    if (iph->protocol == IPPROTO_TCP) {
        struct tcphdr* tcph = (struct tcphdr*)(buffer + sizeof(struct iphdr));
        printf("TCP packet\n");
        printf("Source IP: %s\n", inet_ntoa(*(struct in_addr*)&iph->saddr));
        printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr*)&iph->daddr));
        printf("Source Port: %d\n", ntohs(tcph->source));
        printf("Destination Port: %d\n", ntohs(tcph->dest));
        printf("-----------------------------\n");
    } else if (iph->protocol == IPPROTO_UDP) {
        struct udphdr* udph = (struct udphdr*)(buffer + sizeof(struct iphdr));
        printf("UDP packet\n");
        printf("Source IP: %s\n", inet_ntoa(*(struct in_addr*)&iph->saddr));
        printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr*)&iph->daddr));
        printf("Source Port: %d\n", ntohs(udph->source));
        printf("Destination Port: %d\n", ntohs(udph->dest));
        printf("-----------------------------\n");
    }
}

int main() {
    int socket_fd, data_size;
    struct sockaddr_in sockaddr;
    unsigned char buffer[BUFFER_SIZE];
    
    // Create socket
    socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (socket_fd < 0) {
        perror("Error creating raw socket");
        exit(1);
    }
    
    // Configure socket address
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = INADDR_ANY;
    sockaddr.sin_port = htons(0);
    if (bind(socket_fd, (struct sockaddr*)&sockaddr, sizeof(sockaddr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }
    
    // Enable IP_HDRINCL option
    int one = 1;
    const int* val = &one;
    if (setsockopt(socket_fd, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0) {
        perror("Error setting IP_HDRINCL option");
        exit(1);
    }
    
    // Receive packets and analyze them
    while (1) {
        data_size = recv(socket_fd, buffer, BUFFER_SIZE, 0);
        if (data_size > 0) {
            analyze_packet(buffer, data_size);
        }
    }
    
    close(socket_fd);
    
    return 0;
}