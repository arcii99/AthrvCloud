//FormAI DATASET v1.0 Category: Networking ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MESSAGE_BUFFER_SIZE 2000

int main(int argc, char *argv[]) {
    int server_socket, new_socket, read_size;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);
    char client_message[MESSAGE_BUFFER_SIZE];

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    puts("Waiting for incoming connections...");

    while (1) {
        // Accept incoming connection
        new_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (new_socket < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        puts("Client connected");

        // Send a welcome message to the client
        char *welcome_message = "Welcome to the chat server!\n";
        send(new_socket, welcome_message, strlen(welcome_message), 0);

        // Communicate with the client
        while ((read_size = recv(new_socket, client_message, MESSAGE_BUFFER_SIZE, 0)) > 0) {
            // Null terminate the message received from the client
            client_message[read_size] = '\0';

            // Print the message received
            printf("Message received: %s", client_message);

            // Echo the message back to the client
            send(new_socket, client_message, strlen(client_message), 0);
        }

        if (read_size == 0) {
            puts("Client disconnected");
        } else if (read_size == -1) {
            perror("Receive failed");
        }

        // Close the socket
        close(new_socket);
    }

    return 0;
}