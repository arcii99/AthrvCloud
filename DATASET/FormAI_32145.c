//FormAI DATASET v1.0 Category: Client Server Application ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_sock, new_sock, valread;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = {0};
    int addrlen = sizeof(server_addr);

    // Create TCP socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server socket options
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to IP address and port
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    puts("Waiting for connections...");

    // Accept incoming connection
    if ((new_sock = accept(server_sock, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    puts("Connection accepted");

    // Read incoming message
    valread = read(new_sock, buffer, 1024);
    printf("Received: %s\n", buffer);

    // Send response
    char* message = "Hello from the server!";
    send(new_sock, message, strlen(message), 0);

    return 0;
}