//FormAI DATASET v1.0 Category: Client Server Application ; Style: unmistakable
#include<stdio.h> 
#include<stdlib.h> 
#include<sys/socket.h> 
#include<arpa/inet.h> 
#include<unistd.h> 
#include<string.h> 

#define PORT 8080 

int main(int argc, char const *argv[]) 
{ 
    int server_fd, client_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    char *response = "Server received the message"; 
       
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Listening for incoming client connections 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 

    // Accepting the incoming client connection
    if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Receiving message from client 
    valread = read(client_socket , buffer, 1024); 
    printf("Client Message: %s\n",buffer ); 

    // Sending response back to client 
    send(client_socket , response , strlen(response) , 0 ); 
    printf("Response Sent\n"); 
    return 0; 
}