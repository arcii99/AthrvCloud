//FormAI DATASET v1.0 Category: Networking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int sockfd, newsockfd, ret;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientLen;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error in socket opening\n");
        exit(1);
    }

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if (ret < 0) {
        printf("Error in binding\n");
        exit(1);
    }

    if (listen(sockfd, 10) == 0) {
        printf("Listening on port %d...\n", PORT);
    } else {
        printf("Error in listening\n");
        exit(1);
    }

    while (1) {
        clientLen = sizeof(clientAddr);
        newsockfd = accept(sockfd, (struct sockaddr*)&clientAddr, &clientLen);
        if (newsockfd < 0) {
            printf("Error in accepting\n");
            exit(1);
        }

        printf("Connection accepted from %s:%d\n",
            inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

        memset(buffer, '\0', sizeof(buffer));
        recv(newsockfd, buffer, 1024, 0);

        printf("Received from client: %s\n", buffer);

        close(newsockfd);
    }

    return 0;
}