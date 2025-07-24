//FormAI DATASET v1.0 Category: Networking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

void error_handler(char *message) {
    perror(message);
    exit(1);
}

int main() {
    int server_socket_fd, client_socket_fd;
    long client_address_length;
    struct sockaddr_in server_address, client_address;
    char buffer[MAX_BUFFER_SIZE] = {0};

    // Create a socket for the server
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        error_handler("Failed to create socket");

    // Initiate the server address
    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(server_socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0)
        error_handler("Failed to bind the socket");

    // Listen for incoming connections
    if (listen(server_socket_fd, 3) < 0)
        error_handler("Failed to listen for incoming connections");

    printf("Server is running on port %d\n", PORT);

    while (1) {
        client_address_length = sizeof(client_address);
        if ((client_socket_fd = accept(server_socket_fd, (struct sockaddr *) &client_address,
                                        (socklen_t *) &client_address_length)) < 0) {
            error_handler("Failed to accept incoming connection");
            continue;
        }

        int pid = fork();

        if (pid < 0) {
            error_handler("Failed to create child process");
            continue;
        }

        if (pid == 0) {
            // Child process
            close(server_socket_fd);

            printf("New client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

            while (1) {
                // Read data from the client
                memset(buffer, 0, MAX_BUFFER_SIZE);
                int bytes_read = read(client_socket_fd, buffer, MAX_BUFFER_SIZE);
                if (bytes_read < 0)
                    error_handler("Failed to read from client");

                if (bytes_read == 0) {
                    printf("Client disconnected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                    break;
                }

                printf("Received message from the client: %s\n", buffer);

                // Send data back to the client
                if (write(client_socket_fd, buffer, strlen(buffer)) < 0)
                    error_handler("Failed to send data back to the client");
            }

            // Close the client socket
            close(client_socket_fd);
            exit(0);
        } else {
            // Parent process
            close(client_socket_fd);
        }
    }

    // Close the server socket
    close(server_socket_fd);
    return 0;
}