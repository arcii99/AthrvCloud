//FormAI DATASET v1.0 Category: Networking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10

typedef struct {
    int sockfd;
    struct sockaddr_in address;
    int addrlen;
} client_t;

void handle_client(client_t *client) {
    char buffer[1024];
    int valread = read(client->sockfd, buffer, 1024);
    if (valread > 0) {
        printf("Message received from client at %s:%d: %s\n",
               inet_ntoa(client->address.sin_addr),
               ntohs(client->address.sin_port),
               buffer);
    }
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address = {0};
    int opt = 1;
    int addrlen = sizeof(address);
    client_t clients[MAX_CLIENTS] = {0};
    fd_set readfds;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Initialize file descriptor set
        FD_ZERO(&readfds);
        // Add server socket to set
        FD_SET(server_fd, &readfds);
        int max_fd = server_fd;
        // Add client sockets to set
        for (int i = 0; i < MAX_CLIENTS; i++) {
            client_t client = clients[i];
            if (client.sockfd > 0) {
                FD_SET(client.sockfd, &readfds);
                if (client.sockfd > max_fd) {
                    max_fd = client.sockfd;
                }
            }
        }
        // Wait for activity on file descriptors
        if (select(max_fd + 1, &readfds, NULL, NULL, NULL) < 0) {
            perror("select");
            exit(EXIT_FAILURE);
        }
        // Handle activity on server socket
        if (FD_ISSET(server_fd, &readfds)) {
            if ((new_socket = accept(server_fd,
                                     (struct sockaddr *)&address,
                                     (socklen_t*)&addrlen)) < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i].sockfd == 0) {
                    clients[i].sockfd = new_socket;
                    clients[i].address = address;
                    clients[i].addrlen = addrlen;
                    printf("New client connected at %s:%d\n",
                           inet_ntoa(clients[i].address.sin_addr),
                           ntohs(clients[i].address.sin_port));
                    break;
                }
            }
        }
        // Handle activity on client sockets
        for (int i = 0; i < MAX_CLIENTS; i++) {
            client_t client = clients[i];
            if (FD_ISSET(client.sockfd, &readfds)) {
                handle_client(&client);
            }
        }
    }

    return 0;
}