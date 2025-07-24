//FormAI DATASET v1.0 Category: Socket programming ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

    printf("*** Welcome to The Visionary Socket Programming Example ***\n\n");

    // Create a TCP socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    printf("[+] Socket created successfully.\n");

    // Bind the socket to an address and port
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }
    printf("[+] Socket binded successfully.\n");

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }
    printf("[+] Listening for incoming connections...\n");

    // Handle incoming connections
    while (1) {
        struct sockaddr_in client_addr = {0};
        socklen_t client_addr_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_size);
        if (client_socket == -1) {
            perror("Failed to accept incoming connection");
            continue;
        }
        printf("[+] Accepted incoming connection from %s:%d.\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Read client message
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        if (recv(client_socket, buffer, sizeof(buffer) - 1, 0) == -1) {
            perror("Failed to receive message from client");
            close(client_socket);
            continue;
        }
        printf("[+] Received message: %s", buffer);

        // Send message to client
        char *message = "Hello from the visionary world!\n";
        if (send(client_socket, message, strlen(message), 0) == -1) {
            perror("Failed to send message to client");
            close(client_socket);
            continue;
        }
        printf("[+] Sent message: %s", message);

        // Close client socket
        close(client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}