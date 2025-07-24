//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 10

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, n_clients, client_sockets[MAX_CLIENTS];
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to specified address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started. Listening on port %d\n", PORT);

    // Accept incoming connections
    n_clients = 0;
    while (1) {
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);
        for (int i = 0; i < n_clients; i++) {
            FD_SET(client_sockets[i], &read_fds);
        }

        int max_fd = (n_clients > 0) ? client_sockets[n_clients-1] : server_fd;

        if (select(max_fd+1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(server_fd, &read_fds)) {
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            printf("New connection. Socket fd is %d, ip is : %s, port : %d\n", new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));

            if (n_clients == MAX_CLIENTS) {
                printf("Max clients reached. Connection rejected.\n");
                close(new_socket);
                continue;
            }

            client_sockets[n_clients++] = new_socket;
        }

        for (int i = 0; i < n_clients; i++) {
            if (FD_ISSET(client_sockets[i], &read_fds)) {
                char buffer[1024] = {0};
                int valread = read(client_sockets[i], buffer, sizeof(buffer));
                if (valread <= 0) {
                    printf("Client disconnected. Socket fd %d closed.\n", client_sockets[i]);
                    close(client_sockets[i]);
                    for (int j = i; j < n_clients-1; j++) {
                        client_sockets[j] = client_sockets[j+1];
                    }
                    n_clients--;
                    continue;
                }
                printf("Received message from client %d: %s\n", client_sockets[i], buffer);
                // Do some processing with the received message
                char* response = "OK";
                send(client_sockets[i], response, strlen(response), 0);
            }
        }
    }

    return 0;
}