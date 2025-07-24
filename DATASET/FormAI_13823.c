//FormAI DATASET v1.0 Category: Simple Web Server ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];

    // Create a new socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Clear the server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    // Set the values for the server address structure
    serv_addr.sin_family = AF_INET;                 // IPv4
    serv_addr.sin_addr.s_addr = INADDR_ANY;         // Set the IP address to be any local IP address
    serv_addr.sin_port = htons(PORT);               // Set the port number

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    while (1) {

        // Accept a new connection
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            error("ERROR on accept");
        }

        // Clear the buffer
        bzero(buffer, BUFFER_SIZE);

        // Read incoming data
        int n = read(newsockfd, buffer, BUFFER_SIZE - 1);
        if (n < 0) {
            error("ERROR reading from socket");
        }

        // Print the incoming data
        printf("Here is the message: %s\n", buffer);

        // Send a response
        char* response_message = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>\r\n";
        n = write(newsockfd, response_message, strlen(response_message));
        if (n < 0) {
            error("ERROR writing to socket");
        }

        // Close the connection
        close(newsockfd);
    }

    close(sockfd);
    return 0;
}