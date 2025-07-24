//FormAI DATASET v1.0 Category: Chat server ; Style: Cryptic
//Encrypting server code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

#define PORT_NUMBER     5000
#define BUFFER_SIZE     1024

void encrypt(char *buf, int len) {
    int i;
    for (i = 0; i < len; i++) {
        if ((buf[i] >= 'A' && buf[i] <= 'Z') || (buf[i] >= 'a' && buf[i] <= 'z')) {
            buf[i] = buf[i] + 1;
        }
    }
}

int main(int argc, char **argv) {
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t sin_len = sizeof(client_addr);
    char message[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT_NUMBER);

    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(sockfd);
        exit(1);
    }

    if (listen(sockfd, 10) == -1) {
        perror("listen");
        close(sockfd);
        exit(1);
    }

    while (1) {
        new_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &sin_len);

        if (new_sockfd == -1) {
            perror("accept");
            continue;
        }

        printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));
        send(new_sockfd, "Welcome to the encrypted chat server\n", 38, 0);

        while (1) {
            memset(message, 0, BUFFER_SIZE);
            if (recv(new_sockfd, message, BUFFER_SIZE, 0) == -1) {
                perror("recv");
                break;
            }

            printf("Received message: %s\n", message);
            encrypt(message, strlen(message));
            printf("Encrypted message: %s\n", message);

            if (send(new_sockfd, message, strlen(message), 0) == -1) {
                perror("send");
                break;
            }
        }

        printf("Client disconnected: %s\n", inet_ntoa(client_addr.sin_addr));
        close(new_sockfd);
    }

    return 0;
}