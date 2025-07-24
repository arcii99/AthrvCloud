//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock_fd, client_fd, addr_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare server address
    memset(&server_addr, '0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock_fd, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        // Accept client connection
        addr_len = sizeof(client_addr);
        if ((client_fd = accept(sock_fd, (struct sockaddr *) &client_addr, &addr_len)) < 0) {
            perror("Client connection acceptance failed");
            exit(EXIT_FAILURE);
        }

        // Print client's IP address
        printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));

        // Read from client
        int num_bytes = read(client_fd, buffer, BUFFER_SIZE);
        buffer[num_bytes] = '\0';
        printf("Received message from %s: %s", inet_ntoa(client_addr.sin_addr), buffer);

        // Reply to client
        char *msg = "Hi client! I received your message :)";
        write(client_fd, msg, strlen(msg));

        // Close client connection
        close(client_fd);
    }

    return 0;
}