//FormAI DATASET v1.0 Category: Chat server ; Style: careful
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 30
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
fd_set read_fds;

void broadcast(char *msg, int sender) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        int sockfd = client_sockets[i];
        if (sockfd > 0 && i != sender) {
            send(sockfd, msg, strlen(msg), 0);
        }
    }
}

int main(int argc, char const *argv[]) {
    int master_socket, max_fd;
    struct sockaddr_in address;

    // create master socket
    if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed: ");
        exit(EXIT_FAILURE);
    }

    // reuse the port
    int opt = 1;
    if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("Setsockopt failed: ");
        exit(EXIT_FAILURE);
    }

    // bind the socket to localhost port 8080
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(master_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed: ");
        exit(EXIT_FAILURE);
    }

    // listen on the socket
    if (listen(master_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed: ");
        exit(EXIT_FAILURE);
    }

    // accept incoming connections from clients
    printf("Chat server started on port %d...\n", PORT);
    int addrlen = sizeof(address);
    memset(client_sockets, 0, sizeof(client_sockets));
    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(master_socket, &read_fds);
        max_fd = master_socket;

        // add existing client sockets to the set
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int sockfd = client_sockets[i];
            if (sockfd > 0) {
                FD_SET(sockfd, &read_fds);
            }
            if (sockfd > max_fd) {
                max_fd = sockfd;
            }
        }

        // wait for activity on sockets
        int activity = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
        if (activity < 0) {
            perror("Select failed: ");
            exit(EXIT_FAILURE);
        }

        // handle incoming connections and messages
        if (FD_ISSET(master_socket, &read_fds)) {
            int new_socket;
            if ((new_socket = accept(master_socket, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
                perror("Accept failed: ");
                exit(EXIT_FAILURE);
            }

            // add new socket to array of client sockets
            printf("New client connected. Socket fd is %d, ip is %s, port is %d\n",
                   new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = new_socket;
                    break;
                }
            }
        } else {
            char buffer[BUFFER_SIZE] = {0};
            for (int i = 0; i < MAX_CLIENTS; i++) {
                int sockfd = client_sockets[i];
                if (FD_ISSET(sockfd, &read_fds)) {
                    int bytes_read = read(sockfd, buffer, BUFFER_SIZE);
                    if (bytes_read == 0) {
                        // connection closed
                        printf("Client disconnected. Socket fd is %d, ip is %s, port is %d\n",
                               sockfd, inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                        close(sockfd);
                        client_sockets[i] = 0;
                    } else {
                        // broadcast message to all other clients
                        printf("%s\n", buffer);
                        broadcast(buffer, i);
                    }
                }
            }
        }
    }

    return 0;
}