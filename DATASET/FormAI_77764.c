//FormAI DATASET v1.0 Category: Networking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8000
#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 1024

int main() {
    // create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Failed to create socket");
        exit(1);
    }
    
    // set options for socket
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Failed to set socket options");
        exit(1);
    }
    
    // create server address struct
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // bind socket to server address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind socket to address");
        exit(1);
    }
    
    // listen for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) == -1) {
        perror("Failed to listen for connections");
        exit(1);
    }
    
    // accept incoming connections and handle requests
    while (1) {
        int client_fd;
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        
        printf("Waiting for connections...\n");
        
        // accept incoming connection
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            perror("Error accepting connection");
            exit(1);
        }
        
        printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        
        // receive request from client
        char buffer[BUFFER_SIZE] = {0};
        int bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            perror("Error receiving request");
            exit(1);
        }
        
        printf("Received request: %s\n", buffer);
        
        // send response to client
        char *response = "Hello from server!";
        int bytes_sent = send(client_fd, response, strlen(response), 0);
        if (bytes_sent == -1) {
            perror("Error sending response");
            exit(1);
        }
        
        printf("Sent response: %s\n", response);
        
        // close connection with client
        close(client_fd);
    }
    
    // close server socket
    close(server_fd);
    
    return 0;
}