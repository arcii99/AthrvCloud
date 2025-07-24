//FormAI DATASET v1.0 Category: Socket programming ; Style: interoperable
// Interoperable socket programming example in C
#include <stdio.h> // Standard input/output library
#include <stdlib.h> // Standard library
#include <string.h> // String handling library
#include <errno.h> // Error handling library
#include <unistd.h> // Unix standard library
#include <netdb.h> // Networking library
#include <netinet/in.h> // Internet protocol family library
#include <sys/types.h> // System data types library
#include <sys/socket.h> // Socket programming library

#define PORT 8080 // Server port number
#define MAX_CLIENTS 5 // Maximum number of clients allowed

// Function to handle incoming client requests
void handle_connection(int client_socket) {
    char buffer[1024];
    int bytes_received;

    while(1) {
        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));
        
        // Receive data from the client
        bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received < 0) {
            perror("Error receiving data from client.");
            break;
        }
        else if (bytes_received == 0) {
            printf("Client disconnected.\n");
            break;
        }
        
        // Display the received data
        printf("Received: %s", buffer);

        // Send a response to the client
        if (send(client_socket, buffer, bytes_received, 0) < 0) {
            perror("Error sending data to client.");
            break;
        }
    }

    // Close the client socket
    close(client_socket);
}

int main()
{
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    int address_size = sizeof(server_address);

    // Create the server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating server socket.");
        return EXIT_FAILURE;
    }

    // Set the server address parameters
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the server socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket.");
        return EXIT_FAILURE;
    }

    // Listen for incoming client connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Error listening for connections.");
        return EXIT_FAILURE;
    }

    printf("Server is running and listening for connections on port %d\n", PORT);

    // Accept incoming connections from clients
    while (1) {
        // Wait for a client to connect
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&address_size)) < 0) {
            perror("Error accepting client connection.");
            continue;
        }

        // Display the client's address and port number
        printf("New connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Handle the client's request
        handle_connection(client_socket);
    }

    // Close the server socket
    close(server_socket);
    
    return EXIT_SUCCESS;
}