//FormAI DATASET v1.0 Category: Networking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int socket_fd, new_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE] = {0};
    int opt = 1;
    int addrlen = sizeof(struct sockaddr_in);

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(socket_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if ((new_fd = accept(socket_fd, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        int pid;
        if ((pid = fork()) == -1) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            close(socket_fd);
            char *welcome_message = "Welcome to the chat room\n";
            send(new_fd, welcome_message, strlen(welcome_message), 0);

            while (1) {
                int read_size = read(new_fd, buffer, BUFFER_SIZE);
                if (read_size == 0) {
                    printf("Client disconnected\n");
                    break;
                } else if (read_size == -1) {
                    perror("Read failed");
                    break;
                }

                printf("Received message: %s", buffer);

                if (strncmp(buffer, "quit", 4) == 0) {
                    printf("Client quit\n");
                    break;
                }

                bzero(buffer, BUFFER_SIZE);
            }

            close(new_fd);
            exit(EXIT_SUCCESS);
        }

        close(new_fd);
    }

    close(socket_fd);
    return 0;
}