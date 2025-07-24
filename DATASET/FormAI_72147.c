//FormAI DATASET v1.0 Category: Networking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 12345
#define MAX_BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket; 
    struct sockaddr_in address; 
    int addrlen = sizeof(address); 
    char buffer[MAX_BUFFER_SIZE] = {0}; 
    char *hello = "Hello from server"; 

    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Filling server address information 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 
       
    // Bind the socket with the server address specified above 
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    printf("Listening on port %d...\n", PORT);
       
    // Start listening for connections 
    if (listen(server_fd, 3) < 0) { 
        perror("listen failed"); 
        exit(EXIT_FAILURE); 
    }

    // Accept incoming connections 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) { 
        perror("accept failed"); 
        exit(EXIT_FAILURE); 
    } 
    printf("New connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

    // Send a welcome message to the newly connected client 
    send(new_socket, hello, strlen(hello), 0 ); 
    printf("Welcome message sent to the client\n"); 
       
    // Receive incoming messages from the client 
    while (1) {
        int valread = read(new_socket , buffer, MAX_BUFFER_SIZE); 
        printf("Received message: %s\n", buffer);
        memset(buffer, 0, sizeof(buffer)); // Clear the buffer
        
        // Echo the message back to the client 
        char message[MAX_BUFFER_SIZE] = {0};
        snprintf(message, MAX_BUFFER_SIZE, "Received: %s", buffer);
        send(new_socket , message , strlen(message) , 0 ); 
        printf("Echoed message back to client\n");
    }
    return 0; 
}