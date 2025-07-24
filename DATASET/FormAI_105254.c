//FormAI DATASET v1.0 Category: Socket programming ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {

    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char message[100], response[100];
    int option = 1;

    // Create a server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse the port
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option)) < 0) {
        perror("Set socket options error");
        exit(EXIT_FAILURE);
    }

    // Set server address parameters
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    // Bind server socket to the server address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    // Listen for client connection requests
    if (listen(server_socket, 3) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    printf("Happy server waiting for client connections...\n");

    int addrlen = sizeof(server_address);

    // Accept client connection requests
    if ((client_socket = accept(server_socket, (struct sockaddr *) &server_address, (socklen_t *) &addrlen)) < 0) {
        perror("Accept error");
        exit(EXIT_FAILURE);
    }
    
    printf("Client connected! Let's chat!\n");

    while (1) {
        memset(message, 0, sizeof(message));
        memset(response, 0, sizeof(response));
        
        // Receive message from client
        if (read(client_socket, message, sizeof(message)) < 0) {
            perror("Read error");
            exit(EXIT_FAILURE);
        }
        
        // Print received message
        printf("Client: %s\n", message);
        
        // Send response to client
        printf("Server: ");
        fgets(response, sizeof(response), stdin);
        write(client_socket, response, strlen(response));
        
        // Check for exit command from either server or client
        if (strcmp(message, "exit\n") == 0 || strcmp(response, "exit\n") == 0)
            break;
    }

    // Close sockets
    close(client_socket);
    close(server_socket);

    printf("Ending chat. Bye bye!\n");

    return 0;
}