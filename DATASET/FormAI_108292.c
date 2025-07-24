//FormAI DATASET v1.0 Category: Chat server ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_MSG_LENGTH 1024

int main() {
    int server_fd, client_sockets[MAX_CLIENTS], max_socket, activity, client_socket, opt = 1, addrlen, valread, i;
    struct sockaddr_in address;
    char buffer[MAX_MSG_LENGTH];
    fd_set readfds;

    for (i = 0; i < MAX_CLIENTS; i++) {
        client_sockets[i] = 0;
    }

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
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
    printf("Chat is ready on port %d\n", PORT);

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    addrlen = sizeof(address);
    while (1) {
        FD_ZERO(&readfds);
        FD_SET(server_fd, &readfds);
        max_socket = server_fd;

        for (i = 0; i < MAX_CLIENTS; i++) {
            client_socket = client_sockets[i];

            if (client_socket > 0) {
                FD_SET(client_socket, &readfds);
            }

            if (client_socket > max_socket) {
                max_socket = client_socket;
            }
        }

        activity = select(max_socket + 1, &readfds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(server_fd, &readfds)) {
            if ((client_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            printf("New client connected, socket fd is %d, IP is %s, port is %d\n", client_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));

            for (i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = client_socket;
                    break;
                }
            }
        }

        for (i = 0; i < MAX_CLIENTS; i++) {
            client_socket = client_sockets[i];

            if (FD_ISSET(client_socket, &readfds)) {
                if ((valread = read(client_socket, buffer, MAX_MSG_LENGTH)) == 0) {
                    getpeername(client_socket, (struct sockaddr*)&address, (socklen_t*)&addrlen);
                    printf("Client disconnected, IP is %s, port is %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                    close(client_socket);
                    client_sockets[i] = 0;
                } else {
                    buffer[valread] = '\0';
                    printf("Received message from client with IP %s and port %d: %s\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port), buffer);

                    for (i = 0; i < MAX_CLIENTS; i++) {
                        if (client_sockets[i] != 0 && client_sockets[i] != client_socket) {
                            send(client_sockets[i], buffer, strlen(buffer), 0);
                        }
                    }
                }
            }
        }
    }

    return 0;
}