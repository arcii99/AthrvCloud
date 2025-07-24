//FormAI DATASET v1.0 Category: Client Server Application ; Style: beginner-friendly
/* This C Client-Server application allows a client to connect to a server
and send a message. The server will then respond to the client. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 8080

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *message = "Hello from client!";
    char buffer[1024] = {0};

    // Create socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("Socket creation error");
        return -1;
    }

    // Set values of sockaddr_in serv_addr
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, SERVER_ADDRESS, &serv_addr.sin_addr)<=0){
        perror("Invalid address/ Address not supported");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        perror("Connection failed");
        return -1;
    }

    // Send message to server
    if( send(sock , message , strlen(message) , 0) < 0){
        perror("Send failed");
        return -1;
    }

    // Read response from server
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer);

    // Close socket
    close(sock);
    return 0;
}