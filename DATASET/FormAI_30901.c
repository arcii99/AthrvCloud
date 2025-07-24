//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: recursive
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define PORT 8080

void recursive_echo(int sockfd) {
    char buffer[1024] = {0};
    int valread = read(sockfd, buffer, 1024);
    if(valread > 0) {
        printf("Received: %s", buffer);
        fflush(stdout);
        send(sockfd, buffer, strlen(buffer), 0);
        memset(buffer, 0, 1024);
        recursive_echo(sockfd);
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt error");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);
    while(1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept error");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %d\n", new_socket);
        recursive_echo(new_socket);
    }
    return 0;
}