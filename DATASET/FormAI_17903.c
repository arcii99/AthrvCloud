//FormAI DATASET v1.0 Category: Chat server ; Style: shocked
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/select.h>
#include <errno.h>

#define SERVER_PORT 9090
#define MAX_CLIENTS 10

int main(int argc, char const *argv[])
{
    int server_fd, client_fds[MAX_CLIENTS], max_clients = MAX_CLIENTS, activity, valread, new_socket;
    struct sockaddr_in address;
    char message[1024], buffer[1024];
    fd_set readfds;

    // init client_fds to -1 for availability checks
    for (int i = 0; i < max_clients; i++) {
        client_fds[i] = -1;
    }
 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // bind socket to the specified SERVER_PORT
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(SERVER_PORT);
     
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    int addrlen = sizeof(address);
    printf("Server started and listening on port %d\n", SERVER_PORT);

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(server_fd, &readfds);

        int max_sd = server_fd;
        for (int i = 0; i < max_clients; i++) {
            int sd = client_fds[i];

            if (sd > 0) {
                FD_SET(sd, &readfds);
            }
            if (sd > max_sd) {
                max_sd = sd;
            }
        }

        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
        if (activity < 0) {
            perror("select()");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(server_fd, &readfds)) {
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            printf("New connection established: socket fd is %d, ip is %s, port is %d\n", 
                new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));

            // add new socket to client_fds array
            for (int i = 0; i < max_clients; i++) {
                if (client_fds[i] == -1) {
                    client_fds[i] = new_socket;
                    break;
                }
            }
        }

        // check messages from all clients
        for (int i = 0; i < max_clients; i++) {
            int sd = client_fds[i];
             
            if (FD_ISSET(sd, &readfds)) {
                if ((valread = read(sd, buffer, 1024)) == 0) {
                    getpeername(sd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
                    printf("Client disconnected: socket fd is %d, ip is %s, port is %d\n",
                        sd, inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                    close(sd);
                    client_fds[i] = -1;
                }
                else {
                    // relay message to all other clients
                    buffer[valread] = '\0';
                    for (int j = 0; j < max_clients; j++) {
                        int dest_fd = client_fds[j];
                        if (dest_fd != server_fd && dest_fd != sd && dest_fd > 0) {
                            send(dest_fd, buffer, strlen(buffer), 0);
                        }
                    }
                }
            }
        }
    }

    return 0;
}