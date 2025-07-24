//FormAI DATASET v1.0 Category: Chat server ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *message = "SERVER: Hello, I am a chat server written in C.";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while(1) {
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        if (!fork()) {
            printf("New client connected.\n");
            send(new_socket, message, strlen(message), 0);

            while(read(new_socket, buffer, 1024)) {
                if (strncmp(buffer, "exit", 4) == 0) {
                    printf("Client disconnected.\n");
                    close(new_socket);
                    break;
                }
                else if (strncmp(buffer, "shapeshift", 10) == 0) {
                    char transformed_buf[1024] = {0};
                    int buf_len = strlen(buffer);

                    for (int i = 0; i < buf_len; i++) {
                        if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                            transformed_buf[i] = buffer[i] - 32;
                        }
                        else if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                            transformed_buf[i] = buffer[i] + 32;
                        }
                        else {
                            transformed_buf[i] = buffer[i];
                        }
                    }

                    send(new_socket, transformed_buf, strlen(transformed_buf), 0);
                }
                else {
                    send(new_socket, buffer, strlen(buffer), 0);
                }

                memset(buffer, 0, sizeof(buffer));
            }
        }
    }

    return 0;
}