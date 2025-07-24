//FormAI DATASET v1.0 Category: Networking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 5
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    // Create a socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a specific IP and port
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET; // IPv4
    address.sin_addr.s_addr = INADDR_ANY; // Bind to any available interface
    address.sin_port = htons(8080); // Bind to port 8080
    int addrlen = sizeof(address);
    if (bind(server_fd, (struct sockaddr *)&address, addrlen) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Wait for incoming connections and handle them
    while (1) {
        int client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        if (client_fd < 0) {
            perror("Accept failed");
            continue;
        }

        // Remove this line to enable concurrency
        sleep(1);

        char buffer[BUF_SIZE] = {0};
        int read_val = read(client_fd, buffer, BUF_SIZE);
        if (read_val < 0) {
            perror("Read failed");
            exit(EXIT_FAILURE);
        }

        // Add your own data processing logic here

        char response[BUF_SIZE] = "Hello from the server!";
        send(client_fd, response, strlen(response), 0);
        close(client_fd);
    }

    return 0;
}