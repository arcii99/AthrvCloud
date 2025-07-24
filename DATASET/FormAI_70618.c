//FormAI DATASET v1.0 Category: Networking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define CLIENT_LIMIT 5

typedef struct {
    int fd;
    struct sockaddr_in addr;
} client_t;

client_t clients[CLIENT_LIMIT];

void broadcast(char *msg, int sender_fd) {

    for (int i = 0; i < CLIENT_LIMIT; i++) {
        int fd = clients[i].fd;
        if (fd != 0 && fd != sender_fd) {
            send(fd, msg, strlen(msg), 0);
        }
    }
}

void *handle_client(void *arg) {

    client_t client = *(client_t *) arg;
    char buffer[1024];
    char welcome_msg[] = "Welcome to the chat room!\n";

    // send welcome message to the new client
    send(client.fd, welcome_msg, strlen(welcome_msg), 0);

    while (1) {
        int receive = recv(client.fd, buffer, 1024, 0);
        buffer[receive] = '\0';
        if (strcmp(buffer, "quit") == 0) {
            printf("Client disconnected: %s:%d\n", inet_ntoa(client.addr.sin_addr), ntohs(client.addr.sin_port));
            close(client.fd);
            client.fd = 0;
            pthread_exit(NULL);
        } else {
            printf("%s:%d - %s", inet_ntoa(client.addr.sin_addr), ntohs(client.addr.sin_port), buffer);
            broadcast(buffer, client.fd);
        }
    }
}

int main() {

    int server_fd, opt = 1, address_len, client_fd;
    struct sockaddr_in address;
    pthread_t tid;

    // create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return EXIT_FAILURE;
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt failed");
        return EXIT_FAILURE;
    }

    // assign IP address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind the socket to specified IP address and port
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        return EXIT_FAILURE;
    }

    // listen for incoming connections
    if (listen(server_fd, CLIENT_LIMIT) < 0) {
        perror("listen failed");
        return EXIT_FAILURE;
    }

    printf("Server is online and listening on port %d\n", PORT);

    while (1) {

        address_len = sizeof(address);
        if ((client_fd = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &address_len)) < 0) {
            perror("accept failed");
            continue;
        }

        // add new client to clients list
        for (int i = 0; i < CLIENT_LIMIT; i++) {
            if (clients[i].fd == 0) {
                clients[i].fd = client_fd;
                clients[i].addr = address;
                pthread_create(&tid, NULL, handle_client, (void *) &clients[i]);
                pthread_detach(tid);
                printf("New client connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                break;
            }
        }
    }

    return 0;
}