//FormAI DATASET v1.0 Category: Socket programming ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) 
{ 
    int sockfd, new_socket, valread; 
    struct sockaddr_in serv_addr; 
    
    char *server_message = "Welcome to the C Socket Programming Example!"; 
    
    char buffer[1024] = {0}; 
    
    // Create server socket 
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("Socket failed."); 
        exit(EXIT_FAILURE); 
    } 
    
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_addr.s_addr = INADDR_ANY; 
    serv_addr.sin_port = htons(PORT); 
    
    // Bind socket to the specified port 
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0) 
    { 
        perror("Binding failed."); 
        exit(EXIT_FAILURE); 
    } 
    
    printf("Listening on port %d...\n", PORT); 
    
    // Wait for incoming connections 
    if (listen(sockfd, 3) < 0) 
    { 
        perror("Listen failed."); 
        exit(EXIT_FAILURE); 
    } 
    
    // Accept incoming connection 
    if ((new_socket = accept(sockfd, (struct sockaddr *)&serv_addr, (socklen_t*)&serv_addr))<0) 
    { 
        perror("Accept failed."); 
        exit(EXIT_FAILURE); 
    } 
    
    printf("Client connected!\n"); 
    
    // Send welcome message to the client 
    send(new_socket, server_message, strlen(server_message), 0 ); 
    
    // Receive message from the client 
    valread = read(new_socket, buffer, 1024); 
    
    printf("Client message: %s\n", buffer); 
    
    // Check if the client wants to terminate the connection 
    if (strcmp(buffer, "exit\n") == 0) 
    { 
        printf("Exiting...\n"); 
        close(sockfd); 
        exit(EXIT_SUCCESS); 
    } 
    
    // Echo back the message to the client 
    send(new_socket, buffer, strlen(buffer), 0 ); 
    
    // Close sockets 
    close(sockfd); 
    close(new_socket); 
    
    return 0; 
}