//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: genious
/*
Genius TCP/IP Programming Example Program
By: [Your Name]

Description:
This program creates a simple TCP client that connects to a server and sends a message. The server receives the message and sends a response back to the client.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080 // Port number for the server

int main(int argc, char const *argv[]) {

    int sock = 0;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};

    // Create socket and set up server address
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IP address from string notation to binary notation
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Send message to server
    send(sock , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");

    // Receive message from server
    read( sock , buffer, 1024);
    printf("Server response : %s\n",buffer );

    return 0;
}