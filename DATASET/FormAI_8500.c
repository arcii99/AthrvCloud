//FormAI DATASET v1.0 Category: Simple Web Server ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

#define PORT 8080
#define BUF_SIZE 1024

int main(){
    int sockfd, connfd;
    struct sockaddr_in servaddr, client;
    char buffer[BUF_SIZE] = {0};

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("Socket creation failed.");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, '\0', sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if(bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
        perror("Bind failed.");
        exit(EXIT_FAILURE);
    }

    if(listen(sockfd, 5) < 0){
        perror("Listen failed.");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d\n", PORT);

    while(1){
        int client_addr_len = sizeof(client);
        connfd = accept(sockfd, (struct sockaddr*)&client, (socklen_t*)&client_addr_len);
        if(connfd < 0){
            perror("Accept failed.");
            exit(EXIT_FAILURE);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        int bytes_read = recv(connfd, buffer, BUF_SIZE, 0);
        while(bytes_read > 0){
            printf("%s", buffer);
            bytes_read = recv(connfd, buffer, BUF_SIZE, 0);
        }

        char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello World!</h1></body></html>";
        send(connfd, response, strlen(response), 0);
        printf("Response sent to client.\n");

        close(connfd);
    }

    close(sockfd);

    return 0;
}