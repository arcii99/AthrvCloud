//FormAI DATASET v1.0 Category: Simple Web Server ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main() {

    // create a socket for the server
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // check if socket creation was successful
    if(server_fd == -1) {
        perror("Failed to create socket.");
        return -1;
    }

    // configure the socket's address settings
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // bind the socket to the address and port
    if(bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind socket.");
        return -1;
    }

    // listen for incoming connections
    if(listen(server_fd, 3) == -1) {
        perror("Failed to listen for incoming connections.");
        return -1;
    }

    // accept incoming connection requests
    struct sockaddr_in client_addr;
    int addrlen = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, (socklen_t*)&addrlen);

    // check if client connection was successful
    if(client_fd == -1) {
        perror("Failed to accept incoming connection.");
        return -1;
    }

    // read client request
    char request[1024] = {0};
    if(read(client_fd, request, 1024) == -1) {
        perror("Failed to read client request.");
        return -1;
    }

    // get the requested file name
    char* file_name = strtok(request, " ");
    file_name = strtok(NULL, " ");
    
    // check if file name is not empty
    if(file_name == NULL) {
        file_name = "index.html";
    }
    
    // construct file path string
    char file_path[100] = {0};
    sprintf(file_path, "./html_files/%s", file_name+1);

    // check if requested file exists
    FILE* file = fopen(file_path, "r");
    if(file == NULL) {
        char* response = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<h1>404 Not Found</h1>";
        send(client_fd, response, strlen(response), 0);
    } else {
        // read file contents
        fseek(file, 0, SEEK_END);
        int file_size = ftell(file);
        fseek(file, 0, SEEK_SET);
        char* file_contents = (char*) malloc(file_size);
        fread(file_contents, 1, file_size, file);
        fclose(file);

        // generate HTTP response
        char* response_header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
        send(client_fd, response_header, strlen(response_header), 0);
        send(client_fd, file_contents, file_size, 0);
        free(file_contents);
    }

    close(client_fd);
    close(server_fd);

    return 0;
}