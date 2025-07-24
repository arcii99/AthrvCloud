//FormAI DATASET v1.0 Category: Chat server ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000
#define MAX_CLIENTS 10

int main(int argc, char *argv[]) {
    int server_socket, client_socket, opt = 1;
    struct sockaddr_in server_address, client_address;
    char buffer[1024] = {0};
    int address_len = sizeof(server_address);

    // Create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Failed to create server socket\n");
        return -1;
    }

    // Set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Failed to set socket options\n");
        return -1;
    }

    // Bind socket to address/port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Failed to bind server socket\n");
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        printf("Failed to listen for incoming connections\n");
        return -1;
    }
    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connections
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&address_len)) < 0) {
            printf("Failed to accept incoming connection\n");
            return -1;
        }

        // Print client information
        printf("New client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Read incoming data
        while (1) {
            int valread = read(client_socket, buffer, 1024);
            if (valread <= 0) {
                // Connection closed
                close(client_socket);
                printf("Client disconnected\n");
                break;
            }
            printf("%s", buffer);

            // Echo incoming data back to client
            send(client_socket, buffer, strlen(buffer), 0);
            memset(buffer, 0, sizeof(buffer));
        }
    }

    return 0;
}