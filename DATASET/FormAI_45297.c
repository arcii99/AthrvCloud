//FormAI DATASET v1.0 Category: Simple Web Server ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define DEFAULT_PORT 8080

int main(int argc, char *argv[]) {

    int server_sockfd, client_sockfd;
    char buffer[BUFF_SIZE];
    struct sockaddr_in server_address, client_address;
    socklen_t client_len = sizeof(client_address);

    // Create a socket
    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    // Set the server information
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(DEFAULT_PORT);

    // Bind the socket to the server address
    if (bind(server_sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Error: Failed to bind socket\n");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_sockfd, 5) == -1) {
        printf("Error: Failed to listen for incoming connections\n");
        exit(1);
    }

    // Accept incoming connections
    if ((client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len)) == -1) {
        printf("Error: Failed to accept connection\n");
        exit(1);
    }

    // Read request from client
    int received_bytes = recv(client_sockfd, buffer, BUFF_SIZE, 0);
    if (received_bytes == -1) {
        printf("Error: Failed to receive request from client\n");
        exit(1);
    }

    // Print request message
    printf("Received Request:\n%s", buffer);

    // Send response to client
    const char *response_message = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";
    int sent_bytes = send(client_sockfd, response_message, strlen(response_message), 0);
    if (sent_bytes == -1) {
        printf("Error: Failed to send response to client\n");
        exit(1);
    }

    // Close the sockets
    close(client_sockfd);
    close(server_sockfd);

    return 0;
}