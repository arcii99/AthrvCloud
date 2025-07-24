//FormAI DATASET v1.0 Category: Firewall ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

#define MAX_SIZE 1000

int main()
{
    char buffer[MAX_SIZE];
    
    int s_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    if(s_socket == -1)
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(80);
    
    if(bind(s_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }
    
    if(listen(s_socket, 3) < 0)
    {
        perror("Error listening to socket");
        exit(EXIT_FAILURE);
    }
    
    printf("Server started listening on port 80\n");
    
    while(1)
    {
        int c_socket = accept(s_socket, NULL, NULL);
        
        if(c_socket < 0)
        {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }
        
        memset(buffer, 0, MAX_SIZE);
        
        if(read(c_socket, buffer, MAX_SIZE) < 0)
        {
            perror("Error reading from socket");
            exit(EXIT_FAILURE);
        }
        
        printf("Request from client: %s\n", buffer);
        
        //Code for Firewall
        char* search = strstr(buffer, "facebook.com");
        
        if(search != NULL)
        {
            printf("Request from client blocked: %s\n", search);
            const char* block_msg = "HTTP/1.1 403 Forbidden\r\nContent-Length: 22\r\n\r\nError 403: Access denied";
            write(c_socket, block_msg, strlen(block_msg));
        }
        else
        {
            const char* response_msg = "HTTP/1.1 200 OK\r\nContent-Length: 22\r\n\r\nConnection Established";
            write(c_socket, response_msg, strlen(response_msg));
        }
        
        close(c_socket);
    }
    
    close(s_socket);
    return 0;
}