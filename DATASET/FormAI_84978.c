//FormAI DATASET v1.0 Category: Simple Web Server ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the size of our buffer
#define BUFFER_SIZE 1024

// Define the port that the server listens on
#define PORT 8080

int main()
{
    int server_socket, client_socket;
    int opt = 1;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE] = {0};
    int read_result;

    // Create the server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error: Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address and port
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error: Could not set socket options");
        exit(EXIT_FAILURE);
    }

    // Set server address struct properties
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error: Could not bind socket to address");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Error: Could not listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    unsigned int client_address_len = sizeof(client_address);
    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len)) < 0) {
        perror("Error: Could not accept incoming connection");
        exit(EXIT_FAILURE);
    }

    // Read from the client socket
    read_result = read(client_socket, buffer, BUFFER_SIZE);

    // Write the response back to the client
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello World!</h1></body></html>";
    write(client_socket, response, strlen(response));

    // Close the client and server sockets
    close(client_socket);
    close(server_socket);

    return 0;
}