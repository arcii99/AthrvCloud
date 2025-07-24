//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888
#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    // Create a socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options: reuse address and port
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind the server socket to a specific IP and port
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections and handle them
    struct sockaddr_in client_address;
    int addrlen = sizeof(client_address);

    while (1) {
        int client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&addrlen);
        if (client_fd < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Handle the incoming connection on a new process
        if (fork() == 0) {
            close(server_fd);

            while (1) {
                char buffer[BUFFER_SIZE] = {0};
                int bytes_read = read(client_fd, buffer, BUFFER_SIZE);
                if (bytes_read < 0) {
                    perror("Read failed");
                    exit(EXIT_FAILURE);
                }

                if (bytes_read == 0) {
                    printf("Client disconnected\n");
                    break;
                }

                printf("Received message: %s\n", buffer);

                // Send a response back to the client
                char response[] = "Hello from server\n";
                if (send(client_fd, response, strlen(response), 0) < 0) {
                    perror("Send failed");
                    exit(EXIT_FAILURE);
                }
            }

            close(client_fd);
            exit(EXIT_SUCCESS);
        } else {
            close(client_fd);
        }
    }

    return 0;
}