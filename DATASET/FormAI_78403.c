//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Dennis Ritchie
/* A simple TCP/IP client-server program */
/* Written in the style of Dennis Ritchie */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {

    int sock_descriptor, new_socket, read_val;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = {0};
    char response[] = "Hello from the server!";

    // Creating the socket
    if ((sock_descriptor = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Setting the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding the socket to the server address
    if (bind(sock_descriptor, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(sock_descriptor, 3) < 0) {
        perror("Error listening");
        exit(EXIT_FAILURE);
    }

    // Accepting incoming connection
    int addr_len = sizeof(client_addr);
    if ((new_socket = accept(sock_descriptor, (struct sockaddr *)&client_addr, (socklen_t*)&addr_len)) < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    // Receiving message from client
    if ((read_val = read(new_socket, buffer, 1024)) < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("Message from client: %s\n", buffer);

    // Sending response to client
    send(new_socket, response, strlen(response), 0);
    printf("Response sent to client: %s\n", response);

    // Closing sockets and exiting
    close(new_socket);
    close(sock_descriptor);
    exit(EXIT_SUCCESS); 
}