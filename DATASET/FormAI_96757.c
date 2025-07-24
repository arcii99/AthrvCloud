//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int server_sock, client_sock, read_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = {0};
    char *response = "Hello from the server!";

    // Create socket file descriptor
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    int opt = 1;
    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Configure server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_sock, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming connections on port %d\n", PORT);

    while (1) {
        socklen_t client_addr_len = sizeof(client_addr);

        // Accept new connection
        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Read data from client
        read_len = recv(client_sock, buffer, 1024, 0);
        printf("Received %d bytes from client: %s\n", read_len, buffer);

        // Send response to client
        if (send(client_sock, response, strlen(response), 0) < 0) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }

        printf("Response sent to client: %s\n", response);

        // Close connection
        close(client_sock);
    }

    return 0;
}