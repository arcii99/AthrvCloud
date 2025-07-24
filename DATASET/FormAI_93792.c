//FormAI DATASET v1.0 Category: System administration ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
 
int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *msg = "Hello from server!";
       
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
       
    // Setting socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
       
    // Binding the socket to localhost:8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    while(1) {
        // Accepting client connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("New connection from %s:%d\n",inet_ntoa(address.sin_addr),ntohs(address.sin_port));
        
        // Sending message to client
        if(send(new_socket, msg, strlen(msg), 0) != strlen(msg)) {
            perror("send");
        }
        printf("Hello message sent to %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
        memset(buffer, 0, sizeof buffer);
        // Receiving message from client
        valread = read(new_socket , buffer, 1024);
        if(valread == 0) {
            printf("Connection closed by %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
            close(new_socket);
            continue;
        } else if(valread < 0) {
            perror("read");
            close(new_socket);
            continue;
        }
        printf("%s\n", buffer);
    }
    return 0;
}