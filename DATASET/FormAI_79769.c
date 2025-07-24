//FormAI DATASET v1.0 Category: Simple Web Server ; Style: systematic
// C Simple Web Server Example Program
// by [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = PORT;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the host address using bind() call
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding address");
        exit(1);
    }

    // Start listening for the clients
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // Accept the connection from clients and serve them
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error on accepting");
            exit(1);
        }

        // Read the message from the client into buffer
        bzero(buffer, 1024);
        n = read(newsockfd, buffer, 1024);
        if (n < 0) {
            perror("Error reading from socket");
            exit(1);
        }

        // Print the message received from client
        printf("Here is the message from client: %s\n",buffer);

        // Send response to the client
        char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>";
        n = write(newsockfd, response, strlen(response));
        if (n < 0) {
            perror("Error writing to socket");
            exit(1);
        }

        // Close the socket after response has been sent
        close(newsockfd);
    }

    close(sockfd);
    return 0;
}