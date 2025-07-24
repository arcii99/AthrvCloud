//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

#define PORT 8080 // Server Port

int main(int argc, char const *argv[]) {

    int socket_fd, new_socket, valread;
    struct sockaddr_in server_address;
    char buffer[1024] = {0};
    char *hello = "Hello from server!";

    // Creating Socket File Descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Specifying IPv4 type for socket and assigning Port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Binding the socket to the given port and address
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(socket_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accepting a new connection and handling it
    if ((new_socket = accept(socket_fd, (struct sockaddr *)&server_address, (socklen_t*)&server_address))<0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Receiving data from the client
    valread = read(new_socket , buffer, 1024);
    printf("%s\n",buffer );
    send(new_socket , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
    return 0;
}