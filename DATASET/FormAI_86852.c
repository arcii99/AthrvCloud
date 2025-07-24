//FormAI DATASET v1.0 Category: Simple Web Server ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_REQUEST_SIZE 2048

int main() {
    int server_fd, new_socket;
    long valread;
    struct sockaddr_in address;
    int addr_len = sizeof(address);
    char buffer[MAX_REQUEST_SIZE] = {0};
    char *response = "<html><head><title>Hello, World!</title></head><body><h1>Hello, World!</h1></body></html>";
    int response_length = strlen(response);
    int opt = 1;

    // Create a new socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Allow socket to be reused
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set socket address parameters
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to the specified address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    // Accept incoming connections
    while(1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addr_len))<0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Incoming connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Receive HTTP request
        valread = read(new_socket, buffer, MAX_REQUEST_SIZE);

        printf("Received HTTP request: \"%s\"\n", buffer);

        // Send HTTP response
        write(new_socket, "HTTP/1.1 200 OK\n", 16);
        write(new_socket, "Content-Type: text/html\n", 24);
        char response_length_header[64];
        sprintf(response_length_header, "Content-Length: %d\n", response_length);
        write(new_socket, response_length_header, strlen(response_length_header));
        write(new_socket, "\n", 1);
        write(new_socket, response, response_length);

        // Clean up socket and buffer
        close(new_socket);
        memset(buffer, 0, sizeof(buffer));
    }

    return 0;
}