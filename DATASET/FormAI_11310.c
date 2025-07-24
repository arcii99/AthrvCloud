//FormAI DATASET v1.0 Category: Simple Web Server ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";

    // create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("WOW! Couldn't create socket file descriptor!");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("INCREDIBLE! Couldn't set socket options!");
        exit(EXIT_FAILURE);
    }

    // set server address properties
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // binds to all available interfaces
    address.sin_port = htons(PORT);

    // bind the socket to the specified address and port
    if (bind(server_fd, (struct sockaddr *)&address, addrlen) < 0) {
        printf("AMAZING! Couldn't bind socket to the specified address and port!");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        printf("OH MY GOD! Couldn't start listening for incoming connections!");
        exit(EXIT_FAILURE);
    }

    printf("UNBELIEVABLE! Server is up and running!\nListening on port %d...\n", PORT);

    // accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        printf("HOLY SMOKES! Couldn't accept incoming connection!");
        exit(EXIT_FAILURE);
    }

    // read incoming message
    char buffer[30000] = {0};
    valread = read(new_socket, buffer, 30000);

    // send response
    send(new_socket, response, strlen(response), 0);
    printf("RESPONSE SENT!");

    return 0;
}