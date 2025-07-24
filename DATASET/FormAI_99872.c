//FormAI DATASET v1.0 Category: Chat server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT_NUMBER 9002
#define BUFFER_SIZE 256

// Recursive function for handling client requests
void handle_client_request(int client_socket) {

    // Create a buffer to hold messages sent and received
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // Read data from the client
    ssize_t num_bytes = read(client_socket, buffer, BUFFER_SIZE - 1);

    // If there was an error reading, close the connection
    if (num_bytes < 0) {
        close(client_socket);
        return;
    }

    // If the client closed the connection, return
    if (num_bytes == 0) {
        printf("Client disconnected\n");
        close(client_socket);
        return;
    }

    // Print the client's message
    printf("Message from client: %s", buffer);

    // Respond to the client
    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);
    strcpy(response, "Server received your message: ");
    strcat(response, buffer);
    write(client_socket, response, strlen(response));

    // Call the function recursively to handle additional requests from the same client
    handle_client_request(client_socket);
}

int main() {

    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Error creating server socket\n");
        return -1;
    }

    // Bind the socket to a port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT_NUMBER);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int bind_result = bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    if (bind_result < 0) {
        printf("Error binding server socket to port %d\n", PORT_NUMBER);
        close(server_socket);
        return -1;
    }

    // Listen for incoming connections
    int listen_result = listen(server_socket, 5);
    if (listen_result < 0) {
        printf("Error listening for incoming connections\n");
        close(server_socket);
        return -1;
    }

    printf("Server is listening on port %d...\n", PORT_NUMBER);

    // Accept incoming connections
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);

        int client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_length);
        if (client_socket < 0) {
            printf("Error accepting incoming connection\n");
            continue;
        }

        printf("New client connected\n");

        // Handle client requests recursively
        handle_client_request(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}