//FormAI DATASET v1.0 Category: Chat server ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char const *argv[]) 
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *message = "Welcome to the Chat Server!";
       
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    {
        perror("Socket creation failed.");
        exit(EXIT_FAILURE);
    }
      
    // Attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    {
        perror("setsockopt error.");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
       
    // Binding socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    {
        perror("bind failed.");
        exit(EXIT_FAILURE);
    }
      
    // Listening to the incoming messages
    if (listen(server_fd, 3) < 0) 
    {
        perror("listen error.");
        exit(EXIT_FAILURE);
    }
    
    // Sending welcome message to new client and accepting incoming messages
    while(1)
    {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
        {
            perror("accept error.");
            exit(EXIT_FAILURE);
        }
        
        send(new_socket, message, strlen(message), 0 );
        printf("Welcome message sent to Client.\n");
        
        while(1)
        {
            memset(buffer, 0, sizeof(buffer));
            valread = read(new_socket, buffer, 1024);
            if (valread == 0 || strcmp(buffer, "exit") == 0)
            {
                printf("Client disconnected.\n");
                break;
            }
            printf("Client: %s\n", buffer);
            // Implement your own chat logic here
        }
    }
    
    return 0;
}