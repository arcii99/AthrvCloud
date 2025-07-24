//FormAI DATASET v1.0 Category: Socket programming ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 666
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;
    char buffer[BUFFER_SIZE];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed..\n");
        exit(0);
    }
    else {
        printf("Socket successfully created..\n");
    }

    // assign IP, port
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // bind newly created socket to given IP and port
    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
        printf("Socket bind failed..\n");
        exit(0);
    }
    else {
        printf("Socket successfully binded..\n");
    }

    // listen for clients
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed..\n");
        exit(0);
    }
    else {
        printf("Server listening..\n");
    }

    socklen_t len = sizeof(cli);
    connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
    if (connfd < 0) {
        printf("Server accept failed..\n");
        exit(0);
    }
    else {
        printf("Server accepted the client..\n");
    }

    // read from client and send response
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        read(connfd, buffer, sizeof(buffer));
        if (strncmp(buffer, "exit", 4) == 0) {
            printf("Client disconnected..\n");
            break;
        }
        printf("From client: %s\n", buffer);
        char response[BUFFER_SIZE] = "I am the last server alive.";
        write(connfd, response, strlen(response));
    }

    // close socket
    close(sockfd);
    return 0;
}