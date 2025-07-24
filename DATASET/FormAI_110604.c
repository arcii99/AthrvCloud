//FormAI DATASET v1.0 Category: Simple Web Server ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int server_socket, client_socket;
    socklen_t client_size;
    struct sockaddr_in server_addr, client_addr;
    char buf[BUF_SIZE];
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><head><title>C Simple Web Server</title></head><body><h1>Hello World!</h1></body></html>";
    int response_len = strlen(response);

    // read port from command line argument
    int port = atoi(argv[1]);
    
    // create server socket
    server_socket = socket(PF_INET, SOCK_STREAM, 0);
    
    // setup server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);
    
    // bind socket to server address
    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    
    // listen for client connections
    listen(server_socket, 5);
    printf("Listening on port %d...\n", port);
    
    while(1) {
        // accept client connection
        client_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_size);
        
        // read client request
        memset(buf, 0, BUF_SIZE);
        read(client_socket, buf, BUF_SIZE-1);
        printf("<-- Client Request -->\n%s\n", buf);
        
        // send response to client
        write(client_socket, response, response_len);
        printf("<-- Server Response -->\n%s\n", response);
        
        // close client connection
        close(client_socket);
    }
    
    // close server socket
    close(server_socket);
    
    return 0;
}