//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096
#define SERVER_PORT 8888

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, clientfd;
    int n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("ERROR opening socket");
    }

    int enable = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
        error("ERROR on setsockopt");
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("ERROR on binding");
    }

    if (listen(sockfd, 5) < 0) {
        error("ERROR on listen");
    }

    while (1) {
        if ((clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            error("ERROR on accept");
        }

        bzero(buffer, BUFFER_SIZE);
        n = read(clientfd, buffer, BUFFER_SIZE - 1);
        if (n < 0) {
            error("ERROR reading from socket");
        }
        printf("%s\n", buffer);

        char *request = strtok(buffer, " ");
        request = strtok(NULL, " ");
        printf("%s\n", request);

        struct sockaddr_in remote_addr;
        int remote_len = sizeof(remote_addr);
        int remote_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        bzero((char *) &remote_addr, sizeof(remote_addr));
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_addr.s_addr = inet_addr(request);
        remote_addr.sin_port = htons(80);

        if (connect(remote_sockfd, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) < 0) {
            error("ERROR connecting");
        }

        n = write(remote_sockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("ERROR writing to socket");
        }

        bzero(buffer, BUFFER_SIZE);
        while ((n = read(remote_sockfd, buffer, BUFFER_SIZE - 1)) > 0) {
            n = write(clientfd, buffer, n);
            if (n < 0) {
                error("ERROR writing to socket");
            }
            bzero(buffer, BUFFER_SIZE);
        }

        close(clientfd);
        close(remote_sockfd);
    }

    close(sockfd);
    return 0;
}