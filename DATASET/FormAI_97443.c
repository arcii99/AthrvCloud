//FormAI DATASET v1.0 Category: Simple Web Server ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080 // Port to listen on
#define MAX_REQUEST_SIZE 2048 // Maximum size of a request

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_REQUEST_SIZE] = {0};
    char response[] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\nHello, World!";

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket to allow multiple connections
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections and respond with "Hello, World!"
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            continue;
        }

        valread = read(new_socket, buffer, MAX_REQUEST_SIZE);

        // Print the request for debugging purposes
        printf("%s\n", buffer);

        // Send a response
        send(new_socket, response, strlen(response), 0);

        // Close the socket after sending the response
        close(new_socket);
    }

    return 0;
}