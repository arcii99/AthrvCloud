//FormAI DATASET v1.0 Category: Chat server ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 10

int server_socket;
int clients[MAX_CLIENTS];
int num_clients = 0;

void handle_signal(int sig) {
    printf("Signal %d received. Closing socket...\n", sig);
    close(server_socket);
    exit(0);
}

void handle_client(int client_socket, int index) {
    char buffer[1024];
    int read_size, i;
    while ((read_size = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        for (i = 0; i < num_clients; i++) {
            if (i != index) {
                send(clients[i], buffer, read_size, 0);
            }
        }
        printf("Client %d sent: %s\n", index+1, buffer);
    }
    if (read_size == 0) {
        printf("Client %d disconnected\n", index+1);
        close(client_socket);
        clients[index] = 0;
        num_clients--;
    }
    else {
        printf("Error reading from client %d\n", index+1);
    }
}

int main(int argc, char const *argv[]) {
    int client_socket, max_socket, activity, i;
    struct sockaddr_in address;
    fd_set fds;

    signal(SIGINT, handle_signal);

    memset(clients, 0, sizeof(clients));

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        return 1;
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen failed");
        return 1;
    }

    printf("Server started on port %d. Waiting for clients...\n", PORT);

    while (1) {
        FD_ZERO(&fds);
        FD_SET(server_socket, &fds);
        max_socket = server_socket;
        for (i = 0; i < num_clients; i++) {
            if (clients[i] > 0) {
                FD_SET(clients[i], &fds);
            }
            if (clients[i] > max_socket) {
                max_socket = clients[i];
            }
        }
        activity = select(max_socket + 1, &fds, NULL, NULL, NULL);
        if (activity < 0) {
            perror("select failed");
            return 1;
        }
        if (FD_ISSET(server_socket, &fds)) {
            if ((client_socket = accept(server_socket, NULL, NULL)) < 0) {
                perror("accept failed");
                return 1;
            }
            printf("New client connected\n");
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i] == 0) {
                    clients[i] = client_socket;
                    num_clients++;
                    break;
                }
            }
        }
        for (i = 0; i < num_clients; i++) {
            if (FD_ISSET(clients[i], &fds)) {
                handle_client(clients[i], i);
            }
        }
    }

    return 0;
}