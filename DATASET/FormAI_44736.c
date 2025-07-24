//FormAI DATASET v1.0 Category: Chat server ; Style: retro
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
    int opt = 1;
    int addrlen = sizeof(address);
    char retro[256] = "Welcome to the Retro Chat!\n";

    // Create the socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set the socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Socket options failed");
        exit(EXIT_FAILURE);
    }

    // Set the address family, IP address and port number
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Server listening failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections and handle requests
    while (1) {
        
        // Accept incoming connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Connection accept failed");
            exit(EXIT_FAILURE);
        }

        // Send the welcome message to the client
        send(new_socket, retro, strlen(retro), 0);

        // Read incoming data from the client
        char buffer[1024] = {0};
        int valread = read(new_socket, buffer, 1024);

        // Handle the client's request
        if (strcmp(buffer, "quit\n") == 0) {
            char message[256] = "Goodbye from Retro Chat!\n";
            send(new_socket, message, strlen(message), 0);
            close(new_socket);
            break;
        } else {
            char message[256];
            snprintf(message, 256, "You said: %s", buffer);
            send(new_socket, message, strlen(message), 0);
        }       
    }

    // Close the server socket
    close(server_fd);

    return 0;
}