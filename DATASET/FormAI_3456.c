//FormAI DATASET v1.0 Category: Client Server Application ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 9090

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, n;
    socklen_t clientLen;
    char buffer[1024];
    struct sockaddr_in serv_addr, client_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error on binding");
    }

    listen(sockfd, 5);
    clientLen = sizeof(client_addr);

    printf("Waiting for client...");
    newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &clientLen);
    if (newsockfd < 0) {
        error("Error on accept");
    }

    printf("Client connected\n");
    bzero(buffer,1024);
    n = read(newsockfd, buffer, 1023);
    if (n < 0) {
        error("Error reading from socket");
    }

    printf("Message from client: %s\n", buffer);

    char server_message[256] = "I am the server. Nice to meet you!";

    n = write(newsockfd, server_message, strlen(server_message));
    if (n < 0) {
        error("Error writing to socket");
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}