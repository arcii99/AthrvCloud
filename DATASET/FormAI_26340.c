//FormAI DATASET v1.0 Category: Chat server ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for incoming connections...\n");

    while(1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&address)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Client %s:%d connected!\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        if (fork() == 0) {
            while(1) {
                valread = read(new_socket, buffer, BUFFER_SIZE);

                if (valread <= 0) {
                    printf("Client %s:%d disconnected!\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                    break;
                }

                printf("Message from %s:%d -> %s\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port), buffer);
                memset(buffer, 0, BUFFER_SIZE);
            }

            close(new_socket);
            exit(EXIT_SUCCESS);
        }

        close(new_socket);
    }

    return 0;
}