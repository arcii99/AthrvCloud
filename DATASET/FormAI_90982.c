//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_LINE 1024
#define PORT_NUM 8080

int main(void) {
    int server_sockfd, client_sockfd, len;
    socklen_t client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    char buf[MAX_LINE];

    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT_NUM);

    if (bind(server_sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Server started. Waiting for connections...\n");

    while (1) {
        client_len = sizeof(client_address);
        if ((client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_address, &client_len)) < 0) {
            perror("accept");
            exit(1);
        }

        printf("Accepted connection from %s, port %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        while ((len = read(client_sockfd, buf, MAX_LINE)) > 0) {
            buf[len] = '\0';
            printf("Received message: \"%s\"\n", buf);
            if (write(client_sockfd, buf, strlen(buf)) < 0) {
                perror("write");
                exit(1);
            }
        }

        close(client_sockfd);
        printf("Disconnected from %s, port %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    }

    close(server_sockfd);
    return 0;
}