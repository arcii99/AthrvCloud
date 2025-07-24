//FormAI DATASET v1.0 Category: Socket programming ; Style: portable
/**
 * This program demonstrates a simple socket server that accepts client connections
 * and sends them a welcome message. The server uses the TCP protocol and ports 9000-9009.
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 9000
#define MAX_MSG_LENGTH 1024
#define NUM_PORTS 10

int main() {
    int server_sock, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char welcome_message[] = "Welcome to the Socket Server!";
    char client_message[MAX_MSG_LENGTH];

    // Create an array of port numbers to use
    int ports[NUM_PORTS];
    for(int i = 0; i < NUM_PORTS; i++) {
        ports[i] = PORT + i;
    }

    // Create a socket for each port and start listening for connections
    for(int i = 0; i < NUM_PORTS; i++) {
        // Create socket
        server_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sock == -1) {
            perror("Failed to create socket");
            exit(1);
        }

        // Set socket options
        int opt = 1;
        if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
            perror("Failed to set socket options");
            exit(1);
        }

        // Prepare the sockaddr_in structure
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = INADDR_ANY;
        server.sin_port = htons(ports[i]);

        // Bind the socket to the port
        if (bind(server_sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
            perror("Failed to bind socket to port");
            exit(1);
        }

        // Listen for connections
        listen(server_sock, 3);
        printf("Socket server listening on port %d\n", ports[i]);

        // Accept incoming connections
        c = sizeof(struct sockaddr_in);
        client_sock = accept(server_sock, (struct sockaddr *)&client, (socklen_t*)&c);
        if (client_sock < 0) {
            perror("Failed to accept incoming connection");
            exit(1);
        }

        // Send the welcome message to the client
        if (send(client_sock, welcome_message, strlen(welcome_message), 0) != strlen(welcome_message)) {
            perror("Failed to send welcome message");
            exit(1);
        }

        // Receive messages from the client until they disconnect
        while ((read_size = recv(client_sock, client_message, MAX_MSG_LENGTH, 0)) > 0) {
            // Add a null terminator to the end of the message
            client_message[read_size] = '\0';

            // Print the message to the console
            printf("Received message: %s\n", client_message);

            // Echo the message back to the client
            if (send(client_sock, client_message, strlen(client_message), 0) != strlen(client_message)) {
                perror("Failed to send message to client");
                exit(1);
            }
        }

        // Client has disconnected, close the socket
        close(client_sock);

        // Server socket will be closed at end of program
    }

    return 0;
}