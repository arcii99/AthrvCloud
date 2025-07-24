//FormAI DATASET v1.0 Category: Networking ; Style: cheerful
#include <stdio.h> // Standard IO library
#include <stdlib.h> // Standard Library
#include <string.h> // String Library
#include <sys/socket.h> // Socket Library
#include <netinet/in.h> // Network Library
#include <unistd.h> // Unix Standard Library

#define PORT 8080 // Setting the Port number for the server

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from the other side!";

    // Creating Socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                    &opt, sizeof(opt))) {
        perror("Socket options setting failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding socket to the address and port number
    if (bind(server_fd, (struct sockaddr *)&address,
                sizeof(address))<0) {
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }

    // Listening to the incoming connection requests
    if (listen(server_fd, 3) < 0) {
        perror("Socket listening failed");
        exit(EXIT_FAILURE);
    }

    // Accepting incoming connection requests and
    // building the connection between client and server
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                        (socklen_t*)&addrlen))<0) {
        perror("Connection acceptance failed");
        exit(EXIT_FAILURE);
    }

    // Sending a cheerful hello message to the client
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent to the client!\n");

    // Reading the message sent by the client
    valread = read(new_socket, buffer, 1024);
    printf("%s\n",buffer );
    return 0;
}