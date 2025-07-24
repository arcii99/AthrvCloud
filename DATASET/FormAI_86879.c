//FormAI DATASET v1.0 Category: Simple Web Server ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char response[BUFFER_SIZE] = {0};
    char *html_data = "<html><head><title>Welcome to the Future</title></head><body><h1>Welcome to the Future!</h1><p>Thank you for connecting to this futuristic web server!</p></body></html>";

    // Create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Futuristic web server is up and listening on port %d...\n", PORT);

    while(1) {
        // Accept a connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Receive request from client
        valread = recv(new_socket, buffer, BUFFER_SIZE, 0);
        printf("Request received from client:\n%s\n", buffer);

        // Generate response
        sprintf(response, "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %ld\nConnection: close\n\n%s", strlen(html_data), html_data);

        // Send response to client
        send(new_socket, response, strlen(response), 0);

        printf("Response sent to client:\n%s\n", response);

        // Close connection
        close(new_socket);
    }

    return 0;
}