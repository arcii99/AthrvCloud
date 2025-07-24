//FormAI DATASET v1.0 Category: Networking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

int main(){
    int socket_fd, new_socket, val_read;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char *greeting = "Hello, this is the server!";

    // Creating socket file descriptor
    if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    if(setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("Setsockopt error");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the specified port
    if(bind(socket_fd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if(listen(socket_fd, 3) < 0){
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    printf("Server running on port %d\n", PORT);

    // Accepting incoming connections
    if((new_socket = accept(socket_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0){
        perror("Accept error");
        exit(EXIT_FAILURE);
    }

    char buffer[1024] = {0};
    val_read = read(new_socket, buffer, 1024);
    printf("%s\n", buffer);

    // Sending a greeting to the client
    send(new_socket, greeting, strlen(greeting), 0);

    return 0;
}