//FormAI DATASET v1.0 Category: Socket programming ; Style: genious
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <netinet/in.h> 
#include <unistd.h> 

#define BUFF_SIZE 1024 

int main(int argc, char const *argv[]) 
{ 
    // Creating the socket 
    int server_fd = socket(AF_INET, SOCK_STREAM, 0); 
    if(server_fd < 0) 
    { 
        perror("Socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Binding the socket to a specific IP and port number 
    struct sockaddr_in address; 
    memset(&address, 0, sizeof(address)); 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(8080); 
    if(bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) 
    { 
        perror("Binding failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Listening for incoming connections 
    if(listen(server_fd, 3) < 0) 
    { 
        perror("Listening failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Accepting incoming connections 
    int addrlen = sizeof(address); 
    int client_fd = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen); 
    if(client_fd < 0) 
    { 
        perror("Accepting failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Receiving messages from the client and sending them back 
    char buffer[BUFF_SIZE] = {0}; 
    while(1) 
    { 
        memset(buffer, 0, BUFF_SIZE); 
        read(client_fd, buffer, BUFF_SIZE); 
        printf("Client: %s", buffer); 

        if(strcmp(buffer, "exit\n") == 0) 
        { 
            printf("Server is shutting down...\n"); 
            break; 
        } 

        char* reply = "Server: message received\n"; 
        send(client_fd, reply, strlen(reply), 0); 
    } 

    // Closing the sockets 
    close(client_fd); 
    close(server_fd); 
    return 0; 
}