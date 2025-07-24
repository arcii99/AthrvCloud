//FormAI DATASET v1.0 Category: Socket programming ; Style: recursive
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define PORT 8080 
#define MAXLINE 1024 

int recursive_recvfrom(int sockfd, char *buffer, struct sockaddr_in *cliaddr, socklen_t *len) {
    int n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)cliaddr, len); 
    buffer[n] = '\0'; 
    if (strcmp(buffer, "exit") == 0) {
        return 1;
    }
    printf("Client : %s\n", buffer); 
    recursive_recvfrom(sockfd, buffer, cliaddr, len);
}

int main() { 
    int sockfd; 
    char buffer[MAXLINE]; 
    struct sockaddr_in servaddr, cliaddr; 
    
    // Creating socket file descriptor 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
    memset(&servaddr, 0, sizeof(servaddr)); 
    memset(&cliaddr, 0, sizeof(cliaddr)); 
    
    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(PORT); 
    
    // Bind the socket with the server address 
    bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)); 
    
    socklen_t len; 
    len = sizeof(cliaddr); 
    
    recursive_recvfrom(sockfd, buffer, &cliaddr, &len); 

    close(sockfd); 
    return 0; 
}