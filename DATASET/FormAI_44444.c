//FormAI DATASET v1.0 Category: Chat server ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PENDING_CONNECTIONS 5
#define MAX_BUFFER_SIZE 1024

int main(void) {

    // Create the server's socket
    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if (server_socket == -1) {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }
    
    // Define the server's address
    struct sockaddr_in server_address = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = htonl(INADDR_ANY)
    };
    
    // Bind the server's socket to the specified address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Failed to bind server socket to address");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_socket, MAX_PENDING_CONNECTIONS) == -1) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("The game is afoot. The chat server is waiting for connections...\n");

    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    char buffer[MAX_BUFFER_SIZE];

    while (true) {
        // Wait for a client to connect
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_len);

        if (client_socket == -1) {
            perror("Failed to accept client connection");
            exit(EXIT_FAILURE);
        }

        printf("The client has arrived. The adventure begins...\n");

        // Send a welcome message to the client
        char *welcome_message = "Welcome to the Sherlock Holmes Chat Server!\n";
        send(client_socket, welcome_message, strlen(welcome_message), 0);

        while (true) {
            // Receive a message from the client
            int bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);

            if (bytes_received == -1) {
                perror("Failed to receive message from client");
                exit(EXIT_FAILURE);
            }

            if (bytes_received == 0) {
                printf("The client has left. The adventure is over.\n");
                break;
            }

            buffer[bytes_received] = '\0';

            // Decode the client's message
            if (strcmp(buffer, "ELEMENTARY") == 0) {
                char *reply = "My dear Watson, what a curious message! I'm afraid I don't understand what you mean...\n";
                send(client_socket, reply, strlen(reply), 0);
            } else if (strcmp(buffer, "THE GAME IS AFOOT") == 0) {
                char *reply = "The game is indeed afoot, my dear friend! Let us pursue this trail and see where it leads...\n";
                send(client_socket, reply, strlen(reply), 0);
            } else if (strcmp(buffer, "FOLLOW THE MONEY") == 0) {
                char *reply = "Ah, an astute observation, my friend! Let us follow the money and unmask this villain...\n";
                send(client_socket, reply, strlen(reply), 0);
            } else if (strcmp(buffer, "THE CURIOUS INCIDENT OF THE DOG IN THE NIGHT-TIME") == 0) {
                char *reply = "The curious incident of the dog in the night-time indeed, my dear Watson! This may be the clue we need to solve the case...\n";
                send(client_socket, reply, strlen(reply), 0);
            } else if (strcmp(buffer, "EXIT") == 0) {
                printf("The client has left. The adventure is over.\n");
                break;
            } else {
                char *reply = "I'm afraid I don't understand what you mean, my dear friend. Please try again...\n";
                send(client_socket, reply, strlen(reply), 0);
            }
        }

        // Close the client's socket
        close(client_socket);
    }

    // Close the server's socket
    close(server_socket);

    return EXIT_SUCCESS;
}