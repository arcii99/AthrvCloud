//FormAI DATASET v1.0 Category: Simple Web Server ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SA struct sockaddr
#define MAXLINE 1024

int main(int argc, char* argv[])
{
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char buff[MAXLINE];
    int i, n;

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed!\n");
        exit(0);
    }
    else
        printf("Socket created successfully.\n");

    bzero(&servaddr, sizeof(servaddr));

    // Assigning IP and PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);

    // Binding newly created socket to given IP and PORT
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("Socket bind failed!\n");
        exit(0);
    }
    else
        printf("Socket binded successfully.\n");

    // Listening for client requests
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed!\n");
        exit(0);
    }
    else
        printf("Server listening for client requests...\n");

    // Accepting client request and creating new socket
    socklen_t len = sizeof(cliaddr);
    connfd = accept(sockfd, (SA*)&cliaddr, &len);
    if (connfd < 0) {
        printf("Server accept failed!\n");
        exit(0);
    }
    else
        printf("Server accepted the client request successfully.\n");

    // Reading the message sent by the client
    bzero(buff, sizeof(buff));
    read(connfd, buff, sizeof(buff));
    printf("Client message: %s\n", buff);

    // Writing a response back to the client
    char* response = "HTTP/1.1 200 OK\nContent-Type: text/html\nConnection: close\n\n<html><body><h1>Welcome to the Post-Apocalyptic World!</h1></body></html>";
    write(connfd, response, strlen(response));

    close(connfd);
    close(sockfd);

    return 0;
}