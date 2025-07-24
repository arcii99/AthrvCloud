//FormAI DATASET v1.0 Category: Simple Web Server ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int fd;
    int connection_fd;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    int addrlen = sizeof(client_address);
    int response_size;
    char buffer[BUFFER_SIZE] = {0};
    char response[] = "HTTP/1.1 200 OK\nContent-Type: text/html\nConnection: close\n\n<html><body><h1>Hello, World!</h1></body></html>\n";
    
    // create the socket
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error: Failed to create socket");
        exit(EXIT_FAILURE);
    }
    
    // bind the socket to the address and port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    if (bind(fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error: Failed to bind socket to address");
        exit(EXIT_FAILURE);
    }
    
    // start listening for incoming connections
    if (listen(fd, 3) < 0) {
        perror("Error: Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }
    
    printf("Web server running on port %d...\n", PORT);
    
    // accept incoming connections and send response message
    while (1) {
        if ((connection_fd = accept(fd, (struct sockaddr *)&client_address, (socklen_t*)&addrlen)) < 0) {
            perror("Error: Failed to accept incoming connection");
            continue;
        }
        
        response_size = strlen(response);
        
        if (write(connection_fd, response, response_size) != response_size) {
            perror("Error: Failed to send response message");
        }
        
        printf("Response message sent to client %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        close(connection_fd);
    }
    
    close(fd);
    return 0;
}