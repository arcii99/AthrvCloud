//FormAI DATASET v1.0 Category: Networking ; Style: real-life
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

#define PORT 8080
#define BUFFER_SIZE 1024

int main() 
{ 
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    char buffer[BUFFER_SIZE] = {0}; 
    char *hello = "Hello from server"; 

    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Forcefully attaching socket to the port 8080 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 

    while(1){
        printf("\nWaiting for connection\n");
        
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&address))<0) 
        { 
            perror("accept"); 
            exit(EXIT_FAILURE); 
        } 

        printf("Connection established\n");

        char welcome[BUFFER_SIZE] = "Welcome to my server";
        send(new_socket, welcome, strlen(welcome), 0); 
        printf("Welcome message sent\n"); 

        valread = read( new_socket , buffer, BUFFER_SIZE); 
        printf("%s\n",buffer ); 

        send(new_socket , hello , strlen(hello) , 0 ); 
        printf("Hello message sent\n"); 

        close(new_socket);
        printf("Connection closed\n");
    }

    return 0; 
}