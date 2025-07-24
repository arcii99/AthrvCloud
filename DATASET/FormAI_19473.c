//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_socket, new_socket, read_value;
    struct sockaddr_in server_address, client_address;
    int addrlen = sizeof(server_address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the given IP and port
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen on the socket with a maximum queue of 3 pending connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept any incoming connection
    if ((new_socket = accept(server_socket, (struct sockaddr *) &client_address, (socklen_t *) &addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Convert the client IP address to a string
    char *client_ip = inet_ntoa(client_address.sin_addr);
    printf("Connection accepted from %s\n", client_ip);

    // Send a hello message to the client
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    // Receive data from the client
    read_value = read(new_socket, buffer, 1024);
    printf("%s\n", buffer);

    // Close the sockets
    close(new_socket);
    close(server_socket);

    return 0;
}