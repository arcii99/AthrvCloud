//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define RESPONSE_OK "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
#define RESPONSE_ERROR "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n"
#define RESPONSE_BODY "<html><body><h1>Welcome to the matrix!</h1><p>This is a test Cyberpunk style web server.</p><p>You are connected to the grid.</p></body></html>"

int main(int argc, char const *argv[]) {
    int socket_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = {0};
    int buffer_size = 1024;
    int opt = 1;
    int client_addr_len = sizeof(client_addr);
    
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    if (listen(socket_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    
    while (1) {
        if ((client_fd = accept(socket_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr_len)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        
        read(client_fd, buffer, buffer_size);
        
        if (strstr(buffer, "GET / HTTP")) {
            send(client_fd, RESPONSE_OK, strlen(RESPONSE_OK), 0);
            send(client_fd, RESPONSE_BODY, strlen(RESPONSE_BODY), 0);
        }
        else {
            send(client_fd, RESPONSE_ERROR, strlen(RESPONSE_ERROR), 0);
        }
        
        close(client_fd);
    }

    return 0;
}