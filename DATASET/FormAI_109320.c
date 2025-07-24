//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PROXY_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    // Check if the user has provided the correct number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <destination ip address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket for the proxy server
    int proxy_server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (proxy_server_socket < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a port and IP address
    struct sockaddr_in proxy_server_address;
    bzero((char *) &proxy_server_address, sizeof(proxy_server_address));
    proxy_server_address.sin_family = AF_INET;
    proxy_server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_server_address.sin_port = htons(PROXY_PORT);

    if (bind(proxy_server_socket, (struct sockaddr *) &proxy_server_address, sizeof(proxy_server_address)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Set the socket to listen for incoming connections
    if (listen(proxy_server_socket, 1) < 0) {
        perror("Failed to listen on socket");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections and create a new socket for each one
    struct sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);
    int client_socket = accept(proxy_server_socket, (struct sockaddr *) &client_address, &client_address_length);

    if (client_socket < 0) {
        perror("Failed to accept client connection");
        exit(EXIT_FAILURE);
    }

    // Display the incoming request from the client
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    read(client_socket, buffer, BUFFER_SIZE);
    printf("Received request from client:\n%s", buffer);

    // Extract the requested URL from the client's request
    char *requested_url = strchr(buffer, ' ') + 1;
    char *end_requested_url = strchr(requested_url, ' ');

    if (end_requested_url == NULL) {
        perror("Invalid request from client");
        exit(EXIT_FAILURE);
    }

    *end_requested_url = '\0';

    // Connect to the destination server using a new socket
    char *destination_ip_address = argv[1];
    int destination_port = 80;

    int destination_server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (destination_server_socket < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in destination_server_address;
    bzero((char *) &destination_server_address, sizeof(destination_server_address));
    destination_server_address.sin_family = AF_INET;
    destination_server_address.sin_addr.s_addr = inet_addr(destination_ip_address);
    destination_server_address.sin_port = htons(destination_port);

    if (connect(destination_server_socket, (struct sockaddr *) &destination_server_address, sizeof(destination_server_address)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    // Send the client's request to the destination server
    if (write(destination_server_socket, buffer, strlen(buffer)) < 0) {
        perror("Failed to send request to destination server");
        exit(EXIT_FAILURE);
    }

    // Forward the response from the destination server back to the client
    int bytes_read = 0;
    while ((bytes_read = read(destination_server_socket, buffer, BUFFER_SIZE)) > 0) {
        if (write(client_socket, buffer, bytes_read) < 0) {
            perror("Failed to forward response to client");
            exit(EXIT_FAILURE);
        }
    }

    // Close both sockets and exit the program
    close(client_socket);
    close(destination_server_socket);
    exit(EXIT_SUCCESS);
}