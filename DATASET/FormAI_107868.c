//FormAI DATASET v1.0 Category: Simple Web Server ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 8080
#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

int main(){
    int server_socket, client_socket;
    int opt = 1;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE] = {0};
    char *response = NULL;

    // Create a socket
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if(setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    // Set server address details
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the specified address and port
    if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0){
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if(listen(server_socket, MAX_CONNECTIONS) < 0){
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Server is up and running on port %d\n", PORT);

    while(1){
        int address_size = sizeof(client_address);

        // Accept incoming connection
        if((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&address_size)) < 0){
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        printf("New connection established from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Read the client request
        memset(buffer, 0, BUFFER_SIZE);
        int buffer_size = read(client_socket, buffer, BUFFER_SIZE);
        printf("Received request:\n%s\n", buffer);

        // Generate response
        response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><head><title>Simple Web Server</title></head><body><h1>Welcome to the Simple Web Server example program</h1></body></html>";
        
        // Write the response to the client
        int response_size = strlen(response);
        write(client_socket, response, response_size);

        // Close the client socket
        close(client_socket);

        printf("Connection closed\n");
    }

    // Close the server socket
    close(server_socket);

    return 0;
}