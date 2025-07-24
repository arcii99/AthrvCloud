//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in myaddr;
    socklen_t addrlen = sizeof(myaddr);
    char buffer[BUFSIZE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind to port 8888
    myaddr.sin_family = AF_INET;
    myaddr.sin_addr.s_addr = INADDR_ANY;
    myaddr.sin_port = htons(8888);

    if (bind(sockfd, (struct sockaddr *) &myaddr, sizeof(myaddr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Receive packet
        if (recvfrom(sockfd, buffer, BUFSIZE, 0, (struct sockaddr *) &myaddr, &addrlen) == -1) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }

        // Parse packet
        unsigned short src_port = ntohs(myaddr.sin_port);
        unsigned short dst_port = ntohs(*(unsigned short *)&buffer[2]);
        unsigned int src_ip = ntohl(myaddr.sin_addr.s_addr);
        unsigned int dst_ip = ntohl(*(unsigned int *)&buffer[12]);
        unsigned int protocol = *(unsigned char *)&buffer[9];

        // Print packet details
        printf("Source IP: %u.%u.%u.%u, ", (src_ip >> 24) & 0xFF, (src_ip >> 16) & 0xFF, (src_ip >> 8) & 0xFF, src_ip & 0xFF);
        printf("Destination IP: %u.%u.%u.%u, ", (dst_ip >> 24) & 0xFF, (dst_ip >> 16) & 0xFF, (dst_ip >> 8) & 0xFF, dst_ip & 0xFF);
        printf("Protocol: %u, ", protocol);
        printf("Source Port: %u, ", src_port);
        printf("Destination Port: %u\n", dst_port);
    }

    return 0;
}