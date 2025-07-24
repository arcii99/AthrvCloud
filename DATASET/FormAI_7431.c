//FormAI DATASET v1.0 Category: Socket programming ; Style: scientific
/******************************************************************************
 * File           : scientific_socket_programming.c
******************************************************************************/
/**
  * Description  : Sample code in C for socket programming
  * Date         : 01/01/2021
  * Version      : 1.0
  ***************************************************************************/
#include <stdio.h>      // standard I/O library
#include <stdlib.h>     // standard library
#include <sys/types.h>  // system data types
#include <sys/socket.h> // socket API
#include <netinet/in.h> // Internet protocol family
#include <string.h>     // string functions
#include <arpa/inet.h>  // for inet_ntop()

#define PORT 8080       // port number
#define MAX_CONNECTIONS 5

int main() {

    int socket_fd, new_socket, connection_status, read_value;
    struct sockaddr_in server_address, client_address;
    char buffer[256] = {0};
    const char* message = "Hello, this message is from server";
    int addrlen = sizeof(server_address);
    char client_ip[INET_ADDRSTRLEN];
    
    // create socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    // bind the socket to address
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // listen for connections
    if (listen(socket_fd, MAX_CONNECTIONS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Listening on port: %d \n", PORT);
    
    // accept incoming connections
    if ((new_socket = accept(socket_fd, (struct sockaddr *)&server_address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    
    // get client IP address
    inet_ntop(AF_INET, &client_address.sin_addr, client_ip, INET_ADDRSTRLEN);
    printf("New connection from: %s:%d\n", client_ip, ntohs(client_address.sin_port));
    
    // send message to client
    send(new_socket, message, strlen(message), 0);
    printf("Message sent to client: %s \n", message);
    
    // read data from client
    read_value = read(new_socket, buffer, sizeof(buffer));
    printf("Data from client: %s \n", buffer);
    
    close(socket_fd); // close socket file descriptor
    return 0;
}