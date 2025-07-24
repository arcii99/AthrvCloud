//FormAI DATASET v1.0 Category: Networking ; Style: scientific
/* This program demonstrates the basic sockets programming in C for client-server communication. 
   It establishes a connection between a client and server based on IP address and port number. 
   The server accepts a message from the client and sends a response back to the client. 
   This program can be used to exchange data between different computers over a network using sockets programming.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int socket_desc, new_socket, read_size, valread;
    struct sockaddr_in server, client;
    char *message = "Hello from server!";
    char buffer[1024] = {0};

    // Create a socket
    if ((socket_desc = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the socket to the specified IP address and port
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(socket_desc, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    int client_size = sizeof(client);
    if ((new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&client_size)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Read data from client
    valread = read(new_socket, buffer, 1024);
    printf("Client message: %s\n", buffer);

    // Send response to client
    send(new_socket, message, strlen(message), 0);
    printf("Response sent to client\n");

    return 0;
}