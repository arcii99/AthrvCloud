//FormAI DATASET v1.0 Category: Socket programming ; Style: recursive
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define PORT 8080 
#define MAX_LINE_LEN 1024

// Recursive function to receive messages 
void receive_message(int socket_fd) 
{ 
    char buffer[MAX_LINE_LEN]; 
    int read_size = recv(socket_fd, buffer, MAX_LINE_LEN, 0); 
    
    // If message has been received successfully 
    if (read_size > 0) { 
        printf("%s", buffer); 
        receive_message(socket_fd); 
    } 
} 

int main() 
{ 
    int socket_fd, connection_fd; 
    struct sockaddr_in server_address, client_address; 
    char message[MAX_LINE_LEN]; 

    // Create socket 
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) { 
        printf("Could not create socket.\n"); 
        return 1; 
    } 

    // Prepare server address 
    server_address.sin_family = AF_INET; 
    server_address.sin_addr.s_addr = INADDR_ANY; 
    server_address.sin_port = htons(PORT); 

    // Bind socket to server address 
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) { 
        printf("Could not bind socket to address.\n"); 
        return 1; 
    } 

    // Begin listening on the socket 
    if (listen(socket_fd, 3) == -1) { 
        printf("Could not listen on socket.\n"); 
        return 1; 
    } 

    printf("Waiting for incoming connections...\n"); 

    while(1) { 
        int client_address_len = sizeof(client_address); 

        // Accept incoming connection and create a new socket file descriptor for the connection 
        if ((connection_fd = accept(socket_fd, (struct sockaddr *)&client_address, (socklen_t*)&client_address_len)) == -1) { 
            printf("Could not accept incoming connection.\n"); 
            continue; 
        } 

        printf("Connection accepted.\n"); 

        // Send message to client 
        strcpy(message, "Welcome to the server!\n"); 
        send(connection_fd, message, strlen(message), 0); 

        // Receive messages from client 
        receive_message(connection_fd); 

        // Close the connection file descriptor 
        close(connection_fd); 
    } 

    return 0; 
}