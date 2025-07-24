//FormAI DATASET v1.0 Category: Simple Web Server ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFSIZ 1024

int main(){
    int socket_fd, new_socket_fd, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFSIZ] = {0};
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<!DOCTYPE html><html><head><title>Medieval Web Server</title></head><body><h1>Greetings, traveler!</h1><p>The server is pleased to serve thee!</p></body></html>";

    // Creating socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Reusing socket address
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Binding socket to address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for client connections
    if (listen(socket_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accepting client connections and sending response
    while(1) {
        if ((new_socket_fd = accept(socket_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){
            perror("accept");
            exit(EXIT_FAILURE);
        }
        valread = read(new_socket_fd, buffer, BUFSIZ);
        printf("%s\n", buffer);
        write(new_socket_fd, response, strlen(response));
        close(new_socket_fd);
    }

    return 0;
}