//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Alan Touring
// Welcome to a unique TCP/IP programming example program! 

// Let's start by including the necessary headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// We will define some constants here
#define BUFFER_SIZE 1024
#define PORT_NUMBER 8080

// Now we will define a function that will handle our client requests
void handle_request(int socket) {
    // First, we will create a buffer to store our incoming message
    char buffer[BUFFER_SIZE] = {0};

    // Then, we will read the message from the client
    int bytes_read = read(socket, buffer, BUFFER_SIZE);

    // If we read nothing or an error occurred, we will send an error message back to the client and exit
    if (bytes_read == 0 || bytes_read == -1) {
        char* error_message = "Error: Could not read message\n";
        send(socket, error_message, strlen(error_message), 0);
        return;
    }
    
    // Otherwise, let's print the message to the console
    printf("Received message: %s", buffer);

    // Finally, let's send a response back to the client
    char* response_message = "Message Received!\n";
    send(socket, response_message, strlen(response_message), 0);
}

int main(int argc, char const *argv[]) {
    printf("Starting TCP/IP server...\n");

    // First, we will create our socket using the TCP protocol
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Then, we will define our server address and port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT_NUMBER);

    // Next, we will bind our socket to the server address and port
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    // Finally, we will start listening on the socket
    listen(server_socket, 5);

    printf("Server listening on port %d...\n", PORT_NUMBER);

    // Now we will start accepting client requests
    while (1) {
        // First, let's accept a client connection
        int client_socket = accept(server_socket, NULL, NULL);

        // Then, let's handle the client request
        handle_request(client_socket);

        // Finally, let's close the client socket
        close(client_socket);
    }

    // Don't forget to close the server socket when the program exits!
    close(server_socket);

    return 0;
}