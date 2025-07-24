//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: scientific
// C TCP/IP Programming Example - Socket Communication Between Client and Server

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080 // Port number to be used for communication

int main(int argc, char const *argv[]) 
{ 
    int socket_fd, new_socket_fd; 
    struct sockaddr_in server_address, client_address; 
    int address_len = sizeof(server_address); 

    // Create a new socket and check for errors
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("Socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Assign IP address and port to the server socket
    server_address.sin_family = AF_INET; // IPv4 protocol
    server_address.sin_addr.s_addr = INADDR_ANY; // Use any available IP address
    server_address.sin_port = htons(PORT); // Convert port number to network byte order
    
    // Bind the socket to the server address and check for errors
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
    { 
        perror("Binding failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Listen for incoming connection requests from clients
    if (listen(socket_fd, 3) < 0) 
    { 
        perror("Listening failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Accept incoming connection requests from clients
    if ((new_socket_fd = accept(socket_fd, (struct sockaddr *)&client_address, (socklen_t*)&address_len)) < 0) 
    { 
        perror("Accepting failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Read data from the client and print it to the console
    char buffer[1024] = {0}; 
    int read_value = read(new_socket_fd, buffer, 1024); 
    printf("Received message from client: %s\n", buffer); 
    
    // Send a message back to the client
    char message[] = "Hello from server!"; 
    send(new_socket_fd, message, strlen(message), 0); 
    printf("Message sent to client\n"); 
    
    return 0; 
}