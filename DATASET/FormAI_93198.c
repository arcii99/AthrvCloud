//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Ken Thompson
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>

#define PORT 25

int main(int argc, char const *argv[]) 
{ 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char *msg = "Hello, this is a test message"; 
    char buffer[1024] = {0}; 

    //Create Socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 

    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 

    char *hello = "EHLO\r\n"; 
    send(sock , hello , strlen(hello) , 0); 

    valread = read( sock , buffer, 1024); 
    printf("%s\n",buffer ); 

    char *mail_from = "MAIL FROM:<test@gmail.com>\r\n"; 
    send(sock , mail_from , strlen(mail_from) , 0); 

    valread = read(sock , buffer, 1024); 
    printf("%s\n",buffer ); 

    char *rcpt_to = "RCPT TO:<test@yahoo.com>\r\n";
    send(sock , rcpt_to , strlen(rcpt_to) , 0); 

    valread = read(sock , buffer, 1024); 
    printf("%s\n",buffer ); 

    char *data = "DATA\r\n";
    send(sock , data , strlen(data) , 0); 

    valread = read(sock , buffer, 1024); 
    printf("%s\n",buffer ); 

    send(sock , msg , strlen(msg) , 0); 

    char *endl = "\r\n.\r\n";
    send(sock , endl , strlen(endl) , 0); 

    valread = read(sock , buffer, 1024); 
    printf("%s\n",buffer ); 

    // Close the socket
    close(sock); 
    return 0; 
}