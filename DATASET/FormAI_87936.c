//FormAI DATASET v1.0 Category: Client Server Application ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080

// Function to handle the client requests
void handle_client_request(int client_socket) {
    char buffer[1024];
    int read_bytes;
    
    // Read the incoming message from the client
    read_bytes = read(client_socket, buffer, sizeof(buffer));
    
    if (read_bytes < 0) {
        perror("Read failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Received message from client: %s\n", buffer);
    
    // Send a response back to the client
    char *message = "Hello from the server!";
    int write_bytes = write(client_socket, message, strlen(message));
    
    if (write_bytes < 0) {
        perror("Write failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Sent message to client: %s\n", message);
    
    // Close the client socket connection
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length;
    
    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server socket created successfully\n");
    
    memset(&server_address, 0, sizeof(server_address));
    
    // Set the server socket details
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    // Bind the server socket to the specified port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server socket has been binded successfully\n");
    
    // Listen for incoming client connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server is listening for incoming clients\n");
    
    while (1) {
        client_address_length = sizeof(client_address);
        
        // Accept any incoming client connection requests
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        
        if (client_socket < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        printf("New client connection accepted\n");
        
        // Handle the client request
        handle_client_request(client_socket);
        
        printf("Client connection closed\n");
    }
    
    // Close the server socket connection
    close(server_socket);
    
    return 0;
}