//FormAI DATASET v1.0 Category: Socket programming ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    unsigned int len;
    char buffer[1024];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error in bind");
        exit(EXIT_FAILURE);
    }
    
    if (listen(sockfd, 5) < 0) {
        perror("Error in listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d\n", PORT);
    
    len = sizeof(cliaddr);
    connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
    if (connfd < 0) {
        perror("Error in accept");
        exit(EXIT_FAILURE);
    }
    
    printf("Connected to client: %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
    
    while (1) {
        memset(&buffer, 0, sizeof(buffer));
        if (read(connfd, buffer, sizeof(buffer)) < 0) {
            perror("Error reading from client");
            exit(EXIT_FAILURE);
        }
        printf("Received message from client: %s\n", buffer);
        
        if (strcmp(buffer, "exit") == 0) {
            printf("Closing connection...\n");
            break;
        }
        
        char *reply = "Received your message";
        if (write(connfd, reply, strlen(reply)) < 0) {
            perror("Error writing to client");
            exit(EXIT_FAILURE);
        }
        printf("Sent reply to client: %s\n", reply);
    }
    
    close(connfd);
    close(sockfd);
    
    return 0;
}