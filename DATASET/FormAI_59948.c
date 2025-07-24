//FormAI DATASET v1.0 Category: Socket programming ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8888

int main()
{
    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Socket options set failed");
        exit(1);
    }

    // Bind socket to address and port
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Socket bind failed");
        exit(1);
    }

    // Start listening on the socket
    if (listen(sockfd, 3) < 0) {
        perror("Socket listen failed");
        exit(1);
    }

    // Accept and handle incoming connections
    int addrlen = sizeof(address);
    while (1) {
        int new_socket = accept(sockfd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            perror("Socket accept failed");
            exit(1);
        }

        // Read incoming message from client
        char buffer[1024] = {0};
        read( new_socket , buffer, 1024);

        // Handle message appropriately
        if (strcmp(buffer, "Hello") == 0) {
            char* reply = "Hi there!";
            send(new_socket, reply, strlen(reply), 0);
        }
        else if (strcmp(buffer, "What's your name?") == 0) {
            char* reply = "My name is Ephemeral Socket Bot!";
            send(new_socket, reply, strlen(reply), 0);
        }
        else {
            char* reply = "I don't understand. Can you please rephrase?";
            send(new_socket, reply, strlen(reply), 0);
        }

        // Close connection
        close(new_socket);
    }

    // Close server socket
    close(sockfd);
    return 0;
}