//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024
#define MAX_CONNECTIONS 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("socket() error");
        return 1;
    }

    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(80);
    if (inet_pton(AF_INET, argv[1], &target_addr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton() failed for %s\n", argv[1]);
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) < 0) {
        perror("connect() error");
        return 1;
    }

    printf("%s is available for incoming connections\n", argv[1]);

    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(sockfd, &read_fds);
    int max_fd = sockfd;

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    while (true) {
        fd_set tmp_fds = read_fds;
        if (select(max_fd + 1, &tmp_fds, NULL, NULL, NULL) < 0) {
            perror("select() error");
            break;
        }

        int i;
        for (i = 0; i <= max_fd; i++) {
            if (FD_ISSET(i, &tmp_fds)) {
                if (i == sockfd) {
                    int new_fd = accept(sockfd, NULL, NULL);
                    if (new_fd < 0) {
                        perror("accept() error");
                        continue;
                    }

                    FD_SET(new_fd, &read_fds);
                    if (new_fd > max_fd) {
                        max_fd = new_fd;
                    }

                    printf("New connection from %s:%d\n", inet_ntoa(target_addr.sin_addr),
                                                                ntohs(target_addr.sin_port));
                } else {
                    int bytes_read = recv(i, buffer, BUFFER_SIZE, 0);
                    if (bytes_read < 0) {
                        perror("recv() error");
                        continue;
                    } else if (bytes_read == 0) {
                        printf("%d disconnected\n", i);
                        close(i);
                        FD_CLR(i, &read_fds);
                    } else {
                        printf("Received %d bytes from %d: %.*s\n", bytes_read, i, bytes_read, buffer);
                    }
                }
            }
        }
    }

    close(sockfd);

    return 0;
}