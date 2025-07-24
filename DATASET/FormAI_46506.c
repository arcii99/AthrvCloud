//FormAI DATASET v1.0 Category: Chat server ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000
#define BACKLOG 10
#define MAX_MSG_SIZE 1024

int start_server() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket to port");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, BACKLOG) == -1) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

int main() {
    int sockfd = start_server();
    printf("Server started on port %d\n", PORT);

    while (1) {
        printf("Waiting for client connections...\n");

        int clientfd = accept(sockfd, NULL, NULL);
        if (clientfd == -1) {
            perror("Error accepting client connection");
            continue;
        }

        printf("New client connected\n");

        while (1) {
            char buffer[MAX_MSG_SIZE] = {0};
            int bytes_received = recv(clientfd, buffer, sizeof(buffer), 0);

            if (bytes_received == -1) {
                perror("Error receiving message from client");
                break;
            }

            if (bytes_received == 0) {
                printf("Client disconnected\n");
                break;
            }

            printf("Received message: %s", buffer);

            int bytes_sent = send(clientfd, buffer, strlen(buffer), 0);
            if (bytes_sent == -1) {
                perror("Error sending message to client");
                break;
            }
        }

        close(clientfd);
    }

    close(sockfd);
    return 0;
}