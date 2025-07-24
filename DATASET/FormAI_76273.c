//FormAI DATASET v1.0 Category: Networking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 5000
#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

int main() {

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *hello = "Greetings, Citizen! How can I assist you?\n";
    char *goodbye = "Farewell, Citizen!\n";
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind the socket to the specified address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Start listening for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    
    // Keep accepting connections and serving clients
    while(1) {
        
        // Accept a new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        
        // Send a welcome message to the new client
        send(new_socket, hello, strlen(hello), 0);
        
        // Read data from the client
        while ((valread = read(new_socket, buffer, BUFFER_SIZE)) > 0) {
            printf("Received message: %s\n", buffer);
            
            // Check if the client wants to disconnect
            if (strstr(buffer, "disconnect")) {
                printf("Client disconnected.\n");
                send(new_socket, goodbye, strlen(goodbye), 0);
                close(new_socket);
                break;
            }
            
            // Echo back the message to the client
            send(new_socket, buffer, strlen(buffer), 0);
            
            // Clear the buffer for the next message
            memset(buffer, 0, BUFFER_SIZE);
        }
        
        // Close the connection
        close(new_socket);
    }

    return 0;
}