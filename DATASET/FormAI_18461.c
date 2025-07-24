//FormAI DATASET v1.0 Category: Simple Web Server ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    // Creating socket file descriptor
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("Oh no, something went wrong with the socket creation!\n");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the port
    int bind_status = bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    if (bind_status < 0) {
        printf("What?! Bind failed?!\n");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    int listen_status = listen(server_fd, 3);
    if (listen_status < 0) {
        printf("No way, we can't listen!\n");
        exit(EXIT_FAILURE);
    }

    printf("YAY! The server is listening on port %d!\n", PORT);

    // Accept incoming connections
    int client_socket;
    struct sockaddr_in client_address;
    int addrlen = sizeof(client_address);
    while ((client_socket = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t*)&addrlen))) {
        printf("Woohoo, we got a connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Read the HTTP request message from the client
        char buffer[1024] = {0};
        read(client_socket, buffer, 1024);
        printf("We received a request from the client:\n%s\n", buffer);

        // Generate a response to the client
        char* message = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello World!</h1></body></html>";
        write(client_socket, message, strlen(message));
        printf("Response sent to the client: %s\n", message);

        // Close the socket
        close(client_socket);
        printf("Connection closed.\n\n");
    }

    return 0;
}