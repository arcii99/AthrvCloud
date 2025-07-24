//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 4096 // Maximum size of the buffer for receiving data

int main(int argc, char **argv)
{
    int sock_fd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    if (argc != 2) {
        printf("Usage: %s <Server IP>\n", argv[0]);
        exit(1);
    }

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: Could not create socket.\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080); // Port number for the chat server

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("Error: Could not convert IP address.\n");
        exit(1);
    }

    if (connect(sock_fd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error: Could not connect to server.\n");
        exit(1);
    }

    printf("Connected to server.\n");

    while ((n = read(sock_fd, recvline, MAXLINE)) > 0) {
        recvline[n] = 0;

        // In this example program, we are simply printing the data we receive
        printf("%s", recvline);
    }

    if (n < 0) {
        printf("Error: Read error.\n");
        exit(1);
    }

    close(sock_fd);

    return 0;
}