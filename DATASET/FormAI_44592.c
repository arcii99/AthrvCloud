//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUFSIZE 1024
#define PORT 1234

void sigint_handler(int signal);
void start_server(int port);
void handle_client(int client_socket);
int check_network_qos();

int main(int argc, char** argv) {
    signal(SIGINT, sigint_handler);

    printf("Starting QoS monitor...\n");

    start_server(PORT);

    return 0;
}

void sigint_handler(int signal) {
    printf("Stopping QoS monitor...\n");
    exit(0);
}

void start_server(int port) {
    printf("Starting server on port %d...\n", port);

    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (server_socket < 0) {
        printf("Error creating server socket\n");
        exit(-1);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Error binding server socket\n");
        exit(-1);
    }

    if (listen(server_socket, 5) < 0) {
        printf("Error listening on server socket\n");
        exit(-1);
    }

    printf("Server started!\n");

    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_length);

        if (client_socket < 0) {
            printf("Error accepting client connection\n");
            exit(-1);
        }

        printf("New client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        handle_client(client_socket);
    }
}

void handle_client(int client_socket) {
    char buffer[BUFSIZE];

    if (recv(client_socket, buffer, BUFSIZE, 0) <= 0) {
        printf("Error receiving data from client\n");
    }

    char* response = (check_network_qos() ? "OK" : "BAD");
    send(client_socket, response, strlen(response), 0);
    close(client_socket);
}

int check_network_qos() {
    // TODO: Implement QoS check

    // Placeholder for now
    return rand() % 2;
}