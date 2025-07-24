//FormAI DATASET v1.0 Category: Chat server ; Style: random
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
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    char *hello = "Hello from server"; 
    
    srand(time(NULL)); 
    char rand_str[10]; 
    
    // Create socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Set socket options 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
    
    // Bind socket to address 
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Listen for incoming connections 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    
    printf("Server is listening on port %d...\n", PORT); 
    
    // Accept incoming connection 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
    printf("Connection accepted from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port)); 
    
    // Send and receive messages 
    while(1) 
    { 
        // Receive message from client 
        valread = read(new_socket , buffer, 1024); 
        if(valread == 0) 
        { 
            printf("Client disconnected.\n"); 
            close(new_socket); 
            break; 
        } 
        printf("%s: %s\n", inet_ntoa(address.sin_addr), buffer); 
        
        // Generate random string and send to client 
        sprintf(rand_str, "%d", rand() % 100); 
        send(new_socket , rand_str , strlen(rand_str) , 0 ); 
        printf("Server: %s\n", rand_str); 

        // Clear buffer
        memset(buffer, 0, sizeof(buffer)); 
        memset(rand_str, 0, sizeof(rand_str)); 
    }
    
    // Close socket file descriptor 
    close(server_fd); 
    return 0; 
}