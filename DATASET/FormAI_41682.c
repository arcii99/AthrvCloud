//FormAI DATASET v1.0 Category: Networking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main() {
    // create socket
    int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }
    
    // server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(8080);
    
    // bind socket to address
    if (bind(server_socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        printf("Error binding socket to address.\n");
        exit(1);
    }
    
    // listen for incoming connections
    if (listen(server_socket_fd, 3) == -1) {
        printf("Error listening for incoming connections.\n");
        exit(1);
    }
    
    printf("Server is listening on port 8080.\n");
    
    while (1) {
        // accept incoming connection
        struct sockaddr_in client_address;
        int client_socket_fd = accept(server_socket_fd, (struct sockaddr*)&client_address, sizeof(client_address));
        if (client_socket_fd == -1) {
            printf("Error accepting incoming connection.\n");
            continue;
        }
        
        printf("Client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);
        
        // receive data from client
        int bytes_received = recv(client_socket_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            printf("Error receiving data from client.\n");
            close(client_socket_fd);
            continue;
        }
        
        printf("Received data from client: %s\n", buffer);
        
        // send response back to client
        char response[] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, World!</h1></body></html>";
        int bytes_sent = send(client_socket_fd, response, strlen(response), 0);
        if (bytes_sent == -1) {
            printf("Error sending response to client.\n");
            close(client_socket_fd);
            continue;
        }
        
        printf("Sent response to client.\n");
        
        // close client connection
        close(client_socket_fd);
    }
    
    // close server socket
    close(server_socket_fd);
    
    return 0;
}