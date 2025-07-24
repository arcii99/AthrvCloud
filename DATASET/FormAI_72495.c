//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *welcome = "Welcome to the TCP/IP server!\n";
    char *prompt = ">> ";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set address information
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the given port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d\n", PORT);

    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Client connected\n");
        send(new_socket, welcome, strlen(welcome), 0);

        while (1) {
            send(new_socket, prompt, strlen(prompt), 0);

            // Read command from client
            valread = read(new_socket, buffer, 1024);

            // Handle client disconnect
            if (valread == 0) {
                printf("Client disconnected\n");
                close(new_socket);
                break;
            }

            // Handle command
            if (strncmp(buffer, "quit", 4) == 0) {
                printf("Client requested to quit\n");
                close(new_socket);
                break;
            } else {
                printf("Client input: %s\n", buffer);
                send(new_socket, buffer, strlen(buffer), 0);
            }

            memset(buffer, 0, sizeof(buffer));
        }
    }

    return 0;
}