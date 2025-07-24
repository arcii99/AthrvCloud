//FormAI DATASET v1.0 Category: Firewall ; Style: complex
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>

#define PORT 8080
#define MAX_CONNECTIONS 10
#define MAX_BUFFER 1024

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER];
   
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
   
    // Setting socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt)) < 0)
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
   
    // Setting address structure values
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Binding the socket to provided address and port
    if (bind(server_fd, (struct sockaddr *)&address,sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Setting socket to listen for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
  
    // Server loop
    while(1)
    {
        // Accepting incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        pid_t pid = fork();
        
        if(pid == 0)
        {
            struct sockaddr_in client_addr;
            int client_addrlen = sizeof(client_addr);
            
            // Retrieving the client address from accepted socket
            if(getpeername(new_socket, (struct sockaddr*)&client_addr, &client_addrlen)<0)
            {
                perror("getpeername");
                exit(EXIT_FAILURE);
            }
            
            char ip[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &(client_addr.sin_addr), ip, INET_ADDRSTRLEN);
            
            // Checking IP address to block
            if(strcmp(ip, "192.168.1.2")==0)
            {
                // Block connection
                printf("Blocked connection from IP address: %s\n", ip);
                close(new_socket);
                continue;
            }
            
            // Reading data from client
            memset(buffer,0,MAX_BUFFER);
            valread = read(new_socket , buffer, MAX_BUFFER);
            printf("Message Received from %s: %s\n", ip, buffer);
            send(new_socket , "Acknowledged\n" , strlen("Acknowledged") , 0 );
            close(new_socket);
            exit(EXIT_SUCCESS);
        }
        else
        {
            close(new_socket);
        }
    }
    return 0;
}