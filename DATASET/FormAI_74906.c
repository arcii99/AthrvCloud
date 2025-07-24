//FormAI DATASET v1.0 Category: Firewall ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

#define PORT 8080
#define MAX_PENDING_CONNECTIONS 10
#define MAX_BUFFER_SIZE 1024

void handle_interrupt_signal(int sig) {
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
    struct sockaddr_in server_addr, client_addr;
    int server_socket_fd, client_socket_fd, opt = 1;
    char buffer[MAX_BUFFER_SIZE] = {0};
    int addr_len = sizeof(client_addr);

    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket_fd, MAX_PENDING_CONNECTIONS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, handle_interrupt_signal);
    
    while (1) {
        if ((client_socket_fd = accept(server_socket_fd, (struct sockaddr *) &client_addr, (socklen_t *) &addr_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        if (inet_ntop(AF_INET, &client_addr.sin_addr, buffer, sizeof(buffer)) == NULL) {
            perror("Inet_ntop failed");
            exit(EXIT_FAILURE);
        }

        printf("Incoming connection from %s:%d\n", buffer, ntohs(client_addr.sin_port));

        if ((read(client_socket_fd, buffer, MAX_BUFFER_SIZE)) < 0) {
            perror("Read failed");
            exit(EXIT_FAILURE);
        }

        printf("Data : %s\n", buffer);

        if (strncmp(buffer, "GET / HTTP/1.1", 14) == 0) {
            strcpy(buffer, "HTTP/1.1 200 OK\nContent-Type: text/html\n<html><body><h1>Success!</h1></body></html>");
        } else {
            strcpy(buffer, "HTTP/1.1 403 Forbidden\nContent-Type: text/html\n<html><body><h1>Failed!</h1></body></html>");
        }

        if ((send(client_socket_fd, buffer, strlen(buffer), 0)) < 0) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }

        close(client_socket_fd);
    }

    return 0;
}