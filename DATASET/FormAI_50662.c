//FormAI DATASET v1.0 Category: Client Server Application ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the port to be used by the server
#define PORT 8888
#define BUFFER_SIZE 1024

// Function to handle client requests
void handle_client_request(int client_socket) {
    char buffer[BUFFER_SIZE];

    // Loop to receive messages from the client
    while (1) {
        // Clear the buffer
        memset(buffer, 0, BUFFER_SIZE);

        // Receive message from the client
        int num_bytes = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (num_bytes == -1) {
            perror("Error receiving data");
            break;
        } else if (num_bytes == 0) {
            printf("Client ended the session\n");
            break;
        }

        // Print the message received from the client
        printf("Received message from client: %s\n", buffer);
        
        // Convert the message to uppercase
        int i;
        for (i = 0; i < num_bytes; i++) {
            buffer[i] = toupper(buffer[i]);
        }

        // Send the modified message back to the client
        if (send(client_socket, buffer, num_bytes, 0) == -1) {
            perror("Error sending data");
            break;
        }
    }

    // Close the client socket
    close(client_socket);
}

int main() {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // Create a server address structure and bind the socket to it
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket to address");
        exit(1);
    }

    // Listen for incoming client requests
    if (listen(server_socket, 5) == -1) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    printf("Server is listening for incoming connections on port %d\n", PORT);

    // Loop to accept incoming client requests
    while (1) {
        // Accept a client connection
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_size);
        if (client_socket == -1) {
            perror("Error accepting incoming connection");
            continue;
        }

        // Print the client information
        printf("Accepted client connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Fork a child process to handle the client request
        pid_t pid = fork();
        if (pid == -1) {
            perror("Error creating child process");
            close(client_socket);
            continue;
        } else if (pid == 0) {
            // This is the child process
            close(server_socket);
            handle_client_request(client_socket);
            exit(0);
        } else {
            // This is the parent process
            close(client_socket);

            // Ignore the child process termination signal
            signal(SIGCHLD, SIG_IGN);
        }
    }

    // Close the server socket
    close(server_socket);

    return 0;
}