//FormAI DATASET v1.0 Category: Network Ping Test ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>

#define PACKETSIZE 64

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 0;
    }

    // Create a raw socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Error creating raw socket");
        return 1;
    }

    // Set the IP address to ping
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    printf("Pinging %s...\n", argv[1]);

    for (int i = 1; i <= 3; i++) {
        // Create a packet
        char packet[PACKETSIZE];
        memset(packet, 0, sizeof(packet));
        struct icmphdr *icmp = (struct icmphdr*) packet;
        icmp->type = ICMP_ECHO;
        icmp->code = 0;
        icmp->un.echo.id = getpid() & 0xFFFF;
        icmp->un.echo.sequence = i;
        icmp->checksum = 0;
        icmp->checksum = htons(~(htons(icmp->checksum) + (PACKETSIZE/2)));

        // Send the packet
        int sent = sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr*) &addr, sizeof(addr));
        if (sent < 0) {
            perror("Error sending packet");
            continue;
        }

        // Receive the response
        char buffer[PACKETSIZE];
        struct sockaddr_in response_addr;
        socklen_t response_len = sizeof(response_addr);
        int received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*) &response_addr, &response_len);
        if (received < 0) {
            perror("Error receiving response");
            continue;
        }

        // Check if the response is an echo reply
        struct icmphdr *response_icmp = (struct icmphdr*) buffer;
        if (response_icmp->type == ICMP_ECHOREPLY) {
            printf("Reply from %s: bytes=%d time=%ldms\n", inet_ntoa(response_addr.sin_addr), received, i*1000);
        } else {
            printf("Received packet is not an echo reply\n");
        }

        // Wait for 1 second before sending the next packet
        sleep(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}