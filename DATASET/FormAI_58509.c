//FormAI DATASET v1.0 Category: Chat server ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(){
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char response[] = "Hi there! I'm a chatbot.\n";
       
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
      
    // Attach socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
       
    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0){
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    // Accept incoming connection from a client
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    
    // Send welcome message
    send(new_socket, response, strlen(response), 0);
    
    while(1){
        
        // Read message from the client
        valread = read(new_socket, buffer, BUFFER_SIZE);
        
        if(valread == 0){
            printf("The client has closed the connection.\n");
            break;
        }
        
        // Process and respond to the message
        if(strcmp(buffer, "Hello\n") == 0){
            send(new_socket, "Hi there!\n", strlen("Hi there!\n"), 0);
        }
        else if(strcmp(buffer, "How are you?\n") == 0){
            send(new_socket, "I'm a chatbot, I don't have feelings.\n", strlen("I'm a chatbot, I don't have feelings.\n"), 0);
        }
        else if(strcmp(buffer, "Bye\n") == 0){
            send(new_socket, "Goodbye!\n", strlen("Goodbye!\n"), 0);
            break;
        }
        else{
            send(new_socket, "I'm sorry, I don't understand.\n", strlen("I'm sorry, I don't understand.\n"), 0);
        }
        
        // Clear buffer
        memset(buffer, 0, BUFFER_SIZE);
        
    }
    
    // Close socket
    close(new_socket);
    close(server_fd);
    
    return 0;
}