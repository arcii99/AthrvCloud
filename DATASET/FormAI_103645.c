//FormAI DATASET v1.0 Category: Networking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CONNS 10
#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int sockfd, conn_sockfd[MAX_CONNS], max_fd;
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    char buffer[BUF_SIZE];

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind to local address and port
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8888);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(sockfd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Initialize connection socket array and add listener socket to set
    fd_set fds, read_fds;
    FD_ZERO(&fds);
    FD_SET(sockfd, &fds);
    max_fd = sockfd;
    int num_conns = 0;

    // Wait for and handle connections
    printf("Waiting for connections...\n");
    while (1) {
        read_fds = fds;
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) == -1) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        // Check for new connections
        if (FD_ISSET(sockfd, &read_fds)) {
            conn_sockfd[num_conns] = accept(sockfd, (struct sockaddr *)&addr, &addrlen);
            if (conn_sockfd[num_conns] == -1) {
                perror("accept");
                continue;
            }

            // Add new socket to set
            FD_SET(conn_sockfd[num_conns], &fds);
            max_fd = (max_fd > conn_sockfd[num_conns]) ? max_fd : conn_sockfd[num_conns];

            printf("New connection from %s:%d\n",
                    inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
            num_conns++;
        }

        // Check for input from clients
        for (int i = 0; i < num_conns; i++) {
            if (FD_ISSET(conn_sockfd[i], &read_fds)) {
                int bytes_recv = recv(conn_sockfd[i], buffer, BUF_SIZE, 0);
                if (bytes_recv == -1) {
                    perror("recv");
                    exit(EXIT_FAILURE);
                } else if (bytes_recv == 0) {
                    // Connection closed by client
                    printf("Connection closed by client\n");
                    close(conn_sockfd[i]);
                    FD_CLR(conn_sockfd[i], &fds);
                    num_conns--;
                    continue;
                }

                // Echo input back to client
                if (send(conn_sockfd[i], buffer, bytes_recv, 0) == -1) {
                    perror("send");
                    exit(EXIT_FAILURE);
                }
                buffer[bytes_recv] = '\0';
                printf("Received: %s\n", buffer);
            }
        }
    }

    return 0;
}