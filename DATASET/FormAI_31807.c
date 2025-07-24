//FormAI DATASET v1.0 Category: Client Server Application ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_fd, new_socket[MAX_CLIENTS], valread, activity, client_sockets[MAX_CLIENTS], sd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // create a TCP socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // set socket options to reuse address and port
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // set address properties
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // bind the socket directly to the port on the server side
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // accept incoming connections
    while (1) {
        fd_set fds;
        FD_ZERO(&fds);

        // add the server socket to the set
        FD_SET(server_fd, &fds);

        // add all the client sockets to the set
        for (int i = 0; i < MAX_CLIENTS; i++) {
            sd = client_sockets[i];
            if (sd > 0) {
                FD_SET(sd, &fds);
            }
        }

        // wait for an activity on one of the sockets
        activity = select(0, &fds, NULL, NULL, NULL);

        // handle server socket (new incoming connection)
        if (FD_ISSET(server_fd, &fds)) {
            int new_socket_fd;
            if ((new_socket_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }

            // add the new socket to the client sockets array
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = new_socket_fd;
                    break;
                }
            }

            // send a welcome message to the new connection
            char *welcome_message = "Welcome to the chat server!\n";
            send(new_socket_fd, welcome_message, strlen(welcome_message), 0);
        }

        // handle client sockets (incoming data)
        for (int i = 0; i < MAX_CLIENTS; i++) {
            sd = client_sockets[i];
            if (FD_ISSET(sd, &fds)) {
                if ((valread = read(sd, buffer, BUFFER_SIZE)) == 0) {
                    // someone disconnected, remove from client sockets array
                    close(sd);
                    client_sockets[i] = 0;
                } else {
                    // send the message to all connected clients (broadcast)
                    for (int j = 0; j < MAX_CLIENTS; j++) {
                        if (j != i && client_sockets[j] != 0) {
                            send(client_sockets[j], buffer, strlen(buffer), 0);
                        }
                    }
                }
            }
        }
    }

    return 0;
}