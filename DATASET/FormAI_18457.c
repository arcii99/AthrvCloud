//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_PORT 8080
#define MAXLINE 1024

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAXLINE];
    char reply[MAXLINE];
    int len, n;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Initialize server information
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(SERVER_PORT);

    // Bind the socket to the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(sockfd, 5) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept a connection
        len = sizeof(cliaddr);
        if ((newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len)) < 0) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        // Read the request from the client
        memset(buffer, 0, sizeof(buffer));
        n = read(newsockfd, buffer, MAXLINE);
        printf("Received Request from Client: %s\n", buffer);

        // Create reply
        sprintf(reply, "HTTP/1.1 200 OK\r\nContent-Length: 19\r\n\r\nHello from Server\n");

        // Send reply to the client
        write(newsockfd, reply, strlen(reply));

        // Close the connection
        close(newsockfd);
    }

    return 0;
}