//FormAI DATASET v1.0 Category: Socket programming ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to handle client connections
void handle_client(int client_socket) {
    char* message = "Hello, client!";
    int message_length = strlen(message);

    // Send message to client
    int bytes_sent = send(client_socket, message, message_length, 0);
    if (bytes_sent == -1) {
        perror("Failed to send message to client");
        return;
    }
    printf("Sent message to client: %s\n", message);
}

int main() {
    int server_socket, new_client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create socket");
        return EXIT_FAILURE;
    }

    // Set socket options
    int option = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) == -1) {
        perror("Failed to set socket options");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Bind socket to address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(9000);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Failed to bind socket to address");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Listen for client connections
    if (listen(server_socket, 5) == -1) {
        perror("Failed to listen for client connections");
        close(server_socket);
        return EXIT_FAILURE;
    }
    printf("Server listening for client connections on port %d\n", ntohs(server_address.sin_port));

    // Accept client connections
    while (1) {
        client_address_length = sizeof(client_address);
        new_client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (new_client_socket == -1) {
            perror("Failed to accept client connection");
            close(server_socket);
            return EXIT_FAILURE;
        }

        // Convert client IP address to string
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(client_address.sin_addr), client_ip, INET_ADDRSTRLEN);
        printf("Accepted client connection from %s:%d\n", client_ip, ntohs(client_address.sin_port));

        // Handle client connection in a separate process
        pid_t process_id = fork();
        if (process_id == -1) {
            perror("Failed to fork process");
        } else if (process_id == 0) {
            // Child process
            close(server_socket);
            handle_client(new_client_socket);
            close(new_client_socket);
            return EXIT_SUCCESS;
        } else {
            // Parent process
            close(new_client_socket);
        }
    }

    // Close server socket
    close(server_socket);

    return EXIT_SUCCESS;
}