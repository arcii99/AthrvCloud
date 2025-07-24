//FormAI DATASET v1.0 Category: Networking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int socket_fd, new_socket, read_val;
    struct sockaddr_in server_address, client_addr;
    char buffer[1024] = {0};
    char *welcome_msg = "Welcome to my C Networking server!\n";
    int addrlen = sizeof(server_address);
    
    // create socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket file descriptor creation failed");
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // bind socket to port
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Bind failed");
        return -1;
    }

    // listen for incoming connections
    if (listen(socket_fd, 3) < 0)
    {
        perror("Listen failed");
        return -1;
    }

    printf("Server is listening on port %d\n", PORT);

    // accept a client connection
    if ((new_socket = accept(socket_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0)
    {
        perror("Accept failed");
        return -1;
    }

    // send welcome message to connected client
    send(new_socket, welcome_msg, strlen(welcome_msg), 0);
    printf("Welcome message sent to client\n");

    // read data from client
    read_val = read(new_socket, buffer, 1024);
    printf("Client message: %s\n", buffer);
    
    // send message back to client
    char *response_msg = "Thanks for connecting to my C Networking server!\n";
    send(new_socket, response_msg, strlen(response_msg), 0);
    printf("Message sent back to client\n");

    close(new_socket);
    close(socket_fd);

    return 0;
}