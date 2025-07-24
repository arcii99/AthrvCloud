//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFF_SIZE 1024 // Buffer size for incoming requests
#define PORT 8080 // Port number for the proxy

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFF_SIZE] = {0};
      
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
      
    // Set socket options to allow multiple connections
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
      
    // Bind the socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
      
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("Proxy is listening on port %d...\n", PORT);

    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Read incoming request from client
    valread = read( new_socket , buffer, BUFF_SIZE);
    printf("%s\n", buffer);
    
    // Modify request to include proxy information
    char send_buffer[BUFF_SIZE + 100] = {0};
    char* request_line = strtok(buffer, "\n");
    sprintf(send_buffer, "%s %s %s\r\nProxy-Connection: Keep-Alive\r\nProxy-Connection: close\r\n\r\n", request_line, "HTTP/1.1", "Host: localhost:8080");

    // Connect to the requested server
    struct sockaddr_in server_address;
    int server_socket, connection_status;
    char* host_start = strstr(request_line, "Host: ");
    char* host_end = strstr(host_start, "\r\n") - 6;
    char* host = (char*) malloc(host_end - host_start + 1);
    strncpy(host, host_start + 6, host_end - host_start);
    host[host_end - host_start] = '\0';
    printf("Requested host: %s\n", host);
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
      
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, host, &server_address.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    
    // Connect to server
    if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }
    printf("Connected to server: %s\n", host);
    
    // Send modified request to server
    if (send(server_socket, send_buffer, strlen(send_buffer), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }
    printf("Sent request to server\n");
    
    // Receive response from server
    char server_buffer[BUFF_SIZE] = {0};
    while ((connection_status = read(server_socket, server_buffer, sizeof(server_buffer))) > 0) {
        // Send response back to client
        if (send(new_socket, server_buffer, connection_status, 0) < 0) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }
        memset(server_buffer, 0, BUFF_SIZE);
    }
    printf("Proxy received response from server\n");
    shutdown(server_socket, SHUT_RDWR);
    shutdown(new_socket, SHUT_RDWR);
    close(server_socket);
    close(new_socket);

    return 0;
}