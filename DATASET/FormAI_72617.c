//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Ada Lovelace
// This is a simple web server program written in C, inspired by the great Ada Lovelace
// It listens for incoming HTTP requests and returns a basic HTML response

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char *html_response = "<html><head><title>Ada's Web Server</title></head><body><h1>Hello from Ada's Web Server!</h1></body></html>";

    // Create a TCP socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to allow reuse of address and port
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Configure address and port of server
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the specified address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Ada's Web Server is listening on port %d...\n", PORT);

    while(1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Incoming request from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Return a basic HTML response to the client
        send(new_socket, html_response, strlen(html_response), 0);
        printf("Response sent!\n");

        // Close the connection
        close(new_socket);
    }

    return 0;
}