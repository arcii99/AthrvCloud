//FormAI DATASET v1.0 Category: Socket programming ; Style: brave
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 

#define PORT 8080 

int main() 
{ 
    int sock, valread; 
    struct sockaddr_in serv_addr; 
    char *hello = "Hello from the other side!"; 
    char buffer[1024] = {0}; 
    
    // create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("Socket creation error"); 
        return -1; 
    } 

    // initialize socket structure 
    memset(&serv_addr, '0', sizeof(serv_addr)); 
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
    
    // convert IPv4 and IPv6 addresses from text to binary form 
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) 
    { 
        printf("\nInvalid address/ Address not supported"); 
        return -1; 
    } 

    // connect the socket to the server address 
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed"); 
        return -1; 
    } 
    
    // send message to server 
    send(sock , hello , strlen(hello) , 0 ); 
    printf("Sent message to server: %s\n", hello); 
    
    // receive message from server 
    valread = read( sock , buffer, 1024); 
    printf("Received message from server: %s\n",buffer ); 
    
    // close the socket 
    close(sock); 
    return 0; 
}