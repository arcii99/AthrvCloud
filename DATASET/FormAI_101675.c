//FormAI DATASET v1.0 Category: Socket programming ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    char clientIP[INET_ADDRSTRLEN];
    printf("Client connected with IP address: %s\n", inet_ntop(AF_INET, &address.sin_addr, clientIP, INET_ADDRSTRLEN));

    while (1) {
        valread = read(new_socket, buffer, 1024);
        printf("Client: %s\n", buffer);

        if (strcmp(buffer, "exit\n") == 0) {
            printf("Client disconnected\n");
            break;
        }

        send(new_socket, hello, strlen(hello), 0);
        printf("Server: Hello message sent\n");
        memset(buffer, 0, sizeof(buffer));
    }
    close(new_socket);
    close(server_fd);
    return 0;
}