//FormAI DATASET v1.0 Category: Chat server ; Style: visionary
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <time.h> 

#define PORT 8080 
#define MAX 1024 

int main() { 
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[MAX] = {0}; 
    char* welcome_message = "Welcome to the visionary chat server!"; 
       
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Setting socket options 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    // Binding socket 
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Listening to incoming connections 
    if (listen(server_fd, 3) < 0) { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 

    // Accepting incoming connections 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 

    // Send welcome message to client
    send(new_socket, welcome_message, strlen(welcome_message), 0);

    // Chat Loop
    while(1){
        // Clearing the buffer 
        memset(buffer, '\0', MAX);  
        
        // Reading message from client
        valread = read(new_socket, buffer, MAX); 
        
        // Displaying the message sent by the client
        printf("\t\tMessage from client: %s\n", buffer);

        // Sending confirmation message to client
        send(new_socket, "Message received", 17, 0);
    }

    // Closing server and client sockets
    close(new_socket);
    close(server_fd);

    return 0; 
}