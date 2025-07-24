//FormAI DATASET v1.0 Category: Networking ; Style: energetic
// Let's create a program that mimics a real-time chat application!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFSIZE 1024

int main() {
    char server_message[BUFSIZE] = "Welcome to our chatroom!\n";
    char client_message[BUFSIZE];
    
    // Create the socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Define server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to our specified IP and port
    bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    // Listen for connections (maximum of 5)
    listen(server_socket, 5);

    // Define client variables
    int client_socket;
    struct sockaddr_in client_address;
    socklen_t client_address_len;

    printf("Waiting for a client to connect...\n");

    // Accept a client connection
    client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_len);

    printf("Client connected!\n");

    // Start the chat
    while (1) {
        // Server sends message
        send(client_socket, server_message, strlen(server_message), 0);

        // Check if the client wants to exit
        if (recv(client_socket, client_message, BUFSIZE, 0) == 0)
            break;

        // Print the client's message
        printf("Client: %s", client_message);

        // Server inputs a message
        printf("Server: ");
        fgets(server_message, BUFSIZE, stdin);

        // Check if the server wants to exit
        if (strcmp(server_message, "exit\n") == 0)
            break;
    }

    // Close the sockets
    close(client_socket);
    close(server_socket);

    return 0;
}