//FormAI DATASET v1.0 Category: Socket programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000

int create_socket();
void bind_socket(int server_socket, struct sockaddr_in server_address);
void listen_socket(int server_socket);
void accept_socket(int server_socket, struct sockaddr_in client_address);
void send_message(int client_socket);
void receive_message(int client_socket);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_size;
    pid_t pid;

    server_socket = create_socket();
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);

    bind_socket(server_socket, server_address);
    listen_socket(server_socket);

    while(1) {
        client_address_size = sizeof(client_address);
        client_socket = accept(server_socket,
                               (struct sockaddr*)&client_address,
                               &client_address_size);

        pid = fork();

        if(pid == 0) {
            close(server_socket);
            send_message(client_socket);
            exit(0);
        }
        else {
            close(client_socket);
        }
    }

    close(server_socket);
    return 0;
}

int create_socket() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    return server_socket;
}

void bind_socket(int server_socket, struct sockaddr_in server_address) {
    if(bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }
}

void listen_socket(int server_socket) {
    if(listen(server_socket, SOMAXCONN) < 0) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }
}

void accept_socket(int server_socket, struct sockaddr_in client_address) {
    int client_socket;
    socklen_t client_address_size = sizeof(client_address);

    if((client_socket = accept(server_socket,
                                (struct sockaddr*)&client_address,
                                &client_address_size)) < 0) {
        perror("Error accepting client connection");
        exit(EXIT_FAILURE);
    }
}

void send_message(int client_socket) {
    char message[100];
    memset(message, 0, sizeof(message));

    printf("Enter message to send: ");
    fgets(message, 100, stdin);

    if(send(client_socket, message, strlen(message), 0) < 0) {
        perror("Failed to send message");
    }
}

void receive_message(int client_socket) {
    char message[100];
    memset(message, 0, sizeof(message));

    if(recv(client_socket, message, sizeof(message), 0) < 0) {
        perror("Failed to receive message");
    }

    printf("Received message: %s", message);
}