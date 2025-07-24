//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int socket_fd, port_number, bytes_read;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *request_string = "GET / HTTP/1.1\r\nHost:www.google.com\r\nConnection: close\r\n\r\n";
    
    // Create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    if (inet_pton(AF_INET, "172.217.7.174", &server_addr.sin_addr) <= 0) {
        perror("Invalid Address / Address not supported");
        exit(EXIT_FAILURE);
    }
    
    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }
    
    // Send HTTP request
    if (send(socket_fd, request_string, strlen(request_string), 0) < 0) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }
    
    // Receive HTTP response
    while ((bytes_read = recv(socket_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        printf("%.*s", bytes_read, buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }

    if (bytes_read < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(socket_fd);
    return 0;
}