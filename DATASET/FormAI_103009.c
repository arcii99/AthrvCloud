//FormAI DATASET v1.0 Category: Socket programming ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main() {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[1024];

    // create socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // check if socket was created successfully
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // set server address and port number
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);

    // bind socket to server address and port number
    if(bind(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if(listen(sockfd, 5) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    // accept incoming connection
    int addrlen = sizeof(cliaddr);
    connfd = accept(sockfd, (struct sockaddr*) &cliaddr, (socklen_t*) &addrlen);

    // send welcome message to client
    char* welcome_message = "Welcome to the server!";
    send(connfd, welcome_message, strlen(welcome_message), 0);

    // receive message from client
    memset(&buffer, 0, sizeof(buffer));
    recv(connfd, buffer, sizeof(buffer), 0);

    // print received message
    printf("Received message from client: %s\n", buffer);

    // send response to client
    char* response_message = "Thank you for connecting!";
    send(connfd, response_message, strlen(response_message), 0);

    // close connection
    close(connfd);

    printf("Program completed successfully!\n");

    return 0;
}