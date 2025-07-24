//FormAI DATASET v1.0 Category: Firewall ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 1024

int main(int argc, char* argv[]) {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding UDP socket");
        return 1;
    }

    while (true) {
        char buffer[MAX_PACKET_SIZE];
        memset(buffer, 0, MAX_PACKET_SIZE);

        client_len = sizeof(client_addr);
        int bytes_received = recvfrom(sockfd, buffer, MAX_PACKET_SIZE, 0,
                                      (struct sockaddr*)&client_addr, &client_len);
        if (bytes_received < 0) {
            perror("Error receiving packet");
        } else {
            printf("Received %d bytes from %s:%d\n", bytes_received,
                   inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            // insert firewall rules here
            // e.g. if (client_addr.sin_addr.s_addr != allowed_ip) { // block packet }
        }
    }

    return 0;
}