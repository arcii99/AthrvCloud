//FormAI DATASET v1.0 Category: Chat server ; Style: Alan Touring
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <unistd.h>  

int main()  
{  
    // Create variables for connection details  
    int server_fd, new_socket, valread;  
    struct sockaddr_in address;  
    int opt = 1;  
    int addrlen = sizeof(address);  
    char buffer[1024] = {0};  
    char* hello = "Hello from server";  
    
    // Create the server socket  
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)  
    {  
        perror("socket failed");  
        exit(EXIT_FAILURE);  
    }  
    
    // Configure socket options  
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,  
                                                  &opt, sizeof(opt)))  
    {  
        perror("setsockopt");  
        exit(EXIT_FAILURE);  
    }  
    address.sin_family = AF_INET;  
    address.sin_addr.s_addr = INADDR_ANY;  
    address.sin_port = htons( 8080 );  
    
    // Bind the socket to the IP and Port  
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
    
    // Wait for incoming connections  
    while(1)  
    {  
        printf("\nWaiting for new connection...\n");  
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                           (socklen_t*)&addrlen))<0)  
        {  
            perror("accept");  
            exit(EXIT_FAILURE);  
        }  
        printf("New client connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));  
        
        // Loop receiving messages from the client  
        while(1)
        {
            memset(buffer, 0, sizeof(buffer));
            valread = read(new_socket, buffer, 1024);
            if(valread <= 0) break;
            printf("Message received: %s\n", buffer);
            if(!strcmp(buffer, "exit")) break;
            send(new_socket, hello, strlen(hello), 0);
        }
        
        // Close the connection  
        printf("Connection closed: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));  
        close(new_socket);  
    }  
    return 0;  
}