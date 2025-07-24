//FormAI DATASET v1.0 Category: Socket programming ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 8080
#define BUF_SIZE 1024

int main(){
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;
    socklen_t len;
    char buf[BUF_SIZE];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Socket creation successful\n");
    }

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0){
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Bind successful\n");
    }

    if((listen(sockfd, 5)) != 0){
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Server listening on port %d\n", PORT);
    }

    len = sizeof(cli);
    connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
    if(connfd < 0){
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Connection accepted\n");
    }

    int n;
    while(1){
        bzero(buf, BUF_SIZE);

        n = read(connfd, buf, sizeof(buf));
        if(n < 0){
            perror("Read failed");
            exit(EXIT_FAILURE);
        }

        if(strcmp(buf, "exit\n") == 0){
            printf("Client has requested to close connection. Closing connection...\n");
            break;
        }

        printf("Message from client: %s", buf);

        write(connfd, buf, strlen(buf));
    }
    close(sockfd);
    return 0;
}