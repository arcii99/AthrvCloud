//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: recursive
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
  
#define PORT 8080 
#define MAX_BUFFER_SIZE 1024 

void recursive_echo(int sockfd) 
{   
    char buffer[MAX_BUFFER_SIZE]; 
    memset(buffer, 0, sizeof(buffer)); 
  
    int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0); 
    if(bytes_received == 0) 
    { 
        printf("Connection closed by the client\n"); 
        return; 
    } 
  
    printf("Client: %s\n", buffer); 
    send(sockfd, buffer, bytes_received, 0); 
  
    recursive_echo(sockfd); 
} 
  
int main() 
{  
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if(sockfd == -1) 
    { 
        printf("Failed to create the socket\n"); 
        return -1; 
    } 
  
    struct sockaddr_in address; 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 
      
    if(bind(sockfd, (struct sockaddr*)&address, sizeof(address)) == -1) 
    { 
        printf("Failed to bind the socket\n"); 
        return -1; 
    } 
      
    if(listen(sockfd, 3) == -1) 
    { 
        printf("Failed to listen to the socket\n"); 
        return -1; 
    } 
      
    printf("Server is listening for incoming connections...\n"); 
  
    while(1) 
    { 
        int client_sock = accept(sockfd, NULL, NULL); 
        if(client_sock == -1) 
        { 
            printf("Failed to accept the connection from the client\n"); 
            return -1; 
        } 
  
        recursive_echo(client_sock); 
    } 
  
    return 0; 
}