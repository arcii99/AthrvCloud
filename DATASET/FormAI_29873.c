//FormAI DATASET v1.0 Category: Socket programming ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 5050
#define BUFFER_SIZE 1024

void handle_client_connection(int sockfd) {
    char buffer[BUFFER_SIZE];
    int recv_data_length = 0;

    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        recv_data_length = recv(sockfd, buffer, BUFFER_SIZE-1, 0);

        if (recv_data_length <= 0)
            break;

        printf("Received: %s", buffer);
        send(sockfd, buffer, recv_data_length, 0);
    }
    
    close(sockfd);
    printf("Connection closed.\n");
}

int main() {
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sockfd, 10) < 0) {
        perror("Failed to listen on socket");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port: %d\n", PORT);

    while(1) {
        client_addr_len = sizeof(client_addr);
        client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_addr, &client_addr_len);

        if (client_sockfd < 0) {
            perror("Failed to accept connection");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        handle_client_connection(client_sockfd);
    }

    close(server_sockfd);
    
    return 0;
}