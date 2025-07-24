//FormAI DATASET v1.0 Category: Socket programming ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUF_SIZE 1024

int main(int argc, char const *argv[]) {
    int sock_fd, new_socket, val_read;
    struct sockaddr_in address;
    int opt = 1;
    int addr_len = sizeof(address);
    char buffer[BUF_SIZE] = {0};
    char *hello = "Hello from server!";
       
    // Creating socket file descriptor
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port 8080
    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
       
    // Binding socket at port 8080
    if (bind(sock_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening to incoming client requests
    if (listen(sock_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Handling incoming client requests
    while (1) {
        if ((new_socket = accept(sock_fd, (struct sockaddr *)&address, (socklen_t*)&addr_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
    
        // Receiving data from client
        val_read = read(new_socket, buffer, BUF_SIZE);
        printf("Received message from client: %s\n", buffer);
        // Sending the response to client
        send(new_socket, hello, strlen(hello), 0);
        printf("Hello message sent to the client.\n");
        memset(buffer, 0, BUF_SIZE);
    }
    return 0;
}