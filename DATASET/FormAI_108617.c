//FormAI DATASET v1.0 Category: Socket programming ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define MAXLINE 1024

void handle_connection(int sockfd) {
    char buffer[MAXLINE];
    while(1) {
        printf("Waiting for message...\n");
        memset(buffer, 0, MAXLINE);
        int n = read(sockfd, buffer, sizeof(buffer));
        if(n == 0) {
            printf("Client disconnected\n");
            break;
        }
        printf("Client: %s\n", buffer);
        // Convert message to uppercase
        for(int i = 0; i < n; i++) {
            buffer[i] = toupper(buffer[i]);
        }
        // Send back to client
        write(sockfd, buffer, strlen(buffer));
    }
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
    
    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    
    // Bind the socket with the server address
    if(bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ) {
        perror("Socket bind failed");
        exit(EXIT_FAILURE);
    }
    
    // listen for incoming connections
    if(listen(sockfd, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    while(1) {
        socklen_t len = sizeof(cliaddr);
        int connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
        if(connfd < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        printf("Client connected at IP: %s, port: %d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
        handle_connection(connfd);
        close(connfd);
    }
    
    close(sockfd);
    return 0;
}