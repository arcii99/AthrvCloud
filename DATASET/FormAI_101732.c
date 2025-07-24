//FormAI DATASET v1.0 Category: Socket programming ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char *hello = "Hello from the server";
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Wow, something went wrong with the socket creation");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Wow, something went wrong with setting socket options");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Oops, something went wrong with binding the socket to the address");
        exit(EXIT_FAILURE);
    }

    // Listening on the socket
    if (listen(server_fd, 3) < 0) {
        perror("Oh no, something went wrong with listening on the socket");
        exit(EXIT_FAILURE);
    }

    printf("The server is up and running. Good job!\n");
    while (1) {
        // Accepting incoming connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("Oops, something went wrong with accepting incoming connections");
            exit(EXIT_FAILURE);
        }

        printf("The server successfully accepted an incoming connection. Bravo!\n");

        // Reading incoming messages
        valread = read(new_socket, buffer, 1024);
        printf("%s\n",buffer );

        // Sending a message back to the client
        send(new_socket, hello, strlen(hello), 0 );
        printf("The server successfully sent a message back to the client. You rock!\n");
    }
    return 0;
}