//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: careful
#include <netinet/in.h>         
#include <stdio.h>              
#include <stdlib.h>             
#include <string.h>             
#include <sys/socket.h>         
#include <sys/types.h>          
#include <unistd.h>             
#define PORT 8080

int main() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed!\n");
        exit(0);
    } else {
        printf("Socket created successfully!\n");
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
        printf("Socket bind failed!\n");
        exit(0);
    } else {
        printf("Socket binded successfully!\n");
    }
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed!\n");
        exit(0);
    } else {
        printf("Server listening on port %d...\n", PORT);
    }
    int connfd;
    socklen_t len = sizeof(servaddr);
    connfd = accept(sockfd, (struct sockaddr*)&servaddr, &len);
    if (connfd < 0) {
        printf("Accept failed!\n");
        exit(0);
    } else {
        printf("Server accepted the client successfully!\n");
    }
    while (1) {
        bzero(buffer, 1024);
        read(connfd, buffer, sizeof(buffer));
        printf("Client: %s\n", buffer);
        if ((strncmp(buffer, "exit", 4)) == 0) {
            printf("Server exit...\n");
            break;
        }
        printf("Enter server message: ");
        bzero(buffer, 1024);
        int n = 0;
        while ((buffer[n++] = getchar()) != '\n')
            ;
        write(connfd, buffer, sizeof(buffer));
        if ((strncmp(buffer, "exit", 4)) == 0) {
            printf("Server exit...\n");
            break;
        }
    }
    close(sockfd);
    return 0;
}