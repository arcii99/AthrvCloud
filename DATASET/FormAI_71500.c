//FormAI DATASET v1.0 Category: Network Ping Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define PACKET_SIZE 4096
#define PING_TIMEOUT 4000

struct icmp_packet {
    struct icmphdr header;
    char message[PACKET_SIZE - sizeof(struct icmphdr)];
};

uint16_t checksum(uint16_t *data, int length) {
    uint32_t sum = 0;
    while (length > 1) {
        sum += *data++;
        length -= 2;
    }
    if (length == 1) {
        sum += *(uint8_t *) data;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return (uint16_t) ~sum;
}

void ping(struct sockaddr_in *dest_addr) {
    int sock_fd;
    struct icmp_packet packet;

    memset(&packet, 0, sizeof(packet));
    packet.header.type = ICMP_ECHO;
    packet.header.code = 0;
    packet.header.checksum = 0;
    packet.header.un.echo.id = htons(getpid());
    packet.header.un.echo.sequence = htons(0);

    for (int i = 0; i < sizeof(packet.message) - 1; ++i) {
        packet.message[i] = i + '0';
    }
    packet.message[sizeof(packet.message) - 1] = 0;
    packet.header.checksum = checksum((uint16_t *) &packet, sizeof(packet));

    if ((sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    struct timeval timeout;
    timeout.tv_sec = PING_TIMEOUT / 1000;
    timeout.tv_usec = (PING_TIMEOUT % 1000) * 1000;
    if (setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("Failed to set timeout");
        exit(1);
    }

    if (sendto(sock_fd, (const char *) &packet, sizeof(packet), 0, (const struct sockaddr *) dest_addr,
               sizeof(*dest_addr)) < 0) {
        perror("Failed to send packet");
        exit(1);
    }

    struct sockaddr_in src_addr;
    socklen_t src_addr_len = sizeof(src_addr);
    uint8_t buffer[BUFFER_SIZE];
    long start_time = time(NULL);
    while (time(NULL) - start_time < PING_TIMEOUT / 1000) {
        if (recvfrom(sock_fd, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &src_addr, &src_addr_len) > 0) {
            if (buffer[20] == 0 && buffer[21] == 0) {
                struct icmphdr *icmp_header = (struct icmphdr *) (buffer + 20);
                if (icmp_header->type == ICMP_ECHOREPLY && icmp_header->un.echo.id == htons(getpid())) {
                    printf("Received packet from %s:%d\n", 
                           inet_ntoa(src_addr.sin_addr), ntohs(src_addr.sin_port));
                    return;
                }
            }
        }
    }

    printf("Timeout\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ip-address>\n", argv[0]);
        return 0;
    }

    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(argv[1]);

    printf("Pinging %s...\n", argv[1]);
    ping(&dest_addr);

    return 0;
}