//FormAI DATASET v1.0 Category: Networking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>     // Header file for socket creation 
#include <netinet/in.h>     // Header file for sockaddr_in structure 
#include <arpa/inet.h>      // Header file for inet_pton() function 

#define PORT 8080 

int main(int argc, char const *argv[]) 
{ 
    int socket_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 

    // Creating socket file descriptor 
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        printf("Socket creation failed."); 
        exit(EXIT_FAILURE); 
    } 

    // Setting socket options for reuse of address and port 
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        printf("Socket option setting failed."); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 

    // Binding the socket to address and port 
    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        printf("Socket binding failed."); 
        exit(EXIT_FAILURE); 
    } 

    // Listening for incoming connection requests 
    if (listen(socket_fd, 3) < 0) 
    { 
        printf("Listening failed."); 
        exit(EXIT_FAILURE); 
    } 

    // Accepting connection requests and creating new socket descriptor 
    if ((new_socket = accept(socket_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
    { 
        printf("Connection acceptance failed."); 
        exit(EXIT_FAILURE); 
    } 

    // Receiving message from client 
    valread = read(new_socket, buffer, 1024); 
    printf("%s\n",buffer ); 

    // Sending message to client 
    char *hello = "Hello from server"; 
    send(new_socket, hello, strlen(hello), 0 ); 
    printf("Hello message sent\n"); 

    return 0; 
}