//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8888
#define PROXY_PORT 8080

void handle_client(int client_sockfd, struct sockaddr_in client_addr, struct sockaddr_in server_addr) {
    char buffer[BUFFER_SIZE];
    int server_sockfd, n, len;
    struct sockaddr_in server_addr_proxy;
    
    // Create a new socket
    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    
    // Set up server address for proxy
    memset(&server_addr_proxy, 0, sizeof(server_addr_proxy));
    server_addr_proxy.sin_family = AF_INET;
    server_addr_proxy.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr_proxy.sin_port = htons(PROXY_PORT);
    
    // Connect to server
    if (connect(server_sockfd, (struct sockaddr *)&server_addr_proxy, sizeof(server_addr_proxy)) < 0) {
        perror("Failed to connect to proxy server");
        exit(EXIT_FAILURE);
    }
    
    printf("Connected to proxy server...\n");
    
    // Send request to server
    printf("Sending request to server...\n");
    send(server_sockfd, buffer, strlen(buffer), 0);
    
    // Receive response from server
    printf("Receiving response from server...\n");
    while ((n = recv(server_sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        send(client_sockfd, buffer, n, 0);
    }
    
    printf("Response received from server...\n");
    
    // Close sockets
    close(server_sockfd);
    close(client_sockfd);
    
    printf("Sockets closed...\n");
}

int main() {
    int sockfd, client_sockfd, len;
    struct sockaddr_in server_addr, client_addr;
    
    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    
    printf("Socket created...\n");
    
    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);
    
    // Bind to port
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind to port");
        exit(EXIT_FAILURE);
    }
    
    printf("Socket bound to port...\n");
    
    // Listen for clients
    if (listen(sockfd, 5) < 0) {
        perror("Failed to listen for clients");
        exit(EXIT_FAILURE);
    }
    
    printf("Listening for clients...\n");
    
    while (1) {
        // Accept client connection
        len = sizeof(client_addr);
        if ((client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &len)) < 0) {
            perror("Failed to accept client connection");
            continue;
        }
        
        printf("Accepted client connection...\n");
        
        // Handle client request
        handle_client(client_sockfd, client_addr, server_addr);
        
        printf("Finished handling client request...\n");
    }
    
    // Close socket
    close(sockfd);
    
    printf("Socket closed...\n");
    
    return 0;
}