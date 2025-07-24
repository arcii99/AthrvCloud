//FormAI DATASET v1.0 Category: Simple Web Server ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

void serve_client(int socket){
    char buffer[1024];
    int valread = read(socket, buffer, 1024);
    printf("[SERVER] Received client message: %s\n", buffer);
    
    char response[1024] = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";
    write(socket, response, strlen(response));
    printf("[SERVER] Sent response to client.\n");
}

int main(){
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Create socket
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        printf("[SERVER] Socket creation failed.\n");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        printf("[SERVER] Set socket options failed.\n");
        exit(EXIT_FAILURE);
    }
    
    // Set address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
    
    // Bind socket to address and port
    if(bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        printf("[SERVER] Bind failed.\n");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if(listen(server_fd, 3) < 0){
        printf("[SERVER] Listen failed.\n");
        exit(EXIT_FAILURE);
    }
    
    printf("[SERVER] Listening on port %d...\n", PORT);
    
    while(1){ 
        // Accept incoming connection
        if((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0 ){
            printf("[SERVER] Accept failed.\n");
            exit(EXIT_FAILURE);
        }
        
        printf("[SERVER] Accepted connection from client %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
        
        // Serve client
        serve_client(new_socket);
        
        // Close socket with client
        close(new_socket);
        printf("[SERVER] Closed connection with client.\n");
    }
    
    return 0;
}