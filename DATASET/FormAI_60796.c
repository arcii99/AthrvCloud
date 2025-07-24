//FormAI DATASET v1.0 Category: Simple Web Server ; Style: detailed
/*
Simple Web Server in C
Author: [Your Name]

Description:
This program is a simple web server that listens on port 8080. It reads HTTP requests from clients, processes them,
and sends back the requested files in response.

Dependencies:
- Socket programming in C
- File I/O in C
- HTTP protocol

To run the program, compile it using gcc and run it from the command line. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

#define PORT 8080 // Port number to listen on
#define MAX_CONN 10 // Maximum number of connections to accept
#define BUFFER_SIZE 2048 // Maximum buffer size for requests

int main()
{
    int sockfd, new_sockfd; // Socket file descriptors
    struct sockaddr_in serv_addr, cli_addr; // Server and client addresses
    socklen_t clilen;
    char buffer[BUFFER_SIZE];

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the port
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(sockfd, MAX_CONN);
    printf("Server listening on port %d...\n", PORT);

    while (1) {
        clilen = sizeof(cli_addr);

        // Accept the incoming connection
        new_sockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (new_sockfd < 0) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        // Process the incoming request
        memset(buffer, 0, BUFFER_SIZE);
        read(new_sockfd, buffer, BUFFER_SIZE);

        // Extract the requested file path from the request
        char *path = strtok(buffer, " ");
        path = strtok(NULL, " ");
        path++; // Remove the leading slash

        // Check if the requested file exists
        int filefd = open(path, O_RDONLY);
        if (filefd < 0) {
            // If the file does not exist, send a 404 error message
            char error_buffer[1024];
            memset(error_buffer, 0, 1024);
            sprintf(error_buffer, "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<html><body><h1>404 Not Found</h1></body></html>\n");
            write(new_sockfd, error_buffer, strlen(error_buffer));

        } else {
            // If the file exists, send its contents as the response
            char file_buffer[BUFFER_SIZE];
            memset(file_buffer, 0, BUFFER_SIZE);
            int bytes_read = read(filefd, file_buffer, BUFFER_SIZE);
            char header_buffer[1024];
            memset(header_buffer, 0, 1024);
            sprintf(header_buffer, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n", bytes_read);
            write(new_sockfd, header_buffer, strlen(header_buffer));
            write(new_sockfd, file_buffer, bytes_read);
            close(filefd);
        }

        // Close the connection
        close(new_sockfd);
    }

    // Close the server socket
    close(sockfd);
    return 0;
}