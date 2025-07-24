//FormAI DATASET v1.0 Category: Client Server Application ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, newsockfd, client_len, n;
    char buffer[256];
    struct sockaddr_in server_addr, client_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket!");
    }
    printf("Socket opened successfully!\n");

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("Error on binding!");
    }
    printf("Bind successful!\n");

    listen(sockfd, 5);
    printf("Listening for incoming connections...\n");

    client_len = sizeof(client_addr);

    newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
    if (newsockfd < 0) {
        error("Error on accept!");
    }
    printf("Connection established successfully with a client!\n");

    while (1) {
        printf("Enter message: ");
        bzero(buffer, 256);
        fgets(buffer, 255, stdin);

        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("Error writing to socket!");
        }

        bzero(buffer, 256);

        n = read(newsockfd, buffer, 255);
        if (n < 0) {
            error("Error reading from socket!");
        }
        printf("Client: %s", buffer);

        int cmp = strcmp(buffer, "bye\n");
        if (cmp == 0) {
            close(sockfd);
            close(newsockfd);
            exit(0);
        }
    }

    return 0;
}