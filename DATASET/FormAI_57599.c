//FormAI DATASET v1.0 Category: Networking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 9000
#define MAX_MSG_LEN 1024

int main(int argc, char *argv[]) {
    int sockfd, connfd;
    char buffer[MAX_MSG_LEN];
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket creation failed");
        return EXIT_FAILURE;
    }

    // Initialize server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind socket to server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        perror("socket bind failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Listen for connections
    if (listen(sockfd, 5) != 0) {
        perror("socket listen failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept connection
        len = sizeof(cliaddr);
        connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
        if (connfd < 0) {
            perror("socket accept failed");
            close(sockfd);
            return EXIT_FAILURE;
        }

        printf("Client %s:%d connected\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        // Receive message from client
        memset(buffer, 0, MAX_MSG_LEN);
        if (recv(connfd, buffer, sizeof(buffer), 0) < 0) {
            perror("socket receive failed");
            close(connfd);
            continue;
        }

        printf("Received message from %s:%d: %s\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port), buffer);

        // Send response to client
        memset(buffer, 0, MAX_MSG_LEN);
        strcpy(buffer, "Hello from server");
        if (send(connfd, buffer, strlen(buffer), 0) < 0) {
            perror("socket send failed");
            close(connfd);
            continue;
        }

        printf("Response sent to %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        // Close connection
        close(connfd);
        printf("Client %s:%d disconnected\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
    }

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}