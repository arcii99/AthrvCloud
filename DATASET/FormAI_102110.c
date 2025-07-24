//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

int main(int argc, char const *argv[]) {
    int sockfd;
    char buffer[MAXLINE];
    char *hello = "Hello from C TCP/IP client";
    struct sockaddr_in servaddr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connecting to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    // Sending message to server
    send(sockfd, hello, strlen(hello), 0);
    printf("Message sent to server: %s\n", hello);

    // Receiving message from server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, MAXLINE, 0) < 0) {
        perror("message receiving failed");
        exit(EXIT_FAILURE);
    }
    printf("Server response: %s\n", buffer);

    // Closing the socket
    close(sockfd);
    return 0;
}