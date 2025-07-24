//FormAI DATASET v1.0 Category: Client Server Application ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 256

int main(int argc, char *argv[]) {

    int server_socket, client_socket, port_number;
    socklen_t size_of_client;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        exit(1);
    }

    // Setup the server address
    memset((char*) &server_addr, 0, sizeof(server_addr));
    port_number = 5000;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_number);

    // Bind the server socket
    if (bind(server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding server socket");
        exit(1);
    }

    // Listen for incoming client connections
    listen(server_socket, 5);
    printf("Server is listening on port %d...\n", port_number);

    // Accept client connections
    size_of_client = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr*) &client_addr, &size_of_client);
    if (client_socket < 0) {
        perror("Error accepting client connection");
        exit(1);
    }

    printf("Client connected...\n");

    // Read and write data with client
    while (1) {
        memset(buffer, 0, MAX_BUFFER_SIZE);
        int num_bytes = read(client_socket, buffer, MAX_BUFFER_SIZE);
        if (num_bytes < 0) {
            perror("Error reading data from client");
            exit(1);
        }
        if (num_bytes == 0) {
            printf("Client disconnected\n");
            break;
        }
        printf("Client sent: %s\n", buffer);
        strcat(buffer, " Server received your message");
        num_bytes = write(client_socket, buffer, strlen(buffer));
        if (num_bytes < 0) {
            perror("Error writing data to client");
            exit(1);
        }
    }

    // Close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}