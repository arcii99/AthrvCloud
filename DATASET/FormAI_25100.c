//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Initialize socket variables
    int socket_desc;
    struct sockaddr_in server;
    char *message, server_reply[BUFFER_SIZE];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) { // Handle errors
        printf("Failed to create socket");
        return -1;
    }
    printf("Socket created\n");

    // Fill in server details
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with your server's IP address
    server.sin_family = AF_INET;
    server.sin_port = htons(80); // Replace with your server's port number

    // Connect to server
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0) { // Handle errors
        printf("Failed to connect to server");
        return -1;
    }
    printf("Connected to server\n");

    // Send HTTP request
    message = "GET / HTTP/1.1\r\n\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) { // Handle errors
        printf("Failed to send HTTP request");
        return -1;
    }
    printf("HTTP request sent\n");

    // Receive server response
    if (recv(socket_desc, server_reply, BUFFER_SIZE, 0) < 0) { // Handle errors
        printf("Failed to receive server response");
        return -1;
    }
    printf("Server response received:\n%s", server_reply);

    // Close socket
    close(socket_desc);

    return 0;
}