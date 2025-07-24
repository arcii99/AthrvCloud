//FormAI DATASET v1.0 Category: Client Server Application ; Style: authentic
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>

#define PORT 8080 
    
int main(int argc, char const *argv[]) 
{ 
    int server_fd, new_socket; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    
    // create socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("Socket failed."); 
        exit(EXIT_FAILURE); 
    } 
       
    // set socket options 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        perror("Setsockopt failed."); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
        
    // bind server to the specified address 
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        perror("Bind failed."); 
        exit(EXIT_FAILURE); 
    } 
       
    // listen for incoming connections 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("Listen failed."); 
        exit(EXIT_FAILURE); 
    } 
       
    // accept incoming connection 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
    { 
        perror("Accept failed."); 
        exit(EXIT_FAILURE); 
    } 
       
    // read and print message from client 
    read(new_socket, buffer, 1024); 
    printf("Client: %s\n", buffer); 
    
    // send message back to client 
    const char *hello = "Hello from server."; 
    send(new_socket , hello , strlen(hello) , 0 ); 
    printf("Message sent.\n"); 
    
    return 0; 
}