//FormAI DATASET v1.0 Category: Simple Web Server ; Style: happy
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <string.h>  
#include <sys/socket.h>  
#include <arpa/inet.h>  
#include <netinet/in.h>  

#define PORT 8080  

int main()  
{  
    printf("Woo-hoo, let's start our web server!\n");  
    
    int server_fd, new_socket, valread;  
    struct sockaddr_in address;  
    int opt = 1;  
    int addrlen = sizeof(address);  
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";  
    
    // create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)  
    {  
        printf("Oops, failed to create a socket!\n");  
        exit(EXIT_FAILURE);  
    }  
    
    // set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))  
    {  
        printf("Oops, failed to set socket options!\n");  
        exit(EXIT_FAILURE);  
    }  
    
    // bind and listen
    address.sin_family = AF_INET;  
    address.sin_addr.s_addr = INADDR_ANY;  
    address.sin_port = htons(PORT);  
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)  
    {  
        printf("Oops, failed to bind the socket!\n");  
        exit(EXIT_FAILURE);  
    }  
    
    if (listen(server_fd, 3) < 0)  
    {  
        printf("Oops, failed to listen on the socket!\n");  
        exit(EXIT_FAILURE);  
    }  
    
    // accept client requests and send response
    while (1)  
    {  
        printf("Waiting for incoming client request...\n"); 
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)  
        {  
            printf("Oops, failed to accept client request!\n");  
            exit(EXIT_FAILURE);  
        }  
        
        char buffer[30000] = {0};  
        valread = read(new_socket , buffer, 30000);  
        printf("%s\n",buffer );  
        write(new_socket , response , strlen(response));  
        printf("Response sent to the client successfully!\n"); 
        
        close(new_socket);
    }  
    
    return 0;  
}