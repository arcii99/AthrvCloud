//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {

    int sockfd, new_sockfd, max_fd, client_fd[MAX_CLIENTS], client_count = 0;
    struct sockaddr_in addr;
    char buffer[BUFFER_SIZE], client_addresses[MAX_CLIENTS][INET_ADDRSTRLEN];
    fd_set master, read_fds;

    // setup server socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", PORT);

    FD_ZERO(&master);
    FD_SET(sockfd, &master);
    max_fd = sockfd;

    while (1) {
        read_fds = master; // make a copy of all file descriptors to read from

        if (select(max_fd+1, &read_fds, NULL, NULL, NULL) == -1) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        // loop through all file descriptors to check for data to read
        for (int i = 0; i <= max_fd; i++) {

            if (FD_ISSET(i, &read_fds)) {

                if (i == sockfd) { // new incoming connection
                    struct sockaddr_in client_addr;
                    socklen_t client_addr_len = sizeof(client_addr);

                    if ((new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
                        perror("accept");
                        continue;
                    }

                    // add new client to list
                    client_fd[client_count] = new_sockfd;
                    inet_ntop(client_addr.sin_family, &client_addr.sin_addr, client_addresses[client_count], INET_ADDRSTRLEN);
                    printf("New connection from %s on socket %d\n", client_addresses[client_count], new_sockfd);
                    client_count++;

                    // add new file descriptor to master set
                    FD_SET(new_sockfd, &master);
                    if (new_sockfd > max_fd) {
                        max_fd = new_sockfd;
                    }

                } else { // existing client has new data to read

                    int n = read(i, buffer, BUFFER_SIZE-1);

                    if (n <= 0) { // connection closed by remote client
                        if (n == 0) {
                            printf("Connection closed from %s on socket %d\n", client_addresses[i], i);
                        } else {
                            perror("recv");
                        }

                        // remove file descriptor from master set and client list
                        close(i);
                        FD_CLR(i, &master);
                        for (int j = 0; j < client_count; j++) {
                            if (client_fd[j] == i) {
                                client_fd[j] = -1; // mark as closed
                                break;
                            }
                        }

                    } else { // data received from client

                        // add null terminator to end of string
                        buffer[n] = '\0';

                        printf("Received from %s on socket %d: %s\n", client_addresses[i], i, buffer);

                        // echo message back to all clients except for sender
                        for (int j = 0; j < client_count; j++) {
                            if (client_fd[j] != -1 && client_fd[j] != i) {
                                if (send(client_fd[j], buffer, strlen(buffer), 0) == -1) {
                                    perror("send");
                                    continue;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}