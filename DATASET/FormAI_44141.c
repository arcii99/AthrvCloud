//FormAI DATASET v1.0 Category: Socket programming ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888

int main(int argc, char *argv[]) {
    int sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    char buffer[256];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    printf("Waiting for connection...\n");

    client_len = sizeof(client_addr);
    client_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);

    if (client_sockfd < 0) {
        perror("ERROR on accepting");
        exit(1);
    }

    printf("Connection accepted.\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        n = read(client_sockfd, buffer, sizeof(buffer) - 1);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Received message: %s\n", buffer);

        if (strcmp(buffer, "Exit") == 0) {
            printf("Closing connection...\n");
            close(client_sockfd);
            close(sockfd);
            exit(0);
        }

        char response[256] = "Response: ";
        strcat(response, buffer);

        n = write(client_sockfd, response, strlen(response));
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }

    return 0;
}