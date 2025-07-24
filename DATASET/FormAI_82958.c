//FormAI DATASET v1.0 Category: Simple Web Server ; Style: energetic
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

int main() {

    int server_fd, client_socket, val_read;
    struct sockaddr_in address;
    int opt = 1;
    char response[1024] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<!DOCTYPE html>\n<html>\n<body>\n<h1>C Simple Web Server is running</h1>\n</body>\n</html>";


    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Setting options of the socket
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        return -1;
    }

    // Setting address info for socket
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        return -1;
    }

    // Listening on the socket with a queue of length 3
    if (listen(server_fd, 3) < 0) {
        perror("Listening failed");
        return -1;
    }

    // Accepting a connection
    if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&address)) < 0) {
        perror("Accept failed");
        return -1;
    }

    // Reading a request from the client
    char buffer[30000] = {0};
    val_read = read(client_socket, buffer, 30000);
    printf("%s\n", buffer);

    // Sending a response to the client
    send(client_socket, response, strlen(response), 0);

    printf("Response sent\n");

    return 0;
}