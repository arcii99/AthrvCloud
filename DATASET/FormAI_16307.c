//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080   // port number for communication

int main(int argc, char const *argv[]) 
{ 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char *hello = "Hello from client"; 
    char buffer[1024] = {0}; 
    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Error : Could not create socket \n"); 
        return -1; 
    } 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\n inet_pton error occured\n"); 
        return -1; 
    } 
    // connect the socket with the server address
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\n Connection Failed \n"); 
        return -1; 
    } 
    // send message to the server
    send(sock , hello , strlen(hello) , 0 ); 
    printf("Hello message sent\n"); 
    // receive response from the server 
    valread = read( sock , buffer, 1024); 
    printf("%s\n",buffer ); 
    return 0; 
}