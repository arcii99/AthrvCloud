//FormAI DATASET v1.0 Category: Networking ; Style: Donald Knuth
/*
* Title: Networking with Donald Knuth style
* Author: Chatbot
* Email: chatbot@domain.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_MSG_LEN 1024

int main(int argc, char const *argv[]) {
    int sock_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char msg[MAX_MSG_LEN] = {0};
    char* hello = "Hello from the other side";
    
    // Create socket file descriptor
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind socket to address and port
    if (bind(sock_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(sock_fd, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }
    
    // Accept incoming connection
    if ((new_socket = accept(sock_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    
    // Read data from socket
    valread = read(new_socket, msg, MAX_MSG_LEN);
    printf("%s\n", msg);
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    
    // Close sockets
    close(new_socket);
    close(sock_fd);
    
    return 0;
}