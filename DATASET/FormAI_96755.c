//FormAI DATASET v1.0 Category: Client Server Application ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

// Function to handle client connections
void handle_client(int client_socket) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    char *message = "Welcome to the server!\n";
    send(client_socket, message, strlen(message), 0);

    while (recv(client_socket, buffer, sizeof(buffer), 0) > 0) {
        printf("Received: %s", buffer);
        send(client_socket, buffer, strlen(buffer), 0);
        memset(buffer, 0, sizeof(buffer));
    }
}

int main() {
    struct sockaddr_in server_addr, client_addr;
    int server_socket, client_socket, addr_size, i;

    // Create socket
    server_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_socket < 0) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    // Set server address parameters
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9000);
    server_addr.sin_addr.s_addr = inet_addr("0.0.0.0");

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Could not bind socket to address\n");
        return 1;
    }

    // Listen for client connections
    if (listen(server_socket, 5) < 0) {
        printf("Error: Could not listen for incoming connections\n");
        return 1;
    }

    printf("Server started. Listening on port 9000...\n");

    // Handle incoming client connections
    while (1) {
        addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addr_size);
        if (client_socket < 0) {
            printf("Error: Could not establish connection with client\n");
            continue;
        }

        printf("Client connected at %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        handle_client(client_socket);
        close(client_socket);
        printf("Client connection closed\n");
    }

    close(server_socket);
    return 0;
}