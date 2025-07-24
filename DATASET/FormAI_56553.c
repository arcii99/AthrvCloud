//FormAI DATASET v1.0 Category: Socket programming ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_PENDING_CONNECTIONS 3 // The maximum number of pending connections in the queue
#define MAX_CLIENTS 2 // The maximum number of connected clients

int main() {
    int server_fd, new_socket, num_clients = 0;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char client_message[1024];
     
    // Create a TCP socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
     
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
     
    // Bind the socket to the IP address and specified port number
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
     
    // Listen for incoming connections
    if (listen(server_fd, MAX_PENDING_CONNECTIONS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
     
    while (1) {
        // Accept a new client connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept failed");
            exit(EXIT_FAILURE); 
        }
        
        num_clients++;
        
        if (num_clients > MAX_CLIENTS) {
            printf("Maximum number of clients reached. Rejecting connection.\n");
            close(new_socket);
        }
        else {
            
            // Send a welcome message to the new client
            char* welcome_msg = "Welcome! This is a chat server.\n";
            send(new_socket, welcome_msg, strlen(welcome_msg), 0);
            
            printf("New client connected. Client address: %s : %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
            
            int client_closed = 0;
            
            while (1) {
                
                // Receive a message from the client
                int valread = read(new_socket, client_message, 1024);
                
                // Check if the client has disconnected
                if (valread <= 0) {
                    printf("Client disconnected. Client address: %s : %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                    close(new_socket);
                    num_clients--;
                    client_closed = 1;
                    break;
                }
                
                // Print the received message
                printf("[Client %s : %d]: %s", inet_ntoa(address.sin_addr), ntohs(address.sin_port), client_message);
                
                // Send the message to all connected clients except the sender
                for (int i=0; i<MAX_CLIENTS; i++) {
                    if (i != new_socket && i!=0) {
                        send(i, client_message, strlen(client_message), 0);
                    }
                }
                
                // Clear the client message buffer
                memset(client_message, 0, 1024);
                
            }
            
            if (client_closed) {
                break;
            }
            
        }
    }
    
    return 0;
}