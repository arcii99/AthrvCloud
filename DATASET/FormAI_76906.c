//FormAI DATASET v1.0 Category: Socket programming ; Style: grateful
#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 
#include <unistd.h> //for read and write function
#include <arpa/inet.h> //for inet_pton function
#include <sys/socket.h> //for socket function
 
#define PORT 8080 
   
int main(int argc, char const *argv[]) 
{ 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char *hello = "Grateful to meet you, server!"; 
    char buffer[1024] = {0}; 

    //Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 

    //Setting up the socket address and port number
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 

    //Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 

    //send message to the server
    send(sock , hello , strlen(hello) , 0 ); 
    printf("Message sent to server.\n"); 
    //read the response from server
    valread = read( sock , buffer, 1024); 
    printf("%s\n",buffer ); 

    return 0; 
}