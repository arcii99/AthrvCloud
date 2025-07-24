//FormAI DATASET v1.0 Category: Socket programming ; Style: complex
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 

#define PORT 8080 

int main() { 
    int server_socket, new_socket; 
    struct sockaddr_in server_address, client_address; 
    int opt = 1; 
    socklen_t address_length = sizeof(server_address); 
    char buffer[1024] = {0}; 
    char message[] = "Hello, from server!"; 
    
    // Create socket 
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
        perror("Socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Set socket options 
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
        perror("Socket options set failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Set server address information 
    server_address.sin_family = AF_INET; 
    server_address.sin_addr.s_addr = INADDR_ANY; 
    server_address.sin_port = htons( PORT ); 
    
    // Bind socket to server address 
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address))<0) { 
        perror("Socket bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Listen for connections 
    if (listen(server_socket, 3) < 0) { 
        perror("Listen failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Accept incoming connection 
    if ((new_socket = accept(server_socket, (struct sockaddr *)&client_address, &address_length))<0) { 
        perror("Accept failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Send message to client 
    send(new_socket , message , strlen(message) , 0 ); 
    printf("Message sent from server to client: %s\n", message); 
    
    // Receive message from client 
    read(new_socket , buffer, 1024); 
    printf("Message received from client: %s\n", buffer); 
    
    close(server_socket); 
    return 0; 
}