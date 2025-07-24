//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888
#define BUFFER_SIZE 1024

int main() {
    int server_fd;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE] = {0};
    
    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server address and port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(PORT);

    // Bind server socket to address and port
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d\n", PORT);

    while (1) {
        int client_fd;
        int client_address_size;
        int bytes_received;
        
        client_address_size = sizeof(client_address);

        // Wait for a client to connect
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t*)&client_address_size)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Receive data from client
        bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);

        printf("Received %d bytes from client: %s\n", bytes_received, buffer);

        // Process data
        char response[BUFFER_SIZE] = "Hello, ";
        strcat(response, buffer);
        
        // Send response to client
        send(client_fd, response, strlen(response), 0);

        printf("Sent %ld bytes to client: %s\n", strlen(response), response);

        // Close connection to client
        close(client_fd);
    }

    // Close server socket
    close(server_fd);

    return 0;
}