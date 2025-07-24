//FormAI DATASET v1.0 Category: Chat server ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_address;
    int opt = 1;
    int addrlen = sizeof(server_address);
    char buffer[BUFFER_SIZE] = {0};
    char* welcome_message = "Welcome to the chat server!";

    // Create a TCP socket for the server
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Allow multiple connections to the server using the same address
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons( PORT );

    // Bind the server socket to the specified address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections and handle messages from clients
    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&server_address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Send welcome message to client
        send(client_fd, welcome_message, strlen(welcome_message), 0);

        pid_t process_id = fork();
        if (process_id == 0) { // child process
            close(server_fd); // close unused server socket descriptor in child process

            // Read message from client
            int valread = read(client_fd, buffer, BUFFER_SIZE);
            while (valread > 0) {
                printf("Client sent: %s\n", buffer);
                memset(buffer, 0, BUFFER_SIZE); // clear buffer
                valread = read(client_fd, buffer, BUFFER_SIZE);
            }

            // Close client socket descriptor and exit child process
            close(client_fd);
            exit(EXIT_SUCCESS);
        }
        // Parent process continues the loop waiting for new clients
        close(client_fd); // close unused client socket descriptor in parent process
    }

    return 0;
}