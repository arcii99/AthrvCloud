//FormAI DATASET v1.0 Category: Simple Web Server ; Style: irregular
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

void send_response(int conn_fd) {
    char* response_body = "Hello, World!";
    char response_header[300];

    sprintf(response_header, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\nConnection: close\r\n\r\n", strlen(response_body));
    write(conn_fd, response_header, strlen(response_header));
    write(conn_fd, response_body, strlen(response_body));
    close(conn_fd);
}

int main() {
    int server_fd, conn_fd;

    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if(listen(server_fd, 10) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while(1) {
        conn_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
        if(conn_fd < 0) {
            perror("accept");
            continue;
        }

        send_response(conn_fd);
    }

    return 0;
}