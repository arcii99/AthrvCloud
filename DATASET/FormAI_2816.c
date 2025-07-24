//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main() {
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, clientaddr;
    char buffer[BUFFER_SIZE];
    char* success = "OK";
    char* failure = "FAILED";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed...\n");
        exit(0);
    } else {
        printf("Socket created successfully\n");
    }
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
        printf("Socket bind failed...\n");
        exit(0);
    } else {
        printf("Socket binded successfully\n");
    }
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    } else {
        printf("Server listening to port %d\n", PORT);
    }
    len = sizeof(clientaddr);
    connfd = accept(sockfd, (struct sockaddr*)&clientaddr, &len);
    if (connfd < 0) {
        printf("Server accept failed...\n");
        exit(0);
    } else {
        printf("Server accept the client...\n");
    }

    while (1) {
        bzero(buffer, sizeof(buffer));
        read(connfd, buffer, sizeof(buffer));
        printf("From client: %s\n", buffer);

        if (strcmp(buffer, "exit") == 0) {
            printf("Server is exiting...\n");
            write(connfd, success, strlen(success));
            break;
        } else {
            write(connfd, failure, strlen(failure));
        }
    }
    close(sockfd);
    return 0;
}