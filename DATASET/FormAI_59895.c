//FormAI DATASET v1.0 Category: Network Ping Test ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PACKET_SIZE 64
#define MAX_PACKETS 5
#define TIMEOUT_SECOND 1

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./ping <IP address>\n");
        return 0;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        printf("Error in socket creation\n");
        return 0;
    }

    int seq_no = 0;
    while (seq_no < MAX_PACKETS) {
        char packet[PACKET_SIZE];
        sprintf(packet, "PING %d", seq_no);
        int packet_size = sizeof(packet);

        struct timeval tv;
        tv.tv_sec = TIMEOUT_SECOND;
        tv.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

        int no_of_bytes = sendto(sockfd, packet, packet_size, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (no_of_bytes < 0) {
            printf("Error in sending packet\n");
        }

        char reply[PACKET_SIZE];
        int addr_len = sizeof(server_addr);
        no_of_bytes = recvfrom(sockfd, reply, PACKET_SIZE, 0, (struct sockaddr *)&server_addr, &addr_len);
        if (no_of_bytes < 0) {
            printf("Packet loss\n");
        } else {
            printf("Received reply from %s with content: %s\n", inet_ntoa(server_addr.sin_addr), reply);
        }

        seq_no++;
        sleep(1);
    }

    close(sockfd);
    return 0;
}