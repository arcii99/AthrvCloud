//FormAI DATASET v1.0 Category: Simple Web Server ; Style: imaginative
#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h>
#include <string.h>

#define PORT 8080 

int main(int argc, char const *argv[]) 
{ 
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    char *welcome_message = "Welcome to C Simple Web Server"; 
    
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Set socket options 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 

    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 

    // bind the socket 
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    // listen for incoming connections 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 

    printf("\n[*] C Simple Web Server is running on port %d...\n", PORT);

    while(1) {
        // accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
        { 
            perror("accept"); 
            exit(EXIT_FAILURE); 
        } 

        printf("\n[+] New connection made from %s:%d\n\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // send welcome message
        send(new_socket, welcome_message, strlen(welcome_message), 0); 

        // read incoming message
        valread = read(new_socket, buffer, 1024); 
        printf("%s\n",buffer ); 

        // send response
        char *response_message = "HTTP/1.1 200 OK\nContent-Type: text/html; charset=UTF-8\n\n<!DOCTYPE html><html><head><title>C Simple Web Server</title>\
                                </head><body><h1>Hello, world!</h1></body></html>";
        send(new_socket, response_message, strlen(response_message), 0);
        printf("[*] Response sent to %s:%d\n\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // close connection
        close(new_socket);
    }
    
    return 0; 
}