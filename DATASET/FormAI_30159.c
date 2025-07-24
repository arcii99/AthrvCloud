//FormAI DATASET v1.0 Category: Simple Web Server ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080 // specify port number

int main(int argc, char const *argv[]) {
    int server_sock, new_sock, val_read;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, World!</h1></body></html>";
    char buffer[1024] = {0};

    // create server socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // assign IP address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind the socket to the address and port number
    if (bind(server_sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // wait for incoming connections
    if (listen(server_sock, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // handle incoming connections
    while ((new_sock = accept(server_sock, (struct sockaddr *)&address, (socklen_t *)&addrlen)) > -1) {
        val_read = read(new_sock, buffer, 1024);

        if (val_read == 0) {
            printf("Client disconnected\n");
            break;
        }

        printf("%s\n", buffer);

        // send response to client
        send(new_sock, response, strlen(response), 0);
        printf("Response sent\n");

        close(new_sock); // close socket
    }

    close(server_sock); // close server socket
    return 0;
}