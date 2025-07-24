//FormAI DATASET v1.0 Category: Client Server Application ; Style: systematic
/* This program is a chat application between client and server using TCP/IP protocol */  
/* The client sends messages to the server and the server responds to its messages */ 

#include <stdio.h>  
#include <sys/socket.h>  
#include <arpa/inet.h>  
#include <string.h>  
#include <unistd.h>  
#define PORT 8080  

int main(int argc, char const *argv[])  
{  
    int sock = 0, valread;  
    struct sockaddr_in serv_addr;  
    char *hello = "Hello from client";  
    char buffer[1024] = {0};  
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)  
    {  
        printf("\n Socket creation error \n");  
        return -1;  
    }  

    serv_addr.sin_family = AF_INET;  
    serv_addr.sin_port = htons(PORT);  
       
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    {  
        printf("\nInvalid address/ Address not supported \n");  
        return -1;  
    }  
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)  
    {  
        printf("\nConnection Failed \n");  
        return -1;  
    }  
    while(1)
    {
        printf("Enter message: ");
        char message[1024];
        fgets(message, sizeof(message), stdin);
        send(sock , message , strlen(message) , 0 );  
        printf("Message sent\n");  
        valread = read( sock , buffer, 1024);  
        printf("%s\n",buffer );
    }
    return 0;  
}