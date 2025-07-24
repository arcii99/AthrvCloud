//FormAI DATASET v1.0 Category: Simple Web Server ; Style: recursive
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <unistd.h> 
#include <string.h> 

#define PORT 8080 

void request_handler(int sockfd) {
    char buffer[1024] = {0}; 
    int status = read(sockfd, buffer, 1024);
    if (status < 0) { 
        fprintf(stderr, "read error");
        return;
    } 
    printf("Request received: %s", buffer); 
    char *msg = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nHello, World!\n"; 
    write(sockfd, msg, strlen(msg)); 
    close(sockfd); 
}

void start_server(int sockfd, struct sockaddr_in address) {
    int addrlen = sizeof(address); 
    while (1) {
        int new_sockfd = accept(sockfd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (new_sockfd < 0) { 
            fprintf(stderr, "accept error");
            return;
        } 
        start_server(new_sockfd, address);
    }
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd < 0) { 
        fprintf(stderr, "socket error");
        return 1;
    } 
    struct sockaddr_in address; 
    memset(&address, 0, sizeof(address)); 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 
    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) { 
        fprintf(stderr, "bind error");
        return 1;
    } 
    if (listen(sockfd, 10) < 0) { 
        fprintf(stderr, "listen error");
        return 1;
    } 
    start_server(sockfd, address);
    return 0; 
}