//FormAI DATASET v1.0 Category: Chat server ; Style: enthusiastic
// Welcome to the Exciting Chat Server Program!
// You are about to embark on a journey of chatting with people across the internet. 
// Get ready to go beyond chatting and become part of a thriving online community!

#include <stdio.h>      // Standard input/output library
#include <stdlib.h>     // Standard library
#include <string.h>     // String library
#include <unistd.h>     // Universal standard library
#include <netinet/in.h> // Internet address family of protocols
#include <sys/socket.h> // Socket library
#include <arpa/inet.h>  // IP address manipulation library

int main(int argc, char *argv[]) {
    // Initialize variables for server connection
    int opt = 1;
    int server_socket, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Create the server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error! Socket creation failed.");
        exit(EXIT_FAILURE);
    }

    // Set socket options to eliminate address already in use error
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error! Setsockopt failed.");
        exit(EXIT_FAILURE);
    }

    // Assign IP address and port number to socket
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // Bind the socket to server address
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Error! Bind failed.");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Error! Listen failed.");
        exit(EXIT_FAILURE);
    }
   
    printf("Server is up and running. Chat away!\n");

    while (1) {
        // Wait for a new connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Error! Accept failed.");
            exit(EXIT_FAILURE);
        }

        // Send a welcome message to the client
        const char *welcome_message = "Welcome to the chat room!\n";
        send(client_socket, welcome_message, strlen(welcome_message), 0);

        // Receive messages from the client
        while (1) {
            int valread = read(client_socket, buffer, 1024);
            if (valread <= 0) {
                break;
            }
            printf("Client: %s", buffer);

            // If the client types "bye\n", disconnect from the client
            if (strcmp(buffer, "bye\n") == 0) {
                // Send a goodbye message to the client
                const char *goodbye_message = "Goodbye!\n";
                send(client_socket, goodbye_message, strlen(goodbye_message), 0);
                printf("Client disconnected.\n");
                break;
            }
        }
    }

    // Close the socket
    close(server_socket);

    return 0;
}