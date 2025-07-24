//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void receiveMessage(int socket, char *buffer, int size, char *expected) {
    memset(buffer, 0, size);
    recv(socket, buffer, size, 0);

    if (expected != NULL && strncmp(buffer, expected, strlen(expected)) != 0) {
        printf("Error: Expected '%s', got '%s'\n", expected, buffer);
        exit(1);
    }

    printf("%s", buffer);
}

void sendMessage(int socket, char *message) {
    printf("%s", message);
    send(socket, message, strlen(message), 0);
}

int main(int argc, char **argv) {
    int socketDescriptor;
    struct sockaddr_in serverAddress;
    char buffer[BUFFER_SIZE];

    // Create socket
    socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketDescriptor < 0) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    // Configure server address
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(110);

    // Connect to server
    if (connect(socketDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        printf("Error: Could not connect to server\n");
        exit(1);
    }

    receiveMessage(socketDescriptor, buffer, BUFFER_SIZE, "+OK");

    // Login
    sendMessage(socketDescriptor, "USER example@example.com\r\n");
    receiveMessage(socketDescriptor, buffer, BUFFER_SIZE, "+OK");
    sendMessage(socketDescriptor, "PASS password\r\n");
    receiveMessage(socketDescriptor, buffer, BUFFER_SIZE, "+OK");

    // List messages
    sendMessage(socketDescriptor, "LIST\r\n");
    receiveMessage(socketDescriptor, buffer, BUFFER_SIZE, "+OK");

    // Retrieve first message
    sendMessage(socketDescriptor, "RETR 1\r\n");
    receiveMessage(socketDescriptor, buffer, BUFFER_SIZE, "+OK");

    // Quit
    sendMessage(socketDescriptor, "QUIT\r\n");
    receiveMessage(socketDescriptor, buffer, BUFFER_SIZE, "+OK");

    // Close socket
    close(socketDescriptor);

    return 0;
}