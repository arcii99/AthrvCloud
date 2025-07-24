//FormAI DATASET v1.0 Category: Socket programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

void error(char *message) {
    perror(message);
    exit(1);
}

int create_socket() {
    int my_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (my_socket < 0) {
        error("Error while creating socket.");
    }
    return my_socket;
}

void bind_socket(int my_socket, struct sockaddr_in server_address) {
    int bind_status = bind(my_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (bind_status < 0) {
        error("Error while binding socket to port.");
    }
}

void listen_socket(int my_socket) {
    int listen_status = listen(my_socket, 5);
    if (listen_status < 0) {
        error("Error while listening on socket.");
    }
}

int accept_client(int my_socket, struct sockaddr_in client_address, int client_address_length) {
    int client_socket = accept(my_socket, (struct sockaddr *) &client_address, (socklen_t *) &client_address_length);
    if (client_socket < 0) {
        error("Error while accepting client connection.");
    }
    return client_socket;
}

void receive_message(int client_socket) {
    char buffer[1024] = {0};
    int read_status = read(client_socket, buffer, 1024);
    if (read_status < 0) {
        error("Error while reading message from client.");
    } else {
        printf("Client: %s", buffer);
    }
}

void send_message(int client_socket) {
    char message[1024];
    printf("Server: ");
    fgets(message, 1024, stdin);

    int write_status = write(client_socket, message, strlen(message));
    if (write_status < 0) {
        error("Error while sending message to client.");
    }
}

int main() {
    int my_socket, client_socket, client_address_length;
    struct sockaddr_in server_address, client_address;

    my_socket = create_socket();

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    bind_socket(my_socket, server_address);

    listen_socket(my_socket);

    printf("Waiting for client connection...\n");

    client_address_length = sizeof(client_address);
    client_socket = accept_client(my_socket, client_address, client_address_length);

    printf("Client connected successfully.\n");

    while (1) {
        receive_message(client_socket);

        send_message(client_socket);
    }

    close(client_socket);
    close(my_socket);

    return 0;
}