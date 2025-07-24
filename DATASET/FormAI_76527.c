//FormAI DATASET v1.0 Category: Client Server Application ; Style: accurate
/* A message passing client-server application 
 * This program demonstrates how a client sends a message to a server,
 * the server receives the message, processes it and sends back a response to the client.
 * 
 * Written by: AI Chatbot
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024 // buffer size for message passing

int main(int argc, char *argv[]) {
    int sock_fd, client_sock_fd; // socket file descriptors
    struct sockaddr_in server_address, client_address; // server and client address structures
    socklen_t client_address_len;
    char buffer[BUF_SIZE]; // buffer for message passing
    
    // Creating a socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("Socket creation failed!");
        exit(1);
    }
    
    // Setting up server address
    memset(&server_address, 0, sizeof(server_address)); // zeroing out the structure
    server_address.sin_family = AF_INET; // IPv4 protocol
    server_address.sin_addr.s_addr = INADDR_ANY; // any IP address on the machine
    server_address.sin_port = htons(8888); // port number
    
    // Binding the socket to the server address
    if (bind(sock_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Binding failed!");
        exit(1);
    }
    
    // Listening for incoming connections
    if (listen(sock_fd, 5) < 0) {
        perror("Listening failed!");
        exit(1);
    }
    
    printf("Server is listening for incoming connections on port %d\n", ntohs(server_address.sin_port));
    
    while(1) { // listening indefinitely
        
        // Accepting a new incoming connection
        client_address_len = sizeof(client_address);
        client_sock_fd = accept(sock_fd, (struct sockaddr *)&client_address, &client_address_len);
        if (client_sock_fd < 0) {
            perror("Accepting incoming connection failed!");
            exit(1);
        }
        
        printf("Incoming connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        memset(buffer, 0, BUF_SIZE); // clearing out buffer
        
        // Receiving a message from client
        if (recv(client_sock_fd, buffer, BUF_SIZE, 0) < 0) {
            perror("Error receiving message");
            exit(1);
        }
        
        printf("Received message from client: %s\n", buffer);
        
        // Do something with the message
        // In this example, we just convert the message to uppercase
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] = toupper(buffer[i]);
        }
        
        // Sending back a response to client
        if (send(client_sock_fd, buffer, strlen(buffer), 0) < 0) {
            perror("Error sending message");
            exit(1);
        }
        
        printf("Sent message to client: %s\n", buffer);
        
        close(client_sock_fd); // closing the client socket
    }
    
    return 0;
}