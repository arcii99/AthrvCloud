//FormAI DATASET v1.0 Category: Networking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#define PORT 8080
#define MAX_PENDING_CONNECTIONS 10
#define MAX_BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER_SIZE] = {0};
    char* hello_message = "Hello from server!";
    int message_len = strlen(hello_message);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
            &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_PENDING_CONNECTIONS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Waiting for new connection...\n");

        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        memset(buffer, 0, MAX_BUFFER_SIZE);

        int recv_len = recv(new_socket, buffer, MAX_BUFFER_SIZE, 0);
        if (recv_len < 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        printf("Received message from client: %s\n", buffer);
        printf("Sending message to client: %s\n", hello_message);

        int send_len = send(new_socket, hello_message, message_len, 0);
        if (send_len < 0) {
            perror("send");
            exit(EXIT_FAILURE);
        }

        close(new_socket);
    }

    return 0;
}