//FormAI DATASET v1.0 Category: Socket programming ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8000
#define MAX_BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in server_address;
    char *response = "Hello World! This is a Socket Programming Example!\n";
    char buffer[MAX_BUFFER_SIZE] = {0};

    // Create a socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setting socket options failed!");
        exit(EXIT_FAILURE);
    }

    // Configure the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Binding socket to server address failed!");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listening for incoming connections failed!");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections and handle them
    while (1) {
        printf("Waiting for a client to connect...\n");

        // Accept a connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&server_address, (socklen_t*)&valread)) < 0) {
            perror("Accepting incoming connection failed!");
            exit(EXIT_FAILURE);
        }

        // Read data from the client
        valread = read(new_socket, buffer, MAX_BUFFER_SIZE);
        printf("Received request from the client: %s\n", buffer);

        // Send response to the client
        write(new_socket, response, strlen(response));
        printf("Response sent to the client: %s\n", response);

        // Close the connection
        close(new_socket);
        printf("Connection closed!\n");
    }

    return 0;
}