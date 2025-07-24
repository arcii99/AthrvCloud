//FormAI DATASET v1.0 Category: Client Server Application ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

#define PORT "8888"
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int sock_fd, new_fd, active_clients;
struct addrinfo hints, *server_info, *p;
struct sockaddr_storage client_addr;
socklen_t sin_size;
char buffer[BUFFER_SIZE];

typedef struct {
    int id;
    int fd;
    char name[32];
} client_t;

client_t client_list[MAX_CLIENTS];

void close_server() {
    int i;
    printf("Server stopping...\n");

    for (i = 0; i < MAX_CLIENTS; i++) {
        if (client_list[i].fd > 0) {
            close(client_list[i].fd);
        }
    }

    close(sock_fd);
    exit(0);
}

void handle_signal(int sig) {
    printf("Signal %d received\n", sig);
    close_server();
}

void set_non_blocking(int fd) {
    int flags;
    flags = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

int get_free_client_slot() {
    int i = 0;
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (client_list[i].fd == 0) {
            return i;
        }
    }

    return -1;
}

void broadcast_message(char* message_send, int sender_fd) {
    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (client_list[i].fd > 0 && client_list[i].fd != sender_fd) {
            send(client_list[i].fd, message_send, strlen(message_send), 0);
        }
    }

}

int receive_message(client_t* client) {
    int len = recv(client->fd, buffer, BUFFER_SIZE - 1, 0);
    if (len <= 0) {
        return -1;
    }

    buffer[len] = '\0';
    return 0;
}

void handle_new_connection() {
    client_t new_client;
    sin_size = sizeof(struct sockaddr_storage);

    new_fd = accept(sock_fd, (struct sockaddr *) &client_addr, &sin_size);
    if (new_fd == -1) {
        perror("Error on accept");
        return;
    }

    set_non_blocking(new_fd);

    new_client.fd = new_fd;

    int free_slot = get_free_client_slot();
    if (free_slot == -1) {
        close(new_fd);
        printf("Server full. Connection rejected.\n");
        return;
    }

    client_list[free_slot] = new_client;
    active_clients++;

    sprintf(buffer, "%d clients online.\n", active_clients);
    broadcast_message(buffer, new_fd);

    printf("New client connected with fd: %d slot: %d\n", new_fd, free_slot);
}

void handle_client_request(client_t* client) {
    if (receive_message(client) == -1) {
        close(client->fd);
        printf("Client with fd: %d disconnected.\n", client->fd);
        client->fd = 0;
        active_clients--;
        sprintf(buffer, "%d clients online.\n", active_clients);
        broadcast_message(buffer, -1);
    } else {
        printf("Message from client %d: %s\n", client->id, buffer);
        broadcast_message(buffer, client->fd);
    }
}

int main(int argc, char const *argv[]) {

    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    memset(client_list, 0, sizeof(client_list));

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int rv = getaddrinfo(NULL, PORT, &hints, &server_info);
    if (rv != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = server_info; p != NULL; p = p->ai_next) {
        sock_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sock_fd == -1) {
            perror("Error on creating socket");
            continue;
        }

        set_non_blocking(sock_fd);

        int yes = 1;
        if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
            perror("Error on setsockopt");
            exit(1);
        }

        if (bind(sock_fd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sock_fd);
            continue;
        }

        break;
    }

    freeaddrinfo(server_info);

    if (p == NULL) {
        fprintf(stderr, "Failed to bind socket\n");
        exit(1);
    }

    if (listen(sock_fd, MAX_CLIENTS) == -1) {
        perror("Error on listen");
        exit(1);
    }

    printf("Server listening on port %s...\n", PORT);

    while (1) {
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(sock_fd, &read_fds);

        int max_fd = sock_fd;

        int i;
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (client_list[i].fd > 0) {
                FD_SET(client_list[i].fd, &read_fds);
                if (client_list[i].fd > max_fd) {
                    max_fd = client_list[i].fd;
                }
            }
        }

        int sel = select(max_fd + 1, &read_fds, NULL, NULL, NULL);

        if (sel == -1) {
            perror("Error on select");
            continue;
        }

        if (FD_ISSET(sock_fd, &read_fds)) {
            handle_new_connection();
        }

        for (i = 0; i < MAX_CLIENTS; i++) {
            if (client_list[i].fd > 0 && FD_ISSET(client_list[i].fd, &read_fds)) {
                handle_client_request(&client_list[i]);
            }
        }
    }

    return 0;
}