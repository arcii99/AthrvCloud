//FormAI DATASET v1.0 Category: Networking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 3000
#define MAX_BUFF_SIZE 1024

int main(int argc, char **argv){

    int sock_fd = 0;
    struct sockaddr_in serv_addr;

    char buffer[MAX_BUFF_SIZE] = {0};
    char *message = "Hello, World!";

    // Create socket, and retrieve socket file descriptor (sock_fd)
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("\nSocket creation error \n");
        return -1;
    }

    // Set up the socket to communicate over IP address and PORT
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0){
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Attempt to connect to server
    if (connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        printf("\nConnection Failed \n");
        return -1;
    }

    // Write message to socket
    send(sock_fd , message , strlen(message) , 0 );

    // Retrieve server response and print
    int valread;
    valread = read(sock_fd , buffer, MAX_BUFF_SIZE);
    printf("%s\n",buffer );

    return 0;
}