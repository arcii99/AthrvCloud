//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received, bytes_sent;
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Could not create server socket");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    inet_aton("216.58.194.174", &server_address.sin_addr);    // Google IP address

    if (connect(server_socket, (struct sockaddr *)&server_address,
                sizeof(server_address)) == -1) {
        perror("Could not connect to server");
        exit(1);
    }

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        bytes_sent = send(server_socket, buffer, bytes_received, 0);
        if (bytes_sent == -1) {
            perror("Could not send data to server");
            exit(1);
        }

        bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0);
        bytes_sent = send(client_socket, buffer, bytes_received, 0);
        if (bytes_sent == -1) {
            perror("Could not send data to client");
            exit(1);
        }
    }

    close(server_socket);
    close(client_socket);
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    unsigned int client_address_size = sizeof(client_address);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Could not create server socket");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8888);

    if (bind(server_socket, (struct sockaddr *)&server_address,
             sizeof(server_address)) == -1) {
        perror("Could not bind server socket to address");
        exit(1);
    }

    if (listen(server_socket, 10) == -1) {
        perror("Could not listen for incoming connections");
        exit(1);
    }

    printf("Server listening on port 8888...\n");

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address,
                               &client_address_size);
        if (client_socket == -1) {
            perror("Could not accept incoming connection");
            continue;
        }

        printf("Client connected from %s:%d\n", inet_ntoa(client_address.sin_addr),
               ntohs(client_address.sin_port));

        handle_client(client_socket);
        printf("Client disconnected\n");
    }

    close(server_socket);
    return 0;
}