//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_MSG_SIZE 1024

int main(int argc, char const *argv[]) {
    int sockfd, newsockfd, client_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_MSG_SIZE] = {0};
    char *welcome_msg = "Welcome to the server!\n";

    // Create a socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept incoming connection and create new socket file descriptor
    client_len = sizeof(client_addr);
    if ((newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&client_len)) == -1) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Send welcome message to client
    send(newsockfd, welcome_msg, strlen(welcome_msg), 0);

    // Receive message from client
    read(newsockfd, buffer, MAX_MSG_SIZE);
    printf("Client: %s\n", buffer);

    // Send response to client
    char *response_msg = "Thanks for sending the message!";
    send(newsockfd, response_msg, strlen(response_msg), 0);

    close(newsockfd);
    close(sockfd);

    return 0;
}