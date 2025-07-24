//FormAI DATASET v1.0 Category: Chat server ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage: ./server <port>\n");
        exit(1);
    }

    int socket_fd, client_fds[MAX_CLIENTS], max_fds, activity, i, valread;
    char buffer[BUFFER_SIZE];
    
    fd_set read_fds;

    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // create a socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    // set socket option to allow port reuse
    int opt = 1;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(1);
    }

    // setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    // bind the socket to the specified port
    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // listen for incoming connections
    if (listen(socket_fd, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    // accept incoming connections and add them to the client_fds array
    for (i = 0; i < MAX_CLIENTS; i++) {
        client_fds[i] = 0;
    }

    printf("Waiting for connections...\n");

    while (true) {
        // clear the fd set
        FD_ZERO(&read_fds);

        // add the server socket to the read_fd set
        FD_SET(socket_fd, &read_fds);
        max_fds = socket_fd;

        // add client fds to the read_fds set
        for (i = 0; i < MAX_CLIENTS; i++) {
            int fd = client_fds[i];

            if (fd > 0) {
                FD_SET(fd, &read_fds);
            }

            if (fd > max_fds) {
                max_fds = fd;
            }
        }

        // wait for activity on any of the fds
        activity = select(max_fds + 1, &read_fds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("select failed");
            exit(1);
        }

        // handle incoming client connections
        if (FD_ISSET(socket_fd, &read_fds)) {
            int new_fd;
            if ((new_fd = accept(socket_fd, (struct sockaddr *)&client_addr,
                                 &client_addr_len)) < 0) {
                perror("accept failed");
                exit(1);
            }

            printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr),
                   ntohs(client_addr.sin_port));

            // add new client socket to array
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (client_fds[i] == 0) {
                    client_fds[i] = new_fd;
                    break;
                }
            }
        }

        // handle client messages
        for (i = 0; i < MAX_CLIENTS; i++) {
            int fd = client_fds[i];

            if (FD_ISSET(fd, &read_fds)) {
                valread = read(fd, buffer, BUFFER_SIZE);

                if (valread <= 0) {
                    // connection closed or error
                    close(fd);
                    client_fds[i] = 0;
                    printf("Connection closed\n");
                } else {
                    buffer[valread] = '\0';
                    printf("Message received: %s\n", buffer);

                    // echo message back to client
                    write(fd, buffer, strlen(buffer));
                }
            }
        }
    }

    return 0;
}