//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MESSAGE_SIZE 1024
#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 8080

int main() {
    int client_socket;
    struct sockaddr_in server_address;
    char message[MAX_MESSAGE_SIZE], server_response[MAX_MESSAGE_SIZE];
    
    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error: Could not create socket.\n");
        exit(EXIT_FAILURE);
    }
    
    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
    server_address.sin_port = htons(SERVER_PORT);
    
    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Could not connect to server.\n");
        exit(EXIT_FAILURE);
    }
    
    // Start multiplayer chat
    printf("*** Multiplayer HTTP Client ***\n");
    printf("Type 'exit' to quit.\n\n");
    while (1) {
        // Get user input
        printf("Enter HTTP Request: ");
        fgets(message, MAX_MESSAGE_SIZE, stdin);
        message[strcspn(message, "\n")] = 0; // remove trailing newline
        
        // Send request to server
        if (send(client_socket, message, strlen(message), 0) < 0) {
            printf("Error: Could not send message to server.\n");
            close(client_socket);
            exit(EXIT_FAILURE);
        }
        
        // Exit if user types 'exit'
        if (strcmp(message, "exit") == 0) {
            break;
        }
        
        // Receive response from server
        if (recv(client_socket, server_response, MAX_MESSAGE_SIZE, 0) < 0) {
            printf("Error: Could not receive message from server.\n");
            close(client_socket);
            exit(EXIT_FAILURE);
        }
        printf("Server Response: %s\n\n", server_response);
    }
    
    // Close socket
    close(client_socket);
    return 0;
}