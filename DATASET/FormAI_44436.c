//FormAI DATASET v1.0 Category: Socket programming ; Style: scalable
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

#define PORT 8080 
#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

int main() 
{ 
    int server_socket, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[BUFFER_SIZE] = {0}; 

    // Create TCP socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Allow reuse of address and port
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Initialize socket address structure
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 
    
    // Bind socket to address and port
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    
    while (1)
    {
        // Await incoming connections
        if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
        { 
            perror("accept"); 
            exit(EXIT_FAILURE); 
        } 
        
        // Get client IP address and port
        char *client_ip = inet_ntoa(address.sin_addr);
        int client_port = ntohs(address.sin_port);
        printf("Connection from %s:%d\n", client_ip, client_port);
        
        // Handle incoming message from client
        valread = read(new_socket, buffer, BUFFER_SIZE); 
        printf("Received message: %s\n", buffer);
        
        // Prepare response message
        char response[BUFFER_SIZE] = {0};
        sprintf(response, "Hello, %s:%d! You said: %s", client_ip, client_port, buffer);
        
        // Send response back to client
        send(new_socket, response, strlen(response), 0 ); 
        printf("Response sent to %s:%d\n", client_ip, client_port);
        
        // Clean up
        close(new_socket);
    }
    
    return 0; 
}