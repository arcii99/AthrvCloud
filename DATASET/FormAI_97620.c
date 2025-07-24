//FormAI DATASET v1.0 Category: Socket programming ; Style: lively
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
 
#define PORT 8888 
 
int main(int argc, char const *argv[]) 
{ 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char *hello = "Hello from the other side!"; 
    char buffer[1024] = {0}; 

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("Socket creation error \n"); 
        return -1; 
    } 

    // Set server address
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("Invalid address/ Address not supported \n"); 
        return -1; 
    } 

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("Connection Failed \n"); 
        return -1; 
    } 

    printf("Connected to server \n"); 

    // Send message to server
    send(sock , hello , strlen(hello) , 0 ); 
    printf("Message sent to server! \n"); 

    // Read response from server
    valread = read( sock , buffer, 1024); 
    printf("%s\n",buffer ); 

    return 0; 
}