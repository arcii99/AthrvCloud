//FormAI DATASET v1.0 Category: Simple Web Server ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

#define RESPONSE "HTTP/1.1 200 OK\r\nConnection: close\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Welcome to my C Simple Web Server!</h1></body></html>\r\n"

int main(int argc, char *argv[])
{
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
    {
        printf("Failed to create socket!\n");
        return -1;
    }
    
    // Prepare the socket address structure
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8888);
    
    // Bind the socket to the address and port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        printf("Failed to bind socket!\n");
        return -1;
    }
    
    // Listen for incoming connections
    if (listen(server_socket, 10) == -1)
    {
        printf("Failed to listen for connections!\n");
        return -1;
    }
    
    printf("Server started, listening at port %d...\n", ntohs(server_address.sin_port));
    
    // Accept incoming connections and serve responses
    while (1)
    {
        // Accept incoming connection
        struct sockaddr_in client_address;
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&client_address);
        if (client_socket == -1)
        {
            printf("Failed to accept incoming connection!\n");
            continue;
        }
        
        // Read the incoming request
        char request[1024] = {0};
        read(client_socket, request, 1024);
        printf("Incoming request: %s", request);
        
        // Serve response
        write(client_socket, RESPONSE, strlen(RESPONSE));
        
        // Close the client connection
        close(client_socket);
    }
    
    // Close the server socket
    close(server_socket);
    
    return 0;
}