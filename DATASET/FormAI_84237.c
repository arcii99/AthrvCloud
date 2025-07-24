//FormAI DATASET v1.0 Category: Chat server ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int master_socket, new_socket, client_socket[50], max_clients = 50,
            max_sd, activity, sd, valread, bytes_sent, opt = 1,
            addrlen, clientlen, i, j, k;
    char buffer[1025], message[1000], welcome_message[100] = "Welcome to the chat room\n";
    fd_set readfds;

    struct sockaddr_in server_address, client_address;

    for (i = 0; i < max_clients; i++) {
        client_socket[i] = 0;
    }

    if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *) &opt,
                   sizeof(opt)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    if (bind(master_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Listener on port %d \n", 8080);

    if (listen(master_socket, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    addrlen = sizeof(server_address);
    puts("Waiting for connections ...");

    while (1) {
        FD_ZERO(&readfds);

        FD_SET(master_socket, &readfds);
        max_sd = master_socket;

        for (i = 0; i < max_clients; i++) {
            sd = client_socket[i];

            if (sd > 0) {
                FD_SET(sd, &readfds);
            }

            if (sd > max_sd) {
                max_sd = sd;
            }
        }

        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

        if ((activity < 0) && (errno != EINTR)) {
            perror("select error");
        }

        if (FD_ISSET(master_socket, &readfds)) {
            if ((new_socket = accept(master_socket, (struct sockaddr *) &server_address,
                                     (socklen_t *) &addrlen)) < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            printf("New connection : %s:%d\n", inet_ntoa(server_address.sin_addr),
                   ntohs(server_address.sin_port));

            send(new_socket, welcome_message, strlen(welcome_message), 0);

            for (i = 0; i < max_clients; i++) {
                if (client_socket[i] == 0) {
                    client_socket[i] = new_socket;
                    printf("Adding to list of sockets as %d\n", i);
                    break;
                }
            }
        }

        for (i = 0; i < max_clients; i++) {
            sd = client_socket[i];

            if (FD_ISSET(sd, &readfds)) {
                if ((valread = read(sd, buffer, 1024)) == 0) {
                    getpeername(sd, (struct sockaddr *) &server_address,
                                (socklen_t *) &addrlen);
                    printf("Host disconnected, IP address: %s, Port: %d\n",
                           inet_ntoa(server_address.sin_addr),
                           ntohs(server_address.sin_port));

                    close(sd);
                    client_socket[i] = 0;
                } else {
                    buffer[valread] = '\0';
                    printf("Client message: %s\n", buffer);

                    for (j = 0; j < max_clients; j++) {
                        int dest_sd = client_socket[j];
                        if (dest_sd != 0 && dest_sd != sd) {
                            bytes_sent = send(dest_sd, buffer, strlen(buffer), 0);
                            if (bytes_sent == -1) {
                                perror("send error");
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}