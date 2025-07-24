//FormAI DATASET v1.0 Category: Networking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Main function
int main() {
    printf("Welcome to the exciting world of C Networking!\n");

    // Creating a socket
    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Failed to create socket\n");
        return 1;
    }
    printf("Socket created successfully!\n");

    // Prepare the sockaddr_in structure
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8080);

    // Connect to remote server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection failed\n");
        return 1;
    }
    printf("Connected to the server!\n");

    // Send some data
    char *message = "Hello server, I am a chatbot!";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Failed to send data\n");
        return 1;
    }
    printf("Data sent successfully!\n");

    // Receive some data
    char server_reply[2000];
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        printf("Failed to receive data\n");
        return 1;
    }
    printf("Server replied with: %s\n", server_reply);

    // Close the socket
    close(socket_desc);

    printf("Thank you for using this program!\n");

    return 0;
}