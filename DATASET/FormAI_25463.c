//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(int argc, char *argv[]) {
    // Create a socket for IPv4 TCP connection
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address and port
    int option = true;
    if(setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option)) < 0) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    // Initialize server address struct
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to server address
    if(bind(socket_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket to address");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if(listen(socket_fd, 5) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming connections...\n");

    // Accept incoming connections and handle requests
    struct sockaddr_in client_address;
    int client_socket_fd, addr_len = sizeof(client_address);
    char buffer[BUFFER_SIZE];
    while(true) {
        // Accept incoming connection
        if((client_socket_fd = accept(socket_fd, (struct sockaddr*) &client_address, (socklen_t*) &addr_len)) < 0) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        printf("Received connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Read request from client
        memset(buffer, 0, BUFFER_SIZE);
        if(read(client_socket_fd, buffer, BUFFER_SIZE) < 0) {
            perror("Error reading from socket");
            exit(EXIT_FAILURE);
        }

        printf("Received request: %s", buffer);

        // Send response to client
        if(write(client_socket_fd, "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 12\r\n\r\nHello World!", 77) < 0) {
            perror("Error writing to socket");
            exit(EXIT_FAILURE);
        }

        printf("Sent response: HTTP/1.1 200 OK\\r\\nContent-Type: text/plain\\r\\nContent-Length: 12\\r\\n\\r\\nHello World!");

        // Close client socket
        close(client_socket_fd);
    }

    // Close server socket
    close(socket_fd);

    return 0;
}