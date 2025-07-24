//FormAI DATASET v1.0 Category: Networking ; Style: accurate
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
  
#define PORT 8080 
  
int main(int argc, char const *argv[]) 
{ 
    int socket_desc, new_socket, valread; 
    struct sockaddr_in server_address, client_address; 
    int option = 1; 
    int address_length = sizeof(server_address); 

    char buffer[1024] = {0}; 
    char *hello_message = "Hello from server!"; 
       
    // Creating a socket file descriptor 
    if ((socket_desc = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("Socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Setting socket options
    if (setsockopt(socket_desc, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option))) 
    { 
        perror("setsockopt failure"); 
        exit(EXIT_FAILURE); 
    } 

    // Assigning values to server address
    server_address.sin_family = AF_INET; 
    server_address.sin_addr.s_addr = INADDR_ANY; 
    server_address.sin_port = htons( PORT ); 

    // Binding the socket to the server address
    if (bind(socket_desc, (struct sockaddr *)&server_address, sizeof(server_address))<0) 
    { 
        perror("Bind failure"); 
        exit(EXIT_FAILURE); 
    } 

    // Listening for incoming connections
    if (listen(socket_desc, 3) < 0) 
    { 
        perror("Listen failure"); 
        exit(EXIT_FAILURE); 
    } 

    // Accept incoming connection
    if ((new_socket = accept(socket_desc, (struct sockaddr *)&server_address, (socklen_t*)&address_length))<0) 
    { 
        perror("Connection acceptance failure"); 
        exit(EXIT_FAILURE); 
    } 

    // Reading incoming message from client
    valread = read(new_socket, buffer, 1024); 
    printf("%s\n",buffer ); 

    // Sending hello message to client
    send(new_socket, hello_message, strlen(hello_message), 0 ); 
    printf("Hello message sent\n"); 

    return 0; 
}