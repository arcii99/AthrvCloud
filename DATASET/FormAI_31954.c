//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int socket_fd, new_socket, client_len, read_val;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = {0};
    const char *response_message = "Hello from server!";

    // Creating socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Assigning IP, PORT
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding socket to IP and PORT
    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming client connections
    if (listen(socket_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    client_len = sizeof(client_addr);

    while (1) {
        // Accepting incoming client connection
        if ((new_socket = accept(socket_fd, (struct sockaddr *)&client_addr, (socklen_t*)&client_len)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Receiving data from client
        read_val = read(new_socket, buffer, 1024);
        printf("Received message from client: %s\n", buffer);

        // Sending data back to client
        send(new_socket, response_message, strlen(response_message), 0);
        printf("Message sent to client: %s\n", response_message);
    }
    
    return 0;
}