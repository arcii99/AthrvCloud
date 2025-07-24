//FormAI DATASET v1.0 Category: Networking ; Style: immersive
// Welcome to the virtual chat room!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_BUFFER_SIZE 1024

// Globals
int client_sockets[MAX_CLIENTS] = {0};
bool running = true;

// Helper functions
void print_clients() {
    printf("\n");
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] != 0) {
            printf("Client %d is connected.\n", i);
        }
    }
    printf("\n");
}

bool is_valid_client(int client_socket) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_socket == client_sockets[i]) {
            return true;
        }
    }
    return false;
}

void send_message(int client_socket, char* buffer) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] != 0 && client_sockets[i] != client_socket) {
            send(client_sockets[i], buffer, strlen(buffer), 0);
        }
    }
}

void handle_client(int client_socket) {
    char buffer[MAX_BUFFER_SIZE] = {0};
    int valread;
    while (running) {
        valread = read(client_socket, buffer, MAX_BUFFER_SIZE);
        if (valread == 0) {
            printf("Client disconnected.\n");
            close(client_socket);
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == client_socket) {
                    client_sockets[i] = 0;
                    break;
                }
            }
            break;
        } else {
            printf("Received message: %s", buffer);
            send_message(client_socket, buffer);
            memset(buffer, 0, MAX_BUFFER_SIZE);
        }
    }
}

// Main function
int main(int argc, char const *argv[]) {
    int server_socket, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER_SIZE] = {0};
       
    // Creating server socket file descriptor
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
       
    // Setting address parameters
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
       
    // Binding server socket to address
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);
       
    while (running) {
        if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        printf("New client connected.\n");

        // Add client socket to global list
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = new_socket;
                break;
            }
        }

        print_clients();

        // Spawn thread to handle client
        if (!fork()) {
            handle_client(new_socket);
            exit(0);
        }
    }

    // Close server socket
    close(server_socket);
    return 0;
}