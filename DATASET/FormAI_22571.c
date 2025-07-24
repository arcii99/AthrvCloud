//FormAI DATASET v1.0 Category: Networking ; Style: systematic
// Example program demonstrating C networking

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char message[1024] = {0};
    char buffer[1024] = {0};
    
    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IP address to binary format
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("Invalid address/ Address not supported\n");
        return -1;
    }

    // Connect to socket
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        return -1;
    }
    
    // Send message to server
    strcpy(message , "Hello from client");
    send(sock , message , strlen(message) , 0 );
    printf("Message sent to server\n");

    // Receive message from server
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
    return 0;
}