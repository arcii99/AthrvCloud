//FormAI DATASET v1.0 Category: Simple Web Server ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char* argv[]) {

    int sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    char buffer[1024];

    bzero((char*) &server_addr, sizeof(server_addr));
    
    server_addr.sin_family = AF_INET; // IPv4 Address family
    server_addr.sin_addr.s_addr = INADDR_ANY; // INADDR_ANY binds the socket to all available interfaces on the host system
    server_addr.sin_port = htons(PORT); // convert host byte order to network byte order

    // Create a TCP socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(-1);
    }

    // Bind the socket to the given address and port
    if (bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Socket binding error");
        exit(-1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Socket listening error");
        exit(-1);
    }

    while (1) {
        printf("Waiting for incoming connections...\n");

        // Accept incoming connection
        if ((new_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len)) < 0) {
            perror("Socket accept error");
            exit(-1);
        }
        
        // Read HTTP request from client
        bzero(buffer, sizeof(buffer));
        read(new_sockfd, buffer, sizeof(buffer));
        printf("Received message: %s", buffer);
        
        // Construct an HTTP response
        char* response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 12\r\n\r\nHello World!\n";
        
        // Send HTTP response back to client
        write(new_sockfd, response, strlen(response));

        // Close TCP socket
        close(new_sockfd);
    }

    return 0;
}