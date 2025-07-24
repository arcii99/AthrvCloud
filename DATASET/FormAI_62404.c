//FormAI DATASET v1.0 Category: Chat server ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int sockfd, new_sockfd, client_len;
    struct sockaddr_in server_addr, client_addr;
    char message[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error on binding");
        exit(1);
    }

    listen(sockfd, 1);
    printf("Waiting for incoming connections...\n");

    while (1) {
        client_len = sizeof(client_addr);
        new_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
        if (new_sockfd < 0) {
            perror("Error on accept");
            exit(1);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(message, 0, sizeof(message));
            read(new_sockfd, message, sizeof(message));
            if (strlen(message) == 0) {
                break;
            }

            printf("Received message: %s\n", message);

            write(new_sockfd, "Server received your message", 28);
        }

        close(new_sockfd);
        printf("Client disconnected\n");
    }

    close(sockfd);
    return 0;
}