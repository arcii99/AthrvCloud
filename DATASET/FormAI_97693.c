//FormAI DATASET v1.0 Category: Simple Web Server ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

void handle_client(int sock) {
    char http_response[] = "HTTP/1.1 200 OK\r\n\r\n<!DOCTYPE html><html><head><title>Welcome to Retro Web Server</title><style>body{text-align: center;font-size: 36px;background: #000;color: #fff;}</style></head><body><h1>Welcome to Retro Web Server</h1></body></html>";
    char buffer[1024] = {0};
    read(sock, buffer, 1024);
    printf("Request:\n%s\n", buffer);
    write(sock, http_response, strlen(http_response));
    close(sock);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Retro Web Server started at http://127.0.0.1:%d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        handle_client(new_socket);
    }
    return 0;
}