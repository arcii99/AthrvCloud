//FormAI DATASET v1.0 Category: Socket programming ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

int main() {

    int server_fd, new_socket, client_sockets[10], max_clients = 10, activity, valread, sd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char welcome_message[256] = "Welcome to the server!\n";

    fd_set read_fds;
    char buffer[1024];
    memset(client_sockets, 0, sizeof(client_sockets));

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8888);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server running on port 8888\n");

    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);
        int max_sd = server_fd;

        for (int i = 0; i < max_clients; i++) {
            sd = client_sockets[i];

            if (sd > 0) {
                FD_SET(sd, &read_fds);
            }

            if (sd > max_sd) {
                max_sd = sd;
            }
        }

        activity = select(max_sd + 1, &read_fds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("Select failed");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(server_fd, &read_fds)) {
            if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }
            printf("New connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
            for (int i = 0; i < max_clients; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = new_socket;
                    send(client_sockets[i], welcome_message, strlen(welcome_message), 0);
                    break;
                }
            }
        }

        for (int i = 0; i < max_clients; i++) {
            sd = client_sockets[i];

            if (FD_ISSET(sd, &read_fds)) {
                if ((valread = read(sd, buffer, 1024)) == 0) {
                    printf("%s:%d disconnected\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                    close(sd);
                    client_sockets[i] = 0;
                }
                else {
                    buffer[valread] = '\0';
                    printf("%s:%d - %s", inet_ntoa(address.sin_addr), ntohs(address.sin_port), buffer);
                }
            }
        }
    }

    return 0;
}