//FormAI DATASET v1.0 Category: Client Server Application ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 256
#define PORT_NUMBER 8888

void handle_client(int client_socket);

int main() {
    int server_socket, client_socket, addr_size;
    struct sockaddr_in server_address, client_address;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error: Could not create socket.\n");
        exit(1);
    }

    // Set server address configuration
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT_NUMBER);

    // Bind socket to address and port
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        printf("Error: Could not bind socket to address and port.\n");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        printf("Error: Could not listen for incoming connections.\n");
        exit(1);
    }

    printf("Server started on port %d.\n", PORT_NUMBER);

    while (1) {
        addr_size = sizeof(client_address);

        // Accept incoming connection
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, (socklen_t *) &addr_size);
        if (client_socket == -1) {
            printf("Error: Could not accept incoming connection.\n");
            continue;
        }

        printf("Client %s:%d connected.\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Handle client logic
        handle_client(client_socket);

        printf("Client %s:%d disconnected.\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        close(client_socket);
    }

    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[MAX_BUFFER_SIZE], hello_message[] = "Hello from server! Who are you?\n";
    int read_size;

    // Send hello message to client
    write(client_socket, hello_message, strlen(hello_message));

    // Receive and analyze client messages
    while ((read_size = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0)) > 0 ) {
        buffer[read_size] = '\0';

        if (strstr(buffer, "Sherlock Holmes") != NULL) {
            write(client_socket, "Welcome, Mr. Holmes! How may I assist you today?\n", strlen("Welcome, Mr. Holmes! How may I assist you today?\n"));
        }
        else if (strstr(buffer, "Watson") != NULL) {
            write(client_socket, "Nice to meet you, Dr. Watson! What brings you here?\n", strlen("Nice to meet you, Dr. Watson! What brings you here?\n"));
        }
        else if (strstr(buffer, "Moriarty") != NULL) {
            write(client_socket, "I'm sorry, I cannot talk to villains!\n", strlen("I'm sorry, I cannot talk to villains!\n"));
        }
        else if (strstr(buffer, "Exit") != NULL) {
            write(client_socket, "Goodbye!\n", strlen("Goodbye!\n"));
            break;
        }
        else {
            write(client_socket, "I'm sorry, I could not understand what you said.\n", strlen("I'm sorry, I could not understand what you said.\n"));
        }
    }

    // Handle connection termination
    if (read_size == 0) {
        printf("Client disconnected.\n");
    }
    else if (read_size == -1) {
        printf("Error: Could not receive message from client.\n");
    }
}