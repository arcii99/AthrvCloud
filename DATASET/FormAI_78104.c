//FormAI DATASET v1.0 Category: Socket programming ; Style: innovative
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 

#define PORT 8080 

int main() 
{ 
    int socket_fd, new_socket, val_read; 
    struct sockaddr_in server_address, client_address; 
    char buffer[1024] = {0}; 
    char *hello = "Hello from the other side!"; 
    char client_msg[1024] = {0}; 
    int client_addr_len = sizeof(client_address); 
     
    // Creating socket file descriptor 
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("Socket creation failed"); 
        exit(EXIT_FAILURE); 
    }
    
    printf("Socket created successfully! \n");
 
    memset(&server_address, '0', sizeof(server_address)); 
    
    // Assigning IP and port 
    server_address.sin_family = AF_INET; 
    server_address.sin_addr.s_addr = htonl(INADDR_ANY); 
    server_address.sin_port = htons(PORT); 
     
    // Bind the socket to the specified address and port 
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address))<0) 
    { 
        perror("Bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    printf("Bind successful! \n");
    
    // Listen to incoming connections 
    if (listen(socket_fd, 3) < 0) 
    { 
        perror("Listen failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    printf("Listening... \n");
    
    // Accept an incoming connection 
    if ((new_socket = accept(socket_fd, (struct sockaddr *)&client_address, (socklen_t*)&client_addr_len))<0) 
    { 
        perror("Accept failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    printf("Connection accepted! \n");

    // Send a welcome message to the client
    send(new_socket, hello, strlen(hello), 0 ); 
    printf("Welcome message sent! \n"); 

    // Receive message from the client
    val_read = read( new_socket , client_msg, 1024); 
    printf("%s\n",client_msg ); 

    // Close the socket
    close(socket_fd);
    printf("Connection closed! \n");
    return 0; 
}