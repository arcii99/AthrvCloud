//FormAI DATASET v1.0 Category: Chat server ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

// Function to handle client connections
void handle_client(int client_socket) {
    char buffer[MAX_BUFFER_SIZE] = {0}, message[MAX_BUFFER_SIZE] = {0};
    int num_read;

    // Send welcome message to the client
    sprintf(message, "Welcome to the chat room!\n");
    send(client_socket, message, strlen(message), 0);

    // Loop to receive and process messages from client
    while ((num_read = read(client_socket, buffer, MAX_BUFFER_SIZE)) > 0) {
        buffer[num_read-1] = '\0';
        if (strcasecmp(buffer, "quit") == 0) {
            break; // Stop receiving messages if client sends "quit"
        }

        // Prepend client's IP address to message and send it to all clients
        sprintf(message, "%s: %s\n", inet_ntoa((struct in_addr){client_socket}), buffer);
        printf("%s", message);
        send(client_socket, message, strlen(message), 0);
        memset(buffer, 0, sizeof(buffer));
        memset(message, 0, sizeof(message));
    }

    // Close socket and exit thread
    close(client_socket);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket, optval = 1;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    pthread_t tid;

    // Create socket and set options to reuse address and port
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &optval, sizeof(optval)) < 0) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    // Bind socket to IP address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d...\n", PORT);

    // Loop to handle incoming connections
    while (1) {
        client_len = sizeof(client_addr);
        if ((client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_len)) < 0) {
            perror("Error accepting connection");
            continue;
        }
        printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Create new thread to handle client connection
        if (pthread_create(&tid, NULL, handle_client, client_socket) < 0) {
            perror("Error creating thread");
            continue;
        }
    }

    // Close server socket and exit program
    close(server_socket);
    return 0;
}