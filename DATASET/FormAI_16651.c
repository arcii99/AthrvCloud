//FormAI DATASET v1.0 Category: Simple Web Server ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) 
{
    int socket_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int address_len = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    // Create socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
       
    // Bind the socket to the address and port number
    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0) 
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    if (listen(socket_fd, 3) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Listening on http://localhost:%d/\n", PORT);
    
    while(1) 
    {
        if ((new_socket = accept(socket_fd, (struct sockaddr *)&address, (socklen_t*)&address_len))<0)
        {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        
        valread = read(new_socket, buffer, BUFFER_SIZE);
        printf("%s\n", buffer);
        char *html_response = "<!DOCTYPE html><html><head><title>C Web Server</title></head><body><h1>Hello from C Web Server Example</h1></body></html>";
        char *response_header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
        send(new_socket, response_header, strlen(response_header), 0);
        send(new_socket , html_response , strlen(html_response) , 0 );
        close(new_socket);
    }
    
    return 0;
}