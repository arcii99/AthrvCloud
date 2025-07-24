//FormAI DATASET v1.0 Category: Socket programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/epoll.h>

#define PORT 8080
#define MAX_EVENTS 10

int setnonblocking(int sockfd) {
    if (fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) | O_NONBLOCK) == -1) {
        return -1;
    }
    return 0;
}

int main() {
    int listener_socket, new_socket, epollfd, fd_count;
    struct sockaddr_in address;
    struct epoll_event event, events[MAX_EVENTS];
    char buffer[1024];

    // create listener_socket and bind to port
    listener_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listener_socket == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(listener_socket, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    if (listen(listener_socket, 5) == -1) {
        perror("Failed to listen on socket");
        exit(EXIT_FAILURE);
    }

    // create epoll instance
    epollfd = epoll_create1(0);
    if (epollfd == -1) {
        perror("Failed to create epoll instance");
        exit(EXIT_FAILURE);
    }

    // add listener_socket to epoll instance
    event.events = EPOLLIN | EPOLLET;
    event.data.fd = listener_socket;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listener_socket, &event) == -1) {
        perror("Failed to add listener_socket to epoll instance");
        exit(EXIT_FAILURE);
    }

    while (1) {
        fd_count = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (fd_count == -1) {
            perror("Failed to waiting for events");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < fd_count; i++) {
            if (events[i].data.fd == listener_socket) {
                printf("New connection...\n");

                // accept new connection and add it to epoll instance
                new_socket = accept(listener_socket, NULL, NULL);
                if (new_socket == -1) {
                    perror("Failed to accept new connection");
                    exit(EXIT_FAILURE);
                }

                if (setnonblocking(new_socket) == -1) {
                    perror("Failed to set non-blocking mode");
                    exit(EXIT_FAILURE);
                }

                event.events = EPOLLIN | EPOLLET;
                event.data.fd = new_socket;
                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, new_socket, &event) == -1) {
                    perror("Failed to add new_socket to epoll instance");
                    exit(EXIT_FAILURE);
                }
            } else {
                printf("Data received...\n");

                // receive new data and send response
                memset(buffer, 0, 1024);
                int bytes_read = read(events[i].data.fd, &buffer, 1024);
                if (bytes_read == -1) {
                    perror("Failed to read data");
                    exit(EXIT_FAILURE);
                }

                printf("Received message: %s\n", buffer);
                strcat(buffer, " Response");

                int bytes_send = send(events[i].data.fd, buffer, strlen(buffer), 0);
                if (bytes_send == -1) {
                    perror("Failed to send data");
                    exit(EXIT_FAILURE);
                }

                printf("Data sent...\n");
            }
        }
    }

    close(listener_socket);
    return 0;
}