//FormAI DATASET v1.0 Category: Chat server ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 5555
#define BUFFER_SIZE 1024

int main() {

    int sockfd, connfd, n;
    struct sockaddr_in server_addr, client_addr;
    socklen_t len;
    char buffer[BUFFER_SIZE];

    // Creating the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    // Binding the socket to a port
    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) != 0) {
        fprintf(stderr, "Failed to bind socket\n");
        exit(EXIT_FAILURE);
    }

    // Listening for connections
    if (listen(sockfd, 5) != 0) {
        fprintf(stderr, "Failed to listen for connections\n");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connections...\n");

    while (1) {
        // Accepting incoming connections
        len = sizeof(client_addr);
        connfd = accept(sockfd, (struct sockaddr*)&client_addr, &len);
        if (connfd < 0) {
            fprintf(stderr, "Failed to accept connection\n");
            continue;
        }

        printf("Client %s:%d connected\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            // Receiving data
            n = read(connfd, buffer, BUFFER_SIZE);
            if (n < 0) {
                fprintf(stderr, "Failed to read from socket\n");
                break;
            }
            if (n == 0) {
                printf("Client %s:%d disconnected\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                break;
            }

            // Processing data
            printf("Received message from client %s:%d: ", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            printf("%s", buffer);

            // Sending back data
            write(connfd, buffer, n);
        }

        close(connfd);
    }

    return 0;
}