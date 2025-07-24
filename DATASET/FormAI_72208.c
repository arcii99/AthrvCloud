//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int client_socket, port_number, bytes_received;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_address;
    socklen_t addr_length;

    // Initialize socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket initialization failed");
        exit(EXIT_FAILURE);
    }

    // Clear out the struct
    memset(&server_address, 0, sizeof(server_address));

    // Set server address information
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);

    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) < 0) {
        perror("Address conversion error");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server!\n");

    while(1) {
        // Clear out buffer before each iteration
        memset(buffer, 0, BUFFER_SIZE);

        // Send message to server
        printf("\nEnter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(client_socket, buffer, strlen(buffer), 0);

        // Check if "exit" command has been sent
        if (strncmp("exit", buffer, 4) == 0)
            break;

        // Receive response from server
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received < 0) {
            perror("Error receiving response from server");
            break;
        }

        // Print server's response
        printf("Server: %s\n", buffer);
    }

    // Close socket
    close(client_socket);

    return 0;
}