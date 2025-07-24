//FormAI DATASET v1.0 Category: Simple Web Server ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888
#define MAX_BUFF_SIZE 1024

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, val_read;
    struct sockaddr_in address;
    int opt = 1;
    int add_len = sizeof(address);
    char buffer[MAX_BUFF_SIZE] = {0};
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: 37\n\n<html><body><h1>Welcome to my server!</h1></body></html>";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Socket creation error\n");
        return -1;
    }

    // Set socket options to reuse address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Setsockopt error\n");
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("Bind error\n");
        return -1;
    }

    // Listen for incoming requests
    if (listen(server_fd, 3) < 0) {
        printf("Listen error\n");
        return -1;
    }

    printf("Server has started and is listening on 127.0.0.1:%d\n", PORT);

    while (1) {
        // Accept incoming request
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&add_len)) < 0) {
            printf("Accept error\n");
            continue;
        }

        // Read incoming request
        if ((val_read = read(new_socket, buffer, MAX_BUFF_SIZE)) < 0) {
            printf("Read error\n");
            continue;
        }

        // Send response
        write(new_socket, response, strlen(response));

        // Close the socket
        close(new_socket);
    }

    return 0;
}