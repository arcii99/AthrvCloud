//FormAI DATASET v1.0 Category: Networking ; Style: expert-level
// TCP/IP server-client implementation
// The client sends a string to the server, which converts it to uppercase
// The server then sends the uppercase string back to the client
// Expert-level implementation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error(char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("Socket creation failed");
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        error("Setsockopt failed");
    }

    // Bind the socket to a specific port and address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        error("Bind failed");
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        error("Listen failed");
    }

    // Accept an incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
        error("Accept failed");
    }

    // Read the incoming message from the client
    valread = read(new_socket, buffer, BUFFER_SIZE);
    if(valread < 0) {
        error("Read failed");
    }
    printf("Received message from client: %s\n", buffer);

    // Convert the message to uppercase
    for(int i = 0; i < valread; i++) {
        buffer[i] = toupper(buffer[i]);
    }

    // Send the uppercase message back to the client
    if(send(new_socket, buffer, BUFFER_SIZE, 0) < 0) {
        error("Send failed");
    }
    printf("Sent message to client: %s\n", buffer);

    // Close the socket
    close(new_socket);

    return 0;
}