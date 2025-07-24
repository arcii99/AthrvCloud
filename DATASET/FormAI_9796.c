//FormAI DATASET v1.0 Category: Client Server Application ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int socket_fd, new_socket, client_len;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE] = {0};
  
    // Create socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address parameters
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the specified address and port number
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(socket_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // Accept new connections
        client_len = sizeof(client_address);
        if ((new_socket = accept(socket_fd, (struct sockaddr *)&client_address, (socklen_t *)&client_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Read client message asynchronously
        int pid = fork();
        if (pid == 0) {
            close(socket_fd);
            memset(buffer, 0, sizeof(buffer));
            while (read(new_socket, buffer, BUFFER_SIZE)) {
                // Do something asynchronously with the received data
                printf("Received client message: %s\n", buffer);
                memset(buffer, 0, sizeof(buffer));
            }
            exit(EXIT_SUCCESS);
        }
        else if (pid < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }

        // Close the socket connection with the client
        close(new_socket);
    }
  
    return 0;
}