//FormAI DATASET v1.0 Category: Chat server ; Style: shocked
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

#define PORT 8080 

int main(int argc, char const *argv[]) 
{ 
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    char *welcome = "Welcome to the chat server!";

    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        printf("Oh no! Failed to create socket!"); 
        return -1; 
    } 

    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        printf("Uh oh! Failed to attach socket to port!"); 
        return -1; 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 

    // Forcefully attaching socket to the specified address and port 
    if (bind(server_fd, (struct sockaddr *)&address,sizeof(address))<0) 
    { 
        printf("Oh no! Bind has failed!"); 
        return -1; 
    } 
    
    if (listen(server_fd, 3) < 0) 
    { 
        printf("Uh oh! Listen has failed!"); 
        return -1; 
    } 

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
    { 
        printf("Oh no! Accept has failed!"); 
        return -1; 
    } 
    
    while(1) {

        valread = read( new_socket , buffer, 1024); 
        if(valread <= 0) {
            break;
        }

        if(strcmp(buffer, "exit") == 0) {
            printf("Exiting the chat server"); 
            break;
        }

        printf("Received message: %s\n", buffer); 
        char msg[1024] = {'\0'};
        strcpy(msg, "You said: ");
        strcat(msg, buffer);
        send(new_socket , msg , strlen(msg) , 0 ); 
    }

    close(new_socket);
    close(server_fd);
    printf("\nGoodbye! Hope to see you soon\n");

    return 0; 
}