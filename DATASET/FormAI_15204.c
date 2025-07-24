//FormAI DATASET v1.0 Category: Simple Web Server ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(){
    printf("What? A simple web server program, really? I am surprised!\n");

    // Create a socket for the server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the server address to the socket
    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    // Listen for connections
    listen(server_socket, 5);

    // Accept and handle incoming connections
    while(1){
        int client_socket = accept(server_socket, NULL, NULL);
        printf("Got a connection! Time to send some data...\n");

        // Define the response headers and body
        char* response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello World!</h1></body></html>";

        // Send the response to the client
        send(client_socket, response, strlen(response), 0);

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);
    return 0;
}