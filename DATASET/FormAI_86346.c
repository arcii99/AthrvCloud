//FormAI DATASET v1.0 Category: Socket programming ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int socket_fd, address_len, val_read;
    struct sockaddr_in address;
    char buffer[1024] = {0};
    const char *hello = "Hello from server!";

    // Create socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Set address information
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the specified address
    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        return 1;
    }

    // Listen for incoming connections
    if (listen(socket_fd, 3) < 0) {
        perror("Listen failed");
        return 1;
    }

    printf("Listening on port %d\n", PORT);

    // Accept incoming connections and handle them individually
    while(1) {
        int client_socket_fd;
        if ((client_socket_fd = accept(socket_fd, (struct sockaddr *)&address, (socklen_t*)&address_len)) < 0) {
            perror("Accept failed");
            return 1;
        }
        printf("Connection accepted from IP address %s and port %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Handle communication with the client
        while(1) {
            // Receive data from the client
            val_read = read(client_socket_fd, buffer, 1024);
            if (val_read == 0) {
                printf("Connection closed by client\n");
                close(client_socket_fd);
                break;
            } else if (val_read < 0) {
                perror("Read failed");
                close(client_socket_fd);
                break;
            } else {
                printf("Received %d bytes: %s\n", val_read, buffer);

                // Send a response back to the client
                send(client_socket_fd, hello, strlen(hello), 0);
            }
            memset(buffer, 0, sizeof(buffer));
        }
    }

    return 0;
}