//FormAI DATASET v1.0 Category: Simple Web Server ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void parse_request(char request[], char filename[])
{
    char *token;
    token = strtok(request, " ");
    token = strtok(NULL, " ");
    strcpy(filename, token);
}

int main(int argc, char *argv[]) 
{
    int server_fd, client_fd, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[BUFFER_SIZE] = {0}; 
    char filename[BUFFER_SIZE] = {0};
    
    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Bind socket to port
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( atoi(argv[1]) ); 
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Accept incoming connections
    while(1)
    {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
        { 
            perror("accept"); 
            exit(EXIT_FAILURE); 
        } 
        
        // Receive request
        valread = read(client_fd, buffer, BUFFER_SIZE); 
        
        // Parse request and get filename
        parse_request(buffer, filename); 
        
        // Open file and send response
        FILE *fp = fopen(filename, "r");
        if(fp == NULL)
        {
            char *error_message = "HTTP/1.1 404 Not Found\n\n";
            send(client_fd, error_message, strlen(error_message), 0);
        } else {
            char content[BUFFER_SIZE] = {0};
            char *http_response = "HTTP/1.1 200 OK\n\n";
            send(client_fd, http_response, strlen(http_response), 0);
            while(fgets(content, BUFFER_SIZE, fp) != NULL)
                send(client_fd, content, strlen(content), 0);
            fclose(fp);
        }
        
        // Close connection
        close(client_fd);
    }
    
    return 0; 
}