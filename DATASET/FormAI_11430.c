//FormAI DATASET v1.0 Category: Simple Web Server ; Style: detailed
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 

#define MAX_SIZE 1024 

int main(int argc, char const *argv[]) 
{ 
    int server_fd, client_fd, len; 
    struct sockaddr_in server_addr, client_addr; 
    char buffer[MAX_SIZE] = {0}; 
    int opt = 1; 

    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Binding socket to port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = INADDR_ANY; 
    server_addr.sin_port = htons(8080); 

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 

    len = sizeof(client_addr); 
    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&len)) < 0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 

    read(client_fd, buffer, MAX_SIZE); 
    printf("%s\n", buffer);
    char response[MAX_SIZE] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>\r\n";

    write(client_fd , response , strlen(response)); 
    close(client_fd); 
    close(server_fd); 
    return 0; 
}