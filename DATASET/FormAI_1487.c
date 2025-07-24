//FormAI DATASET v1.0 Category: Networking ; Style: puzzling
#include <stdio.h>      //standard i/o library
#include <stdlib.h>     //standard library
#include <string.h>     //string library
#include <sys/socket.h> //socket library
#include <arpa/inet.h>  //internet library
#include <unistd.h>     //unix standard library

#define PORT 8080       //define port number

int main(int argc, char const *argv[]) 
{
    int sock = 0, valread;             //socket descriptor
    struct sockaddr_in serv_addr;      //server address
    char *hello = "Hello from client"; //message to server
    char buffer[1024] = {0};           //buffer to store response from server
    
    //create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    {
        printf("\n Socket creation error \n");
        return -1;
    }
    
    //fill server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    //convert IPV4 server address from string to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    
    //connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    
    //send message to server
    send(sock , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
    
    //read response from server
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
    
    //close socket
    close(sock);
    return 0;
}