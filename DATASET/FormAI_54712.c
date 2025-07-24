//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main(){
    int server_socket;
    char buffer[1024];

    // Creating a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Defining the address structure
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Binding the socket to the IP address and port
    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    // Listening for incoming connections
    listen(server_socket, 5);

    printf("Server running on http://127.0.0.1:9002/\n");

    while(1){

        // Accepting incoming connection requests
        int client_socket;
        client_socket = accept(server_socket, NULL, NULL);

        // Receiving the request
        recv(client_socket, buffer, 1024, 0);

        // Sending the response
        char *message = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE html><html><head><title>Hello World</title></head><body><h1>Hello World!</h1></body></html>";
        send(client_socket, message, strlen(message), 0);

        // Closing the connection
        close(client_socket);
    }

    return 0;
}