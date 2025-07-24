//FormAI DATASET v1.0 Category: Simple Web Server ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CONNECTIONS 100

void handle_client(int client_fd) {
    char buffer[1024];
    int n;
    memset(buffer, 0, sizeof(buffer));
    n = read(client_fd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("Error reading from client socket");
        exit(1);
    }
    printf("Received request from client: %s", buffer);
    char* response = "HTTP/1.1 200 OK\nContent-Length: 13\n\nHello, World!";
    n = write(client_fd, response, strlen(response));
    if (n < 0) {
        perror("Error writing to client socket");
        exit(1);
    }
    close(client_fd);
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    // create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }
    // set socket options to allow reuse of address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(1);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    // bind socket to specified address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(1);
    }
    // listen for client connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("listen failed");
        exit(1);
    }
    printf("Server listening on port %d...\n", PORT);
    while(1) {
        // accept client connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(1);
        }
        handle_client(client_fd);
    }
    return 0;
}