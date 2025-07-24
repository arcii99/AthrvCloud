//FormAI DATASET v1.0 Category: Chat server ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 3000
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int server_fd, client_fd, max_fd, i, len, activity;
    struct sockaddr_in server, client;
    fd_set read_fds;
    char buffer[BUFFER_SIZE];
    int clients[MAX_CLIENTS] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat server listening on port %d\n", PORT);

    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);
        max_fd = server_fd;

        for (i = 0; i < MAX_CLIENTS; i++) {
            client_fd = clients[i];

            if (client_fd > 0) {
                FD_SET(client_fd, &read_fds);
            }

            if (client_fd > max_fd) {
                max_fd = client_fd;
            }
        }

        activity = select(max_fd + 1, &read_fds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("Select failed");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(server_fd, &read_fds)) {
            if ((client_fd = accept(server_fd, (struct sockaddr *)&client, (socklen_t *)&len)) < 0) {
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }

            printf("New connection established with client %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

            for (i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i] == 0) {
                    clients[i] = client_fd;
                    break;
                }
            }
        }

        for (i = 0; i < MAX_CLIENTS; i++) {
            client_fd = clients[i];

            if (FD_ISSET(client_fd, &read_fds)) {
                if ((len = read(client_fd, buffer, BUFFER_SIZE)) <= 0) {
                    printf("Client %d disconnected\n", client_fd);
                    close(client_fd);
                    clients[i] = 0;
                } else {
                    buffer[len] = '\0';
                    printf("Client %d: %s", client_fd, buffer);

                    for (int j = 0; j < MAX_CLIENTS; j++) {
                        if (clients[j] != 0 && clients[j] != client_fd) {
                            write(clients[j], buffer, strlen(buffer));
                        }
                    }
                }
            }
        }
    }

    return 0;
}