//FormAI DATASET v1.0 Category: Chat server ; Style: careful
#include <stdio.h>      // For input/output functions
#include <stdlib.h>     // For exit() function
#include <string.h>     // For string handling functions
#include <sys/socket.h> // For socket() function
#include <netinet/in.h> // For sockaddr_in structure
#include <unistd.h>     // For close() function

#define PORT 8080       // Port to listen on

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Create a TCP socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options for the socket
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set up the address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening on the socket
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Wait for incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Handle requests from the client
    while (1) {
        valread = read(new_socket, buffer, 1024);
        if (valread <= 0) break; // Error or connection terminated
        printf("Received message: %s\n", buffer);

        // Echo the message back to the client
        send(new_socket, buffer, strlen(buffer), 0);
    }

    // Close the socket
    close(server_fd);
    return 0;
}