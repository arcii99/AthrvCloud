//FormAI DATASET v1.0 Category: Client Server Application ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888
#define BUFF_SIZE 2048

int main() {
    int server_fd, new_socket, val_read;
    struct sockaddr_in server_address;
    char buffer[BUFF_SIZE] = {0};
    char *message = "Hey Client! Let's chat.\n";
    int address_len = sizeof(server_address);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set server attributes
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 2) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&server_address, (socklen_t*)&address_len)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Send welcome message to client
    send(new_socket, message, strlen(message), 0);

    // Start chat loop
    while (1) {
        // Read incoming message
        val_read = read(new_socket, buffer, BUFF_SIZE);
        printf("Client: %s", buffer);
        // If message is "bye", close connection
        if (strcmp(buffer, "bye\n") == 0) {
            close(new_socket);
            break;
        }
        // Ask for response and send it back to client
        printf("You: ");
        fgets(buffer, BUFF_SIZE, stdin);
        send(new_socket, buffer, strlen(buffer), 0);
    }
    return 0;
}