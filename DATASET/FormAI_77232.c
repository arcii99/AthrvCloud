//FormAI DATASET v1.0 Category: Socket programming ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]){

    int socket_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int address_len = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port 8080
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Bind the socket to the supplied IP and port
    if (bind(socket_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(socket_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    if ((new_socket = accept(socket_fd, (struct sockaddr *)&address,
                   (socklen_t*)&address_len))<0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Receive data from the client
    valread = read(new_socket , buffer, BUFFER_SIZE);
    printf("Client message: %s\n",buffer );
    send(new_socket , "Server received the message" , strlen("Server received the message") , 0);

    // Close the sockets
    close(new_socket);
    close(socket_fd);

    return 0;
}