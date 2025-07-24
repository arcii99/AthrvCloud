//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>

#define MAX_MSG_LEN 1024
#define MAX_CLIENTS 10
#define DEFAULT_PORT 5555

typedef struct {
    int fd;
    struct sockaddr_in addr;
    struct timeval last_activity;
    int active;
} Client;

int main(int argc, char *argv[]) {
    int sockfd, new_sockfd, portno = DEFAULT_PORT, maxfd, i, n, max_clients = MAX_CLIENTS;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    fd_set read_fds, write_fds, except_fds;
    char buffer[MAX_MSG_LEN];
    Client clients[MAX_CLIENTS];

    // set up server socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        return 1;
    }
    if (listen(sockfd, 5) < 0) {
        perror("ERROR on listen");
        return 1;
    }
    printf("Server started on port %d\n", portno);

    // set up client info
    memset(clients, 0, sizeof(clients));

    while (1) {
        // select() setup
        FD_ZERO(&read_fds);
        FD_ZERO(&write_fds);
        FD_ZERO(&except_fds);
        FD_SET(sockfd, &read_fds);
        maxfd = sockfd;

        // add client file descriptors to select() sets
        for (i = 0; i < max_clients; i++) {
            if (clients[i].active) {
                if (clients[i].fd > maxfd) {
                    maxfd = clients[i].fd;
                }
                FD_SET(clients[i].fd, &read_fds);
                FD_SET(clients[i].fd, &write_fds);
                FD_SET(clients[i].fd, &except_fds);
            }
        }

        // check for activity on any file descriptor
        if (select(maxfd + 1, &read_fds, &write_fds, &except_fds, NULL) < 0) {
            perror("ERROR on select");
            return 1;
        }

        // check for new client connections
        if (FD_ISSET(sockfd, &read_fds)) {
            clilen = sizeof(cli_addr);
            new_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
            if (new_sockfd < 0) {
                perror("ERROR on accept");
                return 1;
            }
            // add client to list of active clients
            for (i = 0; i < max_clients; i++) {
                if (!clients[i].active) {
                    clients[i].fd = new_sockfd;
                    clients[i].addr = cli_addr;
                    clients[i].active = 1;
                    gettimeofday(&clients[i].last_activity, NULL);
                    printf("New client connected, IP: %s, port: %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
                    break;
                }
            }
            if (i == max_clients) {
                printf("Maximum number of clients reached, closing connection\n");
                close(new_sockfd);
            }
        }

        // check for activity on existing client connections
        for (i = 0; i < max_clients; i++) {
            if (clients[i].active && FD_ISSET(clients[i].fd, &read_fds)) {
                memset(buffer, 0, MAX_MSG_LEN);
                n = read(clients[i].fd, buffer, MAX_MSG_LEN - 1);
                if (n < 0) {
                    perror("ERROR reading from socket");
                    clients[i].active = 0;
                } else if (n == 0) {
                    printf("Client disconnected, IP: %s, port: %d\n", inet_ntoa(clients[i].addr.sin_addr), ntohs(clients[i].addr.sin_port));
                    clients[i].active = 0;
                } else {
                    // do something with the message
                    printf("New message from client, IP: %s, port: %d: %s\n", inet_ntoa(clients[i].addr.sin_addr), ntohs(clients[i].addr.sin_port), buffer);
                }
            }
            if (clients[i].active && FD_ISSET(clients[i].fd, &write_fds)) {
                // do something if client is ready to write
            }
            if (clients[i].active && FD_ISSET(clients[i].fd, &except_fds)) {
                // do something if exception occurred on client socket
            }
            if (clients[i].active) {
                // check if client has timed out
                struct timeval now;
                gettimeofday(&now, NULL);
                if (now.tv_sec - clients[i].last_activity.tv_sec >= 60) { // timeout after 60 seconds of inactivity
                    printf("Client timed out, IP: %s, port: %d", inet_ntoa(clients[i].addr.sin_addr), ntohs(clients[i].addr.sin_port));
                    clients[i].active = 0;
                }
            }
        }
    }

    return 0;
}