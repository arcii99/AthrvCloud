//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Alan Touring
#include <stdio.h>          //for standard I/O operations
#include <stdlib.h>         //for exit() function
#include <string.h>         //for string manipulation functions
#include <sys/socket.h>     //for socket(), connect(), send(), recv() functions
#include <netinet/in.h>     //for sockaddr_in structure

#define PORT 8080           //Port number for the connection

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char *hello = "Hello from client";

    //Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));        //Clear the structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    //Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    //Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    //Send data to the server
    send(sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    //Receive data from the server
    valread = recv(sock, buffer, 1024, 0);
    printf("%s\n", buffer);
    return 0;
}