//FormAI DATASET v1.0 Category: Socket programming ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

#define PORT 8000

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = INADDR_ANY;

    int opt = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt error");
        exit(EXIT_FAILURE);
    }

    if (bind(sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding Failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 3) < 0) {
        perror("listen Failed");
        exit(EXIT_FAILURE);
    }

    int addrlen = sizeof(address);
    int new_socket;

    if ((new_socket = accept(sock, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("Accept Failed");
        exit(EXIT_FAILURE);
    }

    char* message = "Hello from server!";
    write(new_socket, message, strlen(message));

    char buffer[1024] = {0};
    read(new_socket, buffer, 1024);
    printf("Client message: %s\n", buffer);

    return 0;
}