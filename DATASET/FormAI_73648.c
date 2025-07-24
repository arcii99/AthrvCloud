//FormAI DATASET v1.0 Category: Networking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000

int main(int argc, char *argv[]) {
    int socket_fd, new_socket_fd, val_read;
    struct sockaddr_in server_address;
    char message[] = "Hello from server!";
    char buffer[1024] = {0};

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(socket_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started listening on port %d\n", PORT);

    while (1) {
        if ((new_socket_fd = accept(socket_fd, (struct sockaddr *) &server_address, (socklen_t *) &server_address)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected. IP address: %s, port number: %d\n", inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port));

        send(new_socket_fd, message, strlen(message), 0);

        val_read = read(new_socket_fd, buffer, 1024);
        printf("Received message from client: %s\n", buffer);

        close(new_socket_fd);
    }

    close(socket_fd);

    return 0;
}