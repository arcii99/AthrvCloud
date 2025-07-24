//FormAI DATASET v1.0 Category: Networking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFLEN 512 // Size of buffer

int main(int argc, char** argv) {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFLEN];
    socklen_t client_len = sizeof(client_addr);
    
    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Zero out memory
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));
    memset(buffer, 0, BUFLEN);

    // Set up server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(5555);

    // Bind socket to address and port
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", ntohs(server_addr.sin_port));

    // Continuously receive data
    while (1) {
        int recv_len;

        if ((recv_len = recvfrom(sockfd, buffer, BUFLEN, 0, (struct sockaddr *)&client_addr, &client_len)) == -1) {
            perror("recvfrom failed");
            exit(EXIT_FAILURE);
        }

        // Print received data
        printf("Received packet from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        printf("Data: %s\n", buffer);

        // Send message back to client
        if (sendto(sockfd, buffer, recv_len, 0, (struct sockaddr *)&client_addr, client_len) == -1) {
            perror("sendto failed");
            exit(EXIT_FAILURE);
        }
    }
    
    close(sockfd);
    return 0;
}