//FormAI DATASET v1.0 Category: Simple Web Server ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFF_SIZE 1024

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFF_SIZE] = {0};
    char response[BUFF_SIZE] = {0};
    char *html = "<html><head><title>Simple Web Server</title></head><body><h1>Hello from the Simple Web Server!</h1></body></html>";

    // Create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a specific IP address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Simple Web Server is listening on port %d...\n", PORT);

    // Handle incoming connections
    while (1) {
        // Accept the incoming connection request
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Read the incoming request from the client
        valread = read(new_socket, buffer, BUFF_SIZE);
        printf("%s\n", buffer);

        // Send the HTTP response to the client
        snprintf(response, BUFF_SIZE, "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %ld\n\n%s", strlen(html), html);
        send(new_socket, response, strlen(response), 0);
        printf("HTTP response sent.\n");

        // Close the connection
        close(new_socket);
    }

    return 0;
}