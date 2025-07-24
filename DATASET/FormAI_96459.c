//FormAI DATASET v1.0 Category: Simple Web Server ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define PORT 8080
#define MAX_SIZE 1024

int main(int argc, char *argv[])
{
    int server_fd, client_fd, read_size, file_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_SIZE] = {0};
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
    {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
       
    // Bind socket to a port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    while(1)
    {
        // Accept incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        printf("Connection accepted\n");
        
        // Read HTTP request from client
        char filename[MAX_SIZE] = {0};
        if((read_size = read(client_fd, buffer, MAX_SIZE)) > 0)
        {
            sscanf(buffer, "GET /%s HTTP/1.1", filename);
        }
        else
        {
            perror("Read failed");
            exit(EXIT_FAILURE);
        }
        
        printf("Requested file: %s\n", filename);
        
        // Open requested file
        char filepath[MAX_SIZE] = {0};
        sprintf(filepath, "./%s", filename);
        if((file_fd = open(filepath, O_RDONLY)) == -1)
        {
            perror("Open failed");
            exit(EXIT_FAILURE);
        }
        
        // Get file size
        struct stat file_stat;
        if (fstat(file_fd, &file_stat) == -1)
        {
            perror("Fstat failed");
            exit(EXIT_FAILURE);
        }
        int file_size = file_stat.st_size;
        
        // Send HTTP response header to client
        char response_header[MAX_SIZE] = {0};
        sprintf(response_header, "HTTP/1.1 200 OK\nContent-Length: %d\n\n", file_size);
        write(client_fd, response_header, strlen(response_header));
        
        // Send file content to client
        int remaining_size = file_size;
        char file_content[MAX_SIZE];
        while ((read_size = read(file_fd, file_content, MAX_SIZE)) > 0 && remaining_size > 0)
        {
            write(client_fd, file_content, read_size);
            remaining_size -= read_size;
        }
        
        printf("File sent\n");
        
        // Close file descriptor and client socket
        close(file_fd);
        close(client_fd);
    }
    
    return 0;
}