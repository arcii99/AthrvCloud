//FormAI DATASET v1.0 Category: Chat server ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    int sockfd, ret;
    struct sockaddr_in serverAddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("[-]Error in connection.\n");
        exit(1);
    }

    printf("[+]Server socket created successfully.\n");

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if (ret < 0) {
        error("[-]Error in binding.\n");
        exit(1);
    }

    printf("[+]Bind to port %d\n", PORT);

    if (listen(sockfd, 10) == 0) {
        printf("[+]Listening....\n");
    } else {
        error("[-]Error in listening.\n");
        exit(1);
    }

    while (1) {
        int connfd = accept(sockfd, (struct sockaddr*)NULL, NULL);
        if (connfd < 0) {
            error("[-]Error in accepting.\n");
            continue;
        }

        char buffer[1024];
        memset(buffer, '\0', sizeof(buffer));
        int n = read(connfd, buffer, sizeof(buffer));
        if (n < 0) {
            error("[-]Error in reading.\n");
            exit(1);
        }

        printf("Client: %s\n", buffer);
        memset(buffer, '\0', sizeof(buffer));
        printf("Reply: ");
        fgets(buffer, sizeof(buffer), stdin);

        n = write(connfd, buffer, strlen(buffer));
        if (n < 0) {
            error("[-]Error in writing.\n");
            exit(1);
        }

        close(connfd);

    }

    return 0;
}