//FormAI DATASET v1.0 Category: Client Server Application ; Style: detailed
/* This is a sample C Client-Server Application that creates a simple chat program */

// Include necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> // for data types
#include <sys/socket.h> // for socket operations
#include <netinet/in.h> // for internet functions
#include <string.h>
#include <unistd.h>

// Define port number
#define PORT 3000

// Define maximum message size
#define MAX_MSG_SIZE 1024

// Define client socket
int client_socket;

// Define function for sending messages to server
void send_message(char *message) {
    int message_size = strlen(message);
    send(client_socket, message, message_size, 0);
}

// Define function for receiving messages from server
void receive_message() {
    char message[MAX_MSG_SIZE];
    recv(client_socket, message, MAX_MSG_SIZE, 0);
    printf("Server: %s", message);
}

int main() {
    // Create socket variable
    int server_socket, client_socket;

    // Create variable for storing incoming message from client
    char message_from_client[MAX_MSG_SIZE];

    // Create internet address structure
    struct sockaddr_in server_address, client_address;

    // Create socket using socket() system call
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Check if socket creation failed
    if (server_socket < 0) {
        perror("Error creating socket\n");
        exit(1);
    }

    // Clear server_address structure
    bzero((char *) &server_address, sizeof(server_address));

    // Assign IP address and port number to server_address structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to IP address and port number using bind() system call
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket to IP address and port number\n");
        exit(1);
    }

    // Listen for incoming connection requests using listen() system call
    listen(server_socket, 1);

    printf("Server is running and listening on port %d...\n", PORT);

    // Accept incoming connection request using accept() system call
    socklen_t client_address_length = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);

    // Check if accept() system call failed
    if (client_socket < 0) {
        perror("Error accepting connection request\n");
        exit(1);
    }

    printf("Connection request accepted from client at address %s and port %d\n",
            inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    // Loop to continue chat between client and server
    while(1) {
        printf("Enter message: ");
        fgets(message_from_client, MAX_MSG_SIZE, stdin);

        send_message(message_from_client);
        receive_message();
    }

    // Close client and server sockets
    close(client_socket);
    close(server_socket);

    return 0;
}