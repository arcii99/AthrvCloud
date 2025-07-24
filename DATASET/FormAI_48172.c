//FormAI DATASET v1.0 Category: Simple Web Server ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

    int PORT_NUMBER = 8080;

    int server_fd, client_fd;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    socklen_t client_address_size;

    // Setup the server address
    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT_NUMBER);

    // Create the TCP socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Error: Cannot create socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the server address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error: Cannot bind socket to address");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 10) < 0) {
        perror("Error: Cannot listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server running on port %d\n", PORT_NUMBER);

    while (1) {
        // Accept incoming connections
        client_address_size = sizeof(client_address);
        client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_size);
        if (client_fd < 0) {
            perror("Error: Cannot accept incoming connection");
            continue;
        }

        // Read HTTP request
        char request_buffer[1024] = {0};
        read(client_fd, request_buffer, 1024);
        printf("%s\n", request_buffer);  // Print the complete HTTP request to console

        // Serve simple text response
        char *response = "HTTP/1.1 200 OK\r\nContent-Length: 11\r\nContent-Type: text/plain\r\nConnection: Closed\r\n\r\nHello World";
        write(client_fd, response, strlen(response));

        // Close the connection
        close(client_fd);
    }

    // Close the server socket
    close(server_fd);

    return 0;
}