//FormAI DATASET v1.0 Category: Firewall ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <time.h>

#define BUFFER_SIZE 4096
#define PORT 8888

void block_address(char *address);

int main() {
    int sockfd;
    struct sockaddr_in addr;
    char buffer[BUFFER_SIZE] = {0};

    // Create a socket file descriptor
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd == -1) {
        perror("Socket creation failed.");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    const int yes = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &yes, sizeof(yes)) < 0) {
        perror("Error setting socket options.");
        exit(EXIT_FAILURE);
    }

    // Bind socket to a local address
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Failed to bind socket to local address.");
        exit(EXIT_FAILURE);
    }

    printf("Firewall started listening on port %d...\n", PORT);

    while (1) {
        struct sockaddr_in sender_addr;
        int sender_addr_len = sizeof(sender_addr);

        // Receive packet
        ssize_t packet_len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&sender_addr, (socklen_t *)&sender_addr_len);
        if (packet_len == -1) {
            perror("Failed to receive packet.");
            continue;
        }

        // Extract TCP header
        struct iphdr *iph = (struct iphdr *)buffer;
        struct tcphdr *tcph = (struct tcphdr *)(buffer + sizeof(struct iphdr));

        // Convert addresses to strings
        char sender_ip[INET_ADDRSTRLEN], dest_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &sender_addr.sin_addr, sender_ip, sizeof(sender_ip));
        inet_ntop(AF_INET, &iph->daddr, dest_ip, sizeof(dest_ip));

        // Check if packet is a TCP SYN packet
        if (tcph->syn == 1 && tcph->ack == 0) {
            printf("Received TCP SYN packet from %s to %s:%d\n", sender_ip, dest_ip, ntohs(tcph->dest));

            // Block sender IP address
            printf("Blocking address: %s\n", sender_ip);
            block_address(sender_ip);
        }
    }

    close(sockfd);
    return 0;
}

void block_address(char *address) {
    // Add iptables rule to block IP address
    char command[50];
    sprintf(command, "sudo iptables -A INPUT -s %s -j DROP", address);
    system(command);
    printf("Added iptables rule to block address: %s\n", address);
}