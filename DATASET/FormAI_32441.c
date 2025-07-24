//FormAI DATASET v1.0 Category: Client Server Application ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {

    int sockfd, newsockfd;
    socklen_t cliLen;
    struct sockaddr_in servAddr, cliAddr;
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR: failed to create socket");
        exit(1);
    }

    // Initializing server details
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY;
    servAddr.sin_port = htons(PORT);

    // Associating socket with server address and port
    if (bind(sockfd, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0) {
        perror("ERROR: failed to bind socket");
        exit(1);
    }

    // Setting socket to listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("ERROR: failed to listen on socket");
        exit(1);
    }

    // Loop to accept and handle multiple client requests
    while (1) {
        cliLen = sizeof(cliAddr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cliAddr, &cliLen);
        if (newsockfd < 0) {
            perror("ERROR: failed to accept incoming connection");
            exit(1);
        }

        // Receiving message from client
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(newsockfd, buffer, BUFFER_SIZE, 0) < 0) {
            perror("ERROR: failed to receive message from client");
            exit(1);
        }

        printf("Client says: %s\n", buffer);

        // Sending message to client
        char *message = "Hello from server!";
        if (send(newsockfd, message, strlen(message), 0) < 0) {
            perror("ERROR: failed to send message to client");
            exit(1);
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}