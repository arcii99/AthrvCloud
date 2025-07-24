//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: imaginative
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

#define MAXLINE 1024 

int main() 
{ 
    int sockfd, newsockfd, len; 
    struct sockaddr_in servaddr, cliaddr; 
    char buffer[MAXLINE]; 

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("Socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 

    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(8080); 

    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("Socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 

    if (listen(sockfd, 5) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    len = sizeof(cliaddr); 

    newsockfd = accept(sockfd, (struct sockaddr*)&cliaddr, &len); 
    if (newsockfd < 0) { 
        printf("Server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server acccept the client...\n"); 

    bzero(buffer, sizeof(buffer)); 
    recv(newsockfd, buffer, sizeof(buffer), 0); 
    printf("Request received from client: %s\n", buffer); 

    int cli_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (cli_sockfd == -1) { 
        printf("Client socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Client socket successfully created..\n");

    char proxy_buffer[MAXLINE]; 
    sprintf(proxy_buffer, "GET %s", buffer+4);
  
    struct sockaddr_in proxy_server_address; 
    bzero(&proxy_server_address, sizeof(proxy_server_address)); 
    
    proxy_server_address.sin_family = AF_INET; 
    proxy_server_address.sin_addr.s_addr = inet_addr("159.89.224.234"); 
    proxy_server_address.sin_port = htons(80); 
  
    if (connect(cli_sockfd, (struct sockaddr*)&proxy_server_address, sizeof(proxy_server_address)) != 0) { 
        printf("Client connection to proxy server failed...\n"); 
        exit(0); 
    } 
    else
        printf("Client connected to proxy server..\n"); 

    send(cli_sockfd, proxy_buffer, sizeof(proxy_buffer), 0); 
    printf("Request sent to proxy server: %s\n", proxy_buffer); 

    bzero(proxy_buffer, sizeof(proxy_buffer)); 
    recv(cli_sockfd, proxy_buffer, sizeof(proxy_buffer), 0); 
    printf("Response received from proxy server: %s\n", proxy_buffer); 

    send(newsockfd, proxy_buffer, sizeof(proxy_buffer), 0); 
    printf("Response sent to client: %s\n", proxy_buffer); 

    close(sockfd); 
}