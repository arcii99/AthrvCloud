//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define MAX_BUFFER_SIZE 1024

// Function to print error messages and exit the program
void die(char *error_message) {
    perror(error_message);
    exit(1);
}

int main() {
    int server_socket_fd, client_socket_fd, client_socket_length, read_size;
    struct sockaddr_in server_address, client_address;
    char client_message[MAX_BUFFER_SIZE];

    // Creating server socket
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd < 0) 
        die("Failed to create socket");

    // Setting server address
    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(SERVER_PORT);

    // Binding the socket to the server address
    if (bind(server_socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0)
        die("Failed to bind socket");

    // Start listening for incoming connections
    if (listen(server_socket_fd, 3) < 0)
        die("Failed to listen");

    printf("Listening on port %d\n", SERVER_PORT);

    // Accept incoming connection
    client_socket_length = sizeof(client_address);
    client_socket_fd = accept(server_socket_fd, (struct sockaddr*)&client_address, (socklen_t*)&client_socket_length);
    if (client_socket_fd < 0)
        die("Failed to accept connection");

    printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    // Receive data from client
    while ((read_size = recv(client_socket_fd, client_message, MAX_BUFFER_SIZE, 0)) > 0) {
        // Process received data to monitor network QoS
        // Example: Calculate the average response time between requests
        // For simplicity, we will just print the client message
        printf("Client message: %s", client_message);

        // Send response back to client
        write(client_socket_fd, client_message, strlen(client_message));
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
    } else if (read_size == -1) {
        die("Failed to receive message");
    }

    // Close sockets
    close(client_socket_fd);
    close(server_socket_fd);

    return 0;
}