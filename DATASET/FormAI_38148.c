//FormAI DATASET v1.0 Category: Socket programming ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT_NUMBER 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<!DOCTYPE html>\n<html>\n<body>\n<h1>Welcome to my website!</h1>\n<p>Here is some text.</p>\n</body>\n</html>\n";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setting socket options failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT_NUMBER);

    // Binding the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding socket to the port failed");
        exit(EXIT_FAILURE);
    }

    // Listening for requests
    if (listen(server_fd, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d...\n", PORT_NUMBER);

    while (1) {

        // Accepting and processing new requests
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accepting new connection failed");
            exit(EXIT_FAILURE);
        }

        printf("New request from IP address %s, port %d.\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        valread = read(new_socket, buffer, BUFFER_SIZE);

        printf("Request:\n%s\n", buffer);

        write(new_socket, response, strlen(response));
        printf("Response sent.\n");

        close(new_socket);
        printf("Connection closed.\n");
    }

    return 0;
}