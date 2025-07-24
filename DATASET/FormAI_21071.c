//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT_NUMBER 9999
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];

    // Create a TCP socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set server address information
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT_NUMBER);

    // Bind the socket to the server address
    if(bind(server_sockfd, (const struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if(listen(server_sockfd, 5) < 0) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT_NUMBER);

    while(1) {
        socklen_t client_address_len = sizeof(client_address);

        // Accept incoming connection
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_address_len);
        if(client_sockfd < 0) {
            perror("Failed to accept incoming connection");
            exit(EXIT_FAILURE);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Read data from client
        ssize_t num_bytes_read = read(client_sockfd, buffer, BUFFER_SIZE);
        if(num_bytes_read < 0) {
            perror("Failed to read data from client");
            exit(EXIT_FAILURE);
        }

        printf("Data received from client: %s\n", buffer);

        // Process data
        char response[BUFFER_SIZE];
        sprintf(response, "Hello %s!", buffer);

        // Send response to client
        ssize_t num_bytes_sent = send(client_sockfd, response, strlen(response), 0);
        if(num_bytes_sent < 0) {
            perror("Failed to send data to client");
            exit(EXIT_FAILURE);
        }

        // Close client socket
        close(client_sockfd);

        printf("Response sent to client: %s\n", response);
    }

    // Close server socket
    close(server_sockfd);

    return 0;
}