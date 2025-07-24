//FormAI DATASET v1.0 Category: Networking ; Style: excited
// Buckle up, coding enthusiasts! We're about to dive into a thrilling adventure of networking in C

#include <stdio.h> // For basic I/O operations
#include <stdlib.h> // For exit() function and dynamic memory allocation
#include <string.h> // For string manipulation functions
#include <unistd.h> // For close() function
#include <sys/socket.h> // For socket() function and related constants
#include <netinet/in.h> // For struct sockaddr_in and related constants

#define PORT 8080 // The port number that we're going to use

int main(){
    int server_fd, new_socket, valread; // Variables to store the file descriptors for the server socket, new socket, and the number of bytes read
    struct sockaddr_in address; // Structure to store the socket address information
    int opt = 1; // Integer variable to store the option for setsockopt() function
    int addrlen = sizeof(address); // Integer variable to store the length of the socket address structure
    char buffer[1024] = {0}; // Character array to store the message received from the client
    char *hello = "Hello from the server"; // Character array to store the message that will be sent to the client

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Setting socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET; // Setting the address family to IPv4
    address.sin_addr.s_addr = INADDR_ANY; // Setting the IP address to be the localhost
    address.sin_port = htons(PORT); // Setting the port number to the value of PORT constant
    
    // Binding the socket to a specific address and port number
    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Starting to listen to incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    
    // Accepting incoming connections and handling client requests
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Reading the message sent by the client
    valread = read( new_socket , buffer, 1024);
    printf("%s\n",buffer );
    
    // Sending a message to the client
    send(new_socket , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
    
    // Closing the sockets
    close(new_socket);
    close(server_fd);
    return 0;
}