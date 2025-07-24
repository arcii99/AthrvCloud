//FormAI DATASET v1.0 Category: Simple Web Server ; Style: ephemeral
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <unistd.h>  
#include <sys/socket.h> 
#include <netinet/in.h> 

#define PORT 8080 
#define RESPONSE "<html><body><h1>Welcome to the Simple Web Server!</h1></body></html>\n"
#define RESPONSE_SIZE strlen(RESPONSE)

int main(int argc, char const *argv[]) 
{ 
    int server_fd, client_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 

    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("Socket failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Set socket options to reuse address and port 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        perror("Setsockopt failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Set the server address and port 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
    
    // Bind the socket to the server address and port 
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        perror("Bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Listen for incoming connections 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("Listen failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Continuously loop to handle incoming connections 
    while(1) 
    { 
        if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
        { 
            perror("Accept failed"); 
            exit(EXIT_FAILURE); 
        } 
        
        // Read the client request message 
        valread = read(client_socket , buffer, 1024); 
        printf("%s\n",buffer ); 
        
        // Send the response back to the client 
        write(client_socket , RESPONSE , RESPONSE_SIZE); 
        printf("Response sent\n"); 
        
        // Close the client socket connection 
        close(client_socket); 
    } 
    return 0; 
}