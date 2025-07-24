//FormAI DATASET v1.0 Category: Chat server ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    printf("Welcome to Chat Server Program!\n");
    
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket!\n");
        return -1;
    }
    
    // Define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8888);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // Bind the socket to the specified address and port
    int bind_result = bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    if (bind_result == -1) {
        printf("Error binding socket!\n");
        return -1;
    }
    
    // Listen for incoming connections
    int listen_result = listen(server_socket, 5);
    if (listen_result == -1) {
        printf("Error listening for connections!\n");
        return -1;
    }
    printf("Chat server is listening for connections...\n");
    
    // Accept incoming connections
    struct sockaddr_in client_address;
    socklen_t client_address_size = sizeof(client_address);
    int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_size);
    if (client_socket == -1) {
        printf("Error accepting connection!\n");
        return -1;
    }
    printf("Client connected successfully!\n");
    
    char message[256];
    while (1) {
        // Receive message from client
        memset(message, 0, sizeof(message)); // Clear buffer
        int receive_result = recv(client_socket, message, sizeof(message), 0);
        if (receive_result == -1) {
            printf("Error receiving message from client!\n");
            break; // Stop listening for messages
        }
        printf("Client: %s", message);
        
        // Send message back to client
        memset(message, 0, sizeof(message)); // Clear buffer
        printf("Server: ");
        fgets(message, sizeof(message), stdin);
        int send_result = send(client_socket, message, strlen(message), 0);
        if (send_result == -1) {
            printf("Error sending message to client!\n");
            break; // Stop listening for messages
        }
    }
    
    // Close the socket
    close(client_socket);
    close(server_socket);
    return 0;
}