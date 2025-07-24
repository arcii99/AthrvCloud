//FormAI DATASET v1.0 Category: Chat server ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
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
    printf("Server is running at port %d\n", PORT);
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        char *ip = inet_ntoa(address.sin_addr);
        int port = ntohs(address.sin_port);
        printf("New connection from %s:%d\n", ip, port);

        pid_t child_process_id = fork();
        if (child_process_id < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (child_process_id == 0) {
            // This is child process
            close(server_fd);
            while (1) {
                memset(buffer, 0, BUFFER_SIZE);
                valread = read(new_socket, buffer, BUFFER_SIZE);
                if (valread <= 0) {
                    printf("Connection from %s:%d closed\n", ip, port);
                    exit(EXIT_SUCCESS);
                }
                printf("[%s:%d]: %s", ip, port, buffer);
                if (!strncmp(buffer, "bye", 3)) {
                    printf("Connection from %s:%d closed\n", ip, port);
                    exit(EXIT_SUCCESS);
                }
                send(new_socket, hello, strlen(hello), 0);
            }
        } else {
            // This is parent process
            close(new_socket);
        }
    }
    return 0;
}