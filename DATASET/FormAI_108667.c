//FormAI DATASET v1.0 Category: Simple Web Server ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv) {

    // Create a socket for the server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Create a sockaddr_in struct for the server address and set the IP and port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the server socket to the server address
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    // Accept and handle incoming connections
    while (1) {
        struct sockaddr_in client_address;
        int client_socket = accept(server_socket, (struct sockaddr*) &client_address, (socklen_t*) sizeof(client_address));

        // Read the HTTP request from the client
        char request[2048];
        memset(request, 0, sizeof(request));
        read(client_socket, request, sizeof(request));

        // Send an HTTP response back to the client
        char response[2048] = "HTTP/1.1 200 OK\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>";
        write(client_socket, response, sizeof(response));

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}