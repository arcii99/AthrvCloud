//FormAI DATASET v1.0 Category: Network Ping Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PACKET_SIZE 4096
#define DEFAULT_PORT 0x5555 // 0x5555 corresponds to decimal 21845

// Function to calculate the checksum of a packet
unsigned short calcChecksum(unsigned short *buf, int size) {
    unsigned long sum = 0;
    while (size > 1) {
        sum += *buf++;
        size -= sizeof(unsigned short);
    }
    if (size)
        sum += *(unsigned char*)buf;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

// Function to send a ping packet and wait for a response
void sendPing(int sockfd, struct sockaddr_in addr) {
    char packet[PACKET_SIZE];
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    // Fill packet with 0's
    memset(packet, 0, PACKET_SIZE);

    // Set ICMP header
    packet[0] = 8; // ICMP Echo Request
    packet[1] = 0; // Always 0
    packet[2] = 0; // Checksum
    packet[3] = 0; // Checksum
    packet[4] = 0; // Identifier (High)
    packet[5] = 0; // Identifier (Low)
    packet[6] = 0; // Sequence Number (High)
    packet[7] = 0; // Sequence Number (Low)

    // Calculate checksum and set it in packet
    unsigned short check = calcChecksum((unsigned short*)packet, sizeof(packet));
    packet[2] = check >> 8;
    packet[3] = check & 0xFF;

    // Send the packet
    sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr*)&addr, sizeof(addr));

    // Wait for response
    char buf[PACKET_SIZE];
    struct sockaddr_in raddr;
    socklen_t addrlen = sizeof(raddr);

    // Set timeout for receive
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

    // Receive packet
    int nbytes = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&raddr, &addrlen);

    // Check if response is an ICMP Echo Reply
    if (nbytes >= 8 && buf[0] == 0 && buf[1] == 0) {
        printf("PING %s: Received ICMP Echo Reply!\n", inet_ntoa(addr.sin_addr));
    }
    else {
        printf("PING %s: No ICMP Echo Reply received.\n", inet_ntoa(addr.sin_addr));
    }
}

// Main function that sends ping requests to a list of IP addresses on default port
int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set address fields
    addr.sin_family = AF_INET;
    addr.sin_port = htons(DEFAULT_PORT);

    // Send ping requests to list of IP addresses provided as arguments
    for (int i = 1; i < argc; i++) {
        // Convert IP address string to binary form and set it in address
        if (inet_pton(AF_INET, argv[i], &addr.sin_addr) <= 0) {
            perror("Invalid address");
            continue;
        }

        // Send ping request to address
        sendPing(sockfd, addr);

        // Pause before sending next request
        sleep(1);
    }

    // Close socket and exit
    close(sockfd);
    return 0;
}