//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *welcome_message = "Welcome to my server!";

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the specified address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New connection from: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Send a welcome message to the client
        send(new_socket, welcome_message, strlen(welcome_message), 0);

        // Handle the client's requests
        while (1) {
            // Receive message from the client
            int valread = read(new_socket, buffer, 1024);

            // Handle errors
            if (valread == 0) {
                printf("Connection closed by the client\n");
                break;
            } else if (valread < 0) {
                perror("read failed");
                exit(EXIT_FAILURE);
            }

            // Print the message received from the client
            printf("Received message: %s\n", buffer);

            // Send a response to the client
            char response[1024] = {0};
            sprintf(response, "You sent: %s", buffer);
            send(new_socket, response, strlen(response), 0);

            // Clear the buffer
            memset(buffer, 0, 1024);
        }

        // Close the connection
        close(new_socket);
    }

    return 0;
}