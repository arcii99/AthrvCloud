//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: complex
#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

#define PORT 8080 

int main() 
{ 
    int sock = 0;
    struct sockaddr_in serv_addr; 
    char *data = "Hello from the client!"; 
    char buffer[1024] = {0};
    
    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 

    // Setting server address details
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 

    // Send data to server
    send(sock , data , strlen(data) , 0 ); 
    printf("Hello message sent\n"); 

    // Receive data from server
    read( sock , buffer, 1024); 
    printf("%s\n", buffer ); 
    return 0; 
}