//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 4096

void send_packet(int sockfd, const struct sockaddr_in *target, const char *data, size_t len) {
    sendto(sockfd, data, len, 0, (const struct sockaddr *) target, sizeof(struct sockaddr));
}

int main(int argc, const char *argv[]) {
    char buffer[MAX_PACKET_SIZE];
    unsigned int packet_length;

    if (argc != 2) {
        printf("usage: %s <target_ip>\n", argv[0]);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd < 0) {
        perror("failed to create socket");
        exit(1);
    }

    struct sockaddr_in target = { 0 };
    target.sin_family = AF_INET;
    target.sin_port = htons(80);

    if (inet_aton(argv[1], &target.sin_addr) == 0) {
        perror("invalid target address");
        exit(1);
    }

    send_packet(sockfd, &target, "HELLO_WORLD", 11);

    while (1) {
        packet_length = recvfrom(sockfd, buffer, MAX_PACKET_SIZE, 0, NULL, NULL);
        if (packet_length == -1) {
            perror("failed to receive packet");
            continue;
        }

        printf("Received packet with length: %u\n", packet_length);

        for (unsigned int i = 0; i < packet_length; i++) {
            printf("%02x ", buffer[i] & 0xff);
        }
        printf("\n");

        sleep(1);
    }

    return 0;
}