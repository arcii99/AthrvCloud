//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Sherlock Holmes
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
  
#define PORT 8000 

int main(int argc, char const *argv[]) 
{ 
    int sock = 0; 
    struct sockaddr_in serv_addr; 
    char *hello = "Hello, from client!"; 
    char buffer[1024] = {0}; 
    
    // Create socket file descriptor 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("Socket creation error\n"); 
        return -1; 
    } 
  
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
      
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("Invalid address / Address not supported\n"); 
        return -1; 
    } 
  
    // Connect socket to the server 
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("Connection failed\n"); 
        return -1; 
    } 

    // Send data to the server
    send(sock , hello , strlen(hello) , 0 ); 
    printf("Client message sent: %s\n", hello ); 
        
    // Receive server's response
    int valread = read( sock , buffer, 1024); 
    printf("Server message received: %s\n",buffer ); 

    // Close the socket 
    close(sock); 
    return 0; 
}