//FormAI DATASET v1.0 Category: Simple Web Server ; Style: immersive
// You have arrived at the C Simple Web Server program.
// Congratulations! Prepare to dive into the world of servers and sockets.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 1024
#define SERVER_PORT 8080

int main() {
    int sockfd, newsockfd, clilen;
    char buffer[BUFSIZE], response[BUFSIZE];
    struct sockaddr_in serv_addr, cli_addr;

    // Intializing the server socket 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Oh no! Unable to open socket.\n");
        return -1;
    }
    printf("The socket has been opened. Ready to serve.\n");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(SERVER_PORT);

    // Binding the socket to the IP address and port specified 
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Uh-oh! Couldn't bind the socket.\n");
        return -1;
    }
    printf("The socket has been bound.\n");

    // Listening for requests from clients 
    listen(sockfd, 5);
    printf("Listening on port %d...\n", SERVER_PORT);

    // Handling incoming requests
    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        printf("Incoming connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        // Receiving messages from clients 
        bzero(buffer, BUFSIZE);
        recv(newsockfd, buffer, BUFSIZE, 0);
        printf("Received message:\n%s\n", buffer);

        // Crafting the response message 
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\nContent-Type: text/plain\r\n\r\nHello, World!", strlen("Hello, World!"));

        // Sending the response message back to the client 
        send(newsockfd, response, strlen(response), 0);
        printf("Response sent:\n%s\n", response);

        // Closing the connection 
        close(newsockfd);
    }

    // Closing the server socket 
    close(sockfd);
    printf("The socket has been closed. Goodbye!");
    return 0;
}