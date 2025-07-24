//FormAI DATASET v1.0 Category: Simple Web Server ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 8888
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_fd, client_fd, opt = 1;
    struct sockaddr_in server_address;
    int address_length = sizeof(server_address);

    // Create a socket for the server
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set address fields
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections and handle requests
    while (1) {
        printf("Waiting for incoming connections...\n");

        if ((client_fd = accept(server_fd, (struct sockaddr *)&server_address, (socklen_t *)&address_length)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Read client request
        char buffer[BUFFER_SIZE] = {0};
        int bytes_read = read(client_fd, buffer, BUFFER_SIZE);
        printf("%s\n", buffer);

        // Send response
        char *message = "HTTP/1.1 200 OK\n\nHello, World!";
        write(client_fd, message, strlen(message));

        // Close connection
        close(client_fd);
        printf("Connection closed\n");
    }

    return 0;
}