//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 8080
#define MAX_CONNECTIONS 100
#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    char buffer[BUFFER_SIZE];
    int size;
} client_t;

int clients_count = 0;
client_t clients[MAX_CONNECTIONS];

void close_socket(int socket) {
    close(socket);
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (clients[i].socket == socket) {
            clients[i].socket = -1;
            clients_count--;
            break;
        }
    }
}

void close_all_sockets(int signal) {
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (clients[i].socket != -1) {
            close_socket(clients[i].socket);
        }
    }
    exit(0);
}

int make_socket_non_blocking(int socket) {
    int flags = fcntl(socket, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl");
        return -1;
    }
    if (fcntl(socket, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl");
        return -1;
    }
    return 0;
}

int create_socket() {
    int server_socket;
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    make_socket_non_blocking(server_socket);
    return server_socket;
}

void handle_server_socket(int server_socket) {
    while (true) {
        struct sockaddr_in addr;
        socklen_t addrlen = sizeof(addr);
        int client_socket = accept(server_socket, (struct sockaddr *) &addr, &addrlen);
        if (client_socket == -1) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                break;
            } else {
                perror("accept");
            }
        } else {
            if (clients_count == MAX_CONNECTIONS) {
                fprintf(stderr, "Too many connections, rejecting client\n");
                close(client_socket);
            } else {
                make_socket_non_blocking(client_socket);
                clients[clients_count].socket = client_socket;
                clients_count++;
            }

        }
    }
}

void handle_client(client_t *client) {
    while (true) {
        int bytes_read = read(client->socket, client->buffer + client->size, BUFFER_SIZE - client->size);
        if (bytes_read == -1) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                break;
            } else {
                perror("read");
                close_socket(client->socket);
                return;
            }
        } else if (bytes_read == 0) {
            close_socket(client->socket);
            return;
        } else {
            client->size += bytes_read;
            if (client->size >= 4 && memcmp(client->buffer + client->size - 4, "\r\n\r\n", 4) == 0) {
                printf("Received message from client %d: %s", client->socket, client->buffer);
                client->size = 0;
            }
        }
    }
}

int main() {
    signal(SIGINT, close_all_sockets);

    int server_socket = create_socket();

    while (true) {
        handle_server_socket(server_socket);
        for (int i = 0; i < MAX_CONNECTIONS; i++) {
            if (clients[i].socket != -1) {
                handle_client(&clients[i]);
            }
        }
    }
}