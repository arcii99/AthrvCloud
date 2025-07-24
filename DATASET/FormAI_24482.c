//FormAI DATASET v1.0 Category: Socket programming ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void error(const char *msg){
    perror(msg);
    exit(1);
}

int paranoid_socket(int domain, int type, int protocol){
    int fd = socket(domain, type, protocol);
    if(fd == -1) error("Failed to create socket");
    int val = 1;
    if(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val)) == -1) error("Failed to setsockopt");
    return fd;
}

int paranoid_bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
    if(bind(sockfd, addr, addrlen) == -1) error("Failed to bind to socket");
    return 0;
}

int paranoid_listen(int sockfd, int backlog){
    if(listen(sockfd, backlog) == -1) error("Failed to start listening on socket");
    return 0;
}

int paranoid_accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen){
    int client_fd = accept(sockfd, addr, addrlen);
    if(client_fd == -1) error("Failed to accept client connection");
    return client_fd;
}

ssize_t paranoid_recv(int sockfd, void *buf, size_t len, int flags){
    ssize_t bytes = recv(sockfd, buf, len, flags);
    if(bytes == -1) error("Failed to receive data from client");
    return bytes;
}

ssize_t paranoid_send(int sockfd, const void *buf, size_t len, int flags){
    ssize_t bytes = send(sockfd, buf, len, flags);
    if(bytes == -1) error("Failed to send data to client");
    return bytes;
}

int main(){
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    int server_fd, client_fd, port = 8080, backlog = 10;
    char buffer[1024];
    
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    
    server_fd = paranoid_socket(AF_INET, SOCK_STREAM, 0);
    paranoid_bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    paranoid_listen(server_fd, backlog);
    
    while(1){
        client_len = sizeof(client_addr);
        client_fd = paranoid_accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        bzero(buffer, 1024);
        ssize_t bytes = paranoid_recv(client_fd, buffer, 1024, 0);
        printf("Received %ld bytes from client: %s\n", bytes, buffer);
        ssize_t sent_bytes = paranoid_send(client_fd, buffer, bytes, 0);
        printf("Sent %ld bytes to client\n", sent_bytes);
        close(client_fd);
    }
    
    return 0;
}