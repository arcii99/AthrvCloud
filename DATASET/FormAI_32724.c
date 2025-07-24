//FormAI DATASET v1.0 Category: Networking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8000
#define MAXMSGLEN 1024

int main() {
    int sockfd, newsockfd, n;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAXMSGLEN];
    socklen_t clilen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    clilen = sizeof(cliaddr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
    if (newsockfd < 0) {
        perror("accept");
        exit(1);
    }

    printf("Client connected from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

    while (1) {
        bzero(&buffer, sizeof(buffer));
        n = recv(newsockfd, buffer, sizeof(buffer)-1, 0);
        if (n < 0) {
            perror("recv");
            exit(1);
        }

        if (n == 0) {
            printf("Client closed connection.\n");
            break;
        }

        printf("Received message from client: %s", buffer);
        n = send(newsockfd, buffer, strlen(buffer), 0);
        if (n < 0) {
            perror("send");
            exit(1);
        }
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}