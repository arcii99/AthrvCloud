//FormAI DATASET v1.0 Category: Simple Web Server ; Style: thriller
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int port = 8080;
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Socket creation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("setsockopt failed.\n");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    // Bind server socket to IP address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("Bind failed.\n");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        printf("Listen failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", port);

    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            printf("Accept failed.\n");
            exit(EXIT_FAILURE);
        }

        printf("New connection accepted from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        char buffer[30000] = {0};
        valread = read(new_socket, buffer, 30000);

        // Handle request and send response
        if (strstr(buffer, "GET / HTTP/1.1")) {
            write(new_socket, response, strlen(response));
        } else {
            char *response = "HTTP/1.1 404 Not Found\nContent-Type: text/plain\nContent-Length: 9\n\nNot found";
            write(new_socket, response, strlen(response));
        }

        printf("Response sent to %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Close connection
        close(new_socket);
    }

    return 0;
}