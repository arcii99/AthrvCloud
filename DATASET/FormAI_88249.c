//FormAI DATASET v1.0 Category: Network Ping Test ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8888
#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, n, i, max_fd, bytes_sent, bytes_recv, nfds;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in addr;
    struct hostent *server;
    fd_set read_fds, write_fds, except_fds;
    FD_ZERO(&read_fds);
    FD_ZERO(&write_fds);
    FD_ZERO(&except_fds);

    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error: opening socket");
    }

    bzero((char *) &addr, sizeof(addr));
    addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&addr.sin_addr.s_addr, server->h_length);
    addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        error("Error: connecting");
    }

    printf("Connected to server on port %d.\n", PORT);

    FD_SET(STDIN_FILENO, &read_fds);  // Add stdin to read set
    FD_SET(sockfd, &read_fds);  // Add socket to read set
    FD_SET(sockfd, &write_fds); // Add socket to write set
    max_fd = sockfd;

    while (1) {
        except_fds = read_fds;
        nfds = select(max_fd+1, &except_fds, &write_fds, NULL, NULL);
        if (nfds < 0) {
            error("Error: select");
        }

        for (i = 0; i <= max_fd; i++) {
            if (FD_ISSET(i, &except_fds)) {
                printf("Unexpected error on socket %d.\n", i);
                break;
            }

            if (FD_ISSET(i, &write_fds)) {
                bzero(buffer, BUFFER_SIZE);
                printf("Enter a message to send to the server: ");
                fgets(buffer, BUFFER_SIZE-1, stdin);
                bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
                if (bytes_sent < 0) {
                    error("Error: writing to socket");
                }
            }

            if (FD_ISSET(i, &read_fds)) {
                bzero(buffer, BUFFER_SIZE);
                bytes_recv = recv(sockfd, buffer, BUFFER_SIZE-1, 0);
                if (bytes_recv < 0) {
                    error("Error: reading from socket");
                } else if (bytes_recv == 0) {
                    printf("Server closed the connection.\n");
                    break;
                } else {
                    printf("Received message from server: %s", buffer);
                }
            }
        }
    }

    close(sockfd);
    return 0;
}