//FormAI DATASET v1.0 Category: Simple Web Server ; Style: optimized
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 

#define PORT 8080

int main(int argc, char const *argv[]) 
{
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    char *hello = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<!DOCTYPE html><html><head><title>Hello World</title></head><body><h1>Hello, World!</h1></body></html>";

    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        return -1; 
    } 
    
    // Attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        return -1; 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 
    
    // Binding the socket to the provided address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        perror("bind failed"); 
        return -1; 
    } 

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        return -1; 
    } 
    
    while(1) {
        printf("\nWaiting for a client to connect...\n");
        // Accepting incoming client connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
        { 
            perror("accept"); 
            return -1; 
        } 
        
        printf("Client connected!\n");

        // Reading the request from the client
        valread = read(new_socket, buffer, 1024); 
        printf("%s\n",buffer );

        // Sending the response to the client
        write(new_socket, hello, strlen(hello)); 
        printf("Hello message sent\n");
        close(new_socket);
    }
    return 0; 
}