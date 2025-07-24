//FormAI DATASET v1.0 Category: Chat server ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_NUMBER 3000
#define BUFFER_SIZE 256
#define CLIENT_LIMIT 5

struct client {
    int socket_fd;
    struct sockaddr_in address;
};

void handle_client_message(struct client *clients, int sender_index, char *message, int message_length) {
    printf("Received message: %s\n", message);
    for (int i = 0; i < CLIENT_LIMIT; i++) {
        if (clients[i].socket_fd != -1 && i != sender_index) {
            send(clients[i].socket_fd, message, message_length, 0);
        }
    }
}

int main(int argc, char *argv[]) {
    int server_socket_fd, client_socket_fd, max_fd;
    struct client clients[CLIENT_LIMIT];
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];
    socklen_t client_address_length = sizeof(client_address);
    fd_set active_fds, read_fds;

    for (int i = 0; i < CLIENT_LIMIT; i++) {
        clients[i].socket_fd = -1;
    }

    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT_NUMBER);

    if (bind(server_socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Could not bind socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket_fd, CLIENT_LIMIT) < 0) {
        perror("Could not listen on socket");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT_NUMBER);

    FD_ZERO(&active_fds);
    FD_SET(server_socket_fd, &active_fds);
    max_fd = server_socket_fd;

    while (1) {
        read_fds = active_fds;

        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("Failed to select");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i <= max_fd; i++) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == server_socket_fd) {
                    if ((client_socket_fd = accept(server_socket_fd, (struct sockaddr *) &client_address, &client_address_length)) < 0) {
                        perror("Could not accept client connection");
                        exit(EXIT_FAILURE);
                    }

                    printf("New connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

                    int added = 0;
                    for (int j = 0; j < CLIENT_LIMIT && !added; j++) {
                        if (clients[j].socket_fd == -1) {
                            clients[j].socket_fd = client_socket_fd;
                            clients[j].address = client_address;
                            FD_SET(client_socket_fd, &active_fds);

                            if (client_socket_fd > max_fd) {
                                max_fd = client_socket_fd;
                            }

                            added = 1;
                            printf("Added new client to slot %d\n", j);
                        }
                    }

                    if (!added) {
                        perror("Too many clients");
                        exit(EXIT_FAILURE);
                    }
                } else {
                    int sender_index = -1;
                    for (int j = 0; j < CLIENT_LIMIT && sender_index == -1; j++) {
                        if (clients[j].socket_fd == i) {
                            sender_index = j;
                        }
                    }

                    int message_length = recv(i, buffer, BUFFER_SIZE, 0);
                    if (message_length <= 0) {
                        printf("Client %s:%d disconnected\n", inet_ntoa(clients[sender_index].address.sin_addr), ntohs(clients[sender_index].address.sin_port));
                        close(i);
                        FD_CLR(i, &active_fds);
                        clients[sender_index].socket_fd = -1;
                    } else {
                        handle_client_message(clients, sender_index, buffer, message_length);
                    }
                }
            }
        }
    }

    return 0;
}