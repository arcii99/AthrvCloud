//FormAI DATASET v1.0 Category: Networking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>

#define MAX_EVENTS 10 // Maximum number of events to receive at once

static int set_non_blocking(int sockfd) {
    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl");
        return -1;
    }

    flags |= O_NONBLOCK;
    int s = fcntl(sockfd, F_SETFL, flags);
    if (s == -1) {
        perror("fcntl");
        return -1;
    }

    return 0;
}

int main() {
    struct sockaddr_in serv_addr, cli_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(sockfd, SOMAXCONN) < 0) {
        perror("listen");
        return 1;
    }

    int epollfd = epoll_create1(0);
    if (epollfd < 0) {
        perror("epoll_create1");
        return 1;
    }

    struct epoll_event ev, events[MAX_EVENTS];
    ev.events = EPOLLIN;
    ev.data.fd = sockfd;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &ev) < 0) {
        perror("epoll_ctl");
        return 1;
    }

    while (1) {
        int n = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        for (int i = 0; i < n; ++i) {
            if ((events[i].events & EPOLLERR) || (events[i].events & EPOLLHUP)) {
                fprintf(stderr, "Epoll error on fd %d\n", events[i].data.fd);
                close(events[i].data.fd);
                continue;
            } else if (events[i].data.fd == sockfd) {  // New incoming connection
                socklen_t clilen = sizeof(cli_addr);

                int newfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
                if (newfd < 0) {
                    perror("accept");
                    continue;
                }

                set_non_blocking(newfd);  // Set to non-blocking mode

                ev.data.fd = newfd;
                ev.events = EPOLLIN | EPOLLET;
                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, newfd, &ev) < 0) {
                    perror("epoll_ctl");
                    return 1;
                }
            } else {  // Existing connection has data to read
                int done = 0;
                while (1) {
                    char buf[512];
                    ssize_t count = read(events[i].data.fd, buf, sizeof(buf));

                    if (count == -1) {
                        if (errno != EAGAIN) {
                            perror("read");
                            done = 1;
                        }
                        break;
                    } else if (count == 0) {
                        done = 1;
                        break;
                    }

                    // Do something with the received data
                    printf("Received %ld bytes: %s\n", count, buf);
                }

                if (done) {
                    printf("Closed connection on fd %d\n", events[i].data.fd);
                    close(events[i].data.fd);
                }
            }
        }
    }

    return 0;
}