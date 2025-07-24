//FormAI DATASET v1.0 Category: Chat server ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the maximum message length
#define MAX_MESSAGE_LENGTH 1024

// Define the port number for the server
#define PORT 8888

int main() {

    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_MESSAGE_LENGTH];
    int connection_status;
    int message_size;

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Check if the server socket was created successfully
    if (server_socket < 0) {
        printf("Error creating the server socket.\n");
        exit(1);
    }

    // Set the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the server socket to the specified address and port
    connection_status = bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

    // Check if the server socket was bound successfully
    if (connection_status < 0) {
        printf("Error binding the server socket.\n");
        exit(1);
    }

    // Listen for incoming connections
    connection_status = listen(server_socket, 10);

    // Check if the server is listening for incoming connections
    if (connection_status < 0) {
        printf("Error while listening for incoming connections.\n");
        exit(1);
    }

    printf("Server started listening for incoming connections.\n");

    while (1) {
        // Accept an incoming client connection
        int client_address_length = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_address_length);

        // Check if the client connection was accepted successfully
        if (client_socket < 0) {
            printf("Error accepting client connection.\n");
            exit(1);
        }

        // Get the client IP address and port
        char *client_ip = inet_ntoa(client_addr.sin_addr);
        int client_port = ntohs(client_addr.sin_port);
        printf("New client connection accepted from %s:%d\n", client_ip, client_port);

        while (1) {
            // Receive a message from the client
            message_size = read(client_socket, buffer, MAX_MESSAGE_LENGTH);

            // Check if the message was received successfully
            if (message_size < 0) {
                printf("Error receiving message from client.\n");
                exit(1);
            }

            // Null terminate the received message string
            buffer[message_size] = '\0';

            // Check if the client has disconnected
            if (message_size == 0) {
                printf("Client disconnected.\n");
                break;
            }

            // Reply to the client with the received message
            printf("Received message from client: %s", buffer);
            write(client_socket, buffer, strlen(buffer));
        }

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}