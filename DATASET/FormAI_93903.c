//FormAI DATASET v1.0 Category: Chat server ; Style: scientific
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

#define PORT 8080 

int main(int argc, char const *argv[]) 
{ 
    int socketfd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    char *welcome_msg = "Welcome to the Scientific Chat Server!\n"; 
    
    // Creating socket file descriptor 
    if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("Socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Set socket options
    if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        perror("Setsockopt failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 
    
    // Bind the socket to the IP address and port
    if (bind(socketfd, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        perror("Bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Listen for incoming connections
    if (listen(socketfd, 3) < 0) 
    { 
        perror("Listen failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Accept incoming connections
    if ((new_socket = accept(socketfd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
    { 
        perror("Accept failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Send welcome message to the client
    send(new_socket, welcome_msg, strlen(welcome_msg), 0); 
    
    while(1)
    { 
        memset(buffer, 0, sizeof(buffer)); 
        valread = read(new_socket, buffer, 1024); 
        
        // Terminate the connection if the client sends 'exit'
        if (strncmp(buffer, "exit", 4) == 0) 
        { 
            printf("Client disconnected\n"); 
            break; 
        } 
        
        // Scientific operations
        float x, y, result;
        char operator;
        sscanf(buffer, "%f%c%f", &x, &operator, &y);
        switch(operator)
        {
            case '+':
                result = x + y;
                break;
            case '-':
                result = x - y;
                break;
            case '*':
                result = x * y;
                break;
            case '/':
                if(y != 0)
                    result = x / y;
                else
                    result = -1;
                break;
            default:
                result = -1;
                break; 
        }
        
        // Send result to the client
        char result_string[20];
        sprintf(result_string, "%.2f", result);
        send(new_socket, result_string, strlen(result_string), 0); 
    } 
    
    // Close the connection
    close(new_socket); 
    return 0; 
}