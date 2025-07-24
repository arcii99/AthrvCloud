//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: accurate
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

#define PORT 8080 

int main() 
{ 
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli; 
  
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("Socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created...\n"); 
    bzero(&servaddr, sizeof(servaddr)); 

    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("Socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully bound...\n"); 
  
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening...\n"); 
    len = sizeof(cli); 
  
    connfd = accept(sockfd, (struct sockaddr*)&cli, &len); 
    if (connfd < 0) { 
        printf("Server accept failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server accept the client...\n"); 
  
    char buffer[1024];
    int n;
    n = read(connfd, buffer, sizeof(buffer)); 
    printf("Client : %s", buffer); 
    printf("Server : ");
    fgets(buffer, sizeof(buffer), stdin);
    write(connfd, buffer, strlen(buffer));
  
    close(sockfd); 
}