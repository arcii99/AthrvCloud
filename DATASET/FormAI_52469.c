//FormAI DATASET v1.0 Category: Socket programming ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8080
#define MAXLINE 1024

int main(int argc, char const *argv[]) {

    struct sockaddr_in server_address;

    int sockfd;

    char buffer[MAXLINE];

    char *hello = "Hello from client";

    // create a socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));

    // set the server address family, IP address, and port number
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("invalid address/ address not supported");
        exit(EXIT_FAILURE);
    }

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    // send hello message to the server
    send(sockfd, hello, strlen(hello), 0);

    printf("Hello message sent\n");

    // read server's response
    memset(buffer, 0, sizeof(buffer));
    read(sockfd, buffer, MAXLINE);

    printf("Server response: %s\n", buffer);

    // close the socket file descriptor
    close(sockfd);

    return 0;
}