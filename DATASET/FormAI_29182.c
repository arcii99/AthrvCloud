//FormAI DATASET v1.0 Category: Client Server Application ; Style: detailed
// simple client and server program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000 // the port number for the server

int main()
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr; // server address structure
    char *hello = "Hello from the client";
    char buffer[1024] = {0};

    // create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    // set up the server address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    // send hello message to server
    send(sock , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");

    // read message from server
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );

    return 0;
}