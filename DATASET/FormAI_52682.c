//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 9000
#define MAX_CONS 5

int main() {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    unsigned int client_len = sizeof(client_addr);

    // create socket
    listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listen_socket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // set socket options
    int optval = 1;
    if (setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); // bind to any available address
    server_addr.sin_port = htons(PORT);

    // bind socket to server address
    if (bind(listen_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(listen_socket, MAX_CONS) == -1) {
        perror("Error listening");
        exit(EXIT_FAILURE);
    }

    // accept incoming connections
    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *) &client_addr, &client_len);
        if (client_socket == -1) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }
        printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // send message to client
        char message[] = "Hello, client!";
        if (send(client_socket, message, strlen(message), 0) == -1) {
            perror("Error sending message");
            close(client_socket);
            continue;
        }

        // receive message from client
        char buffer[1024] = {0};
        ssize_t bytes_read = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_read == -1) {
            perror("Error receiving message");
            close(client_socket);
            continue;
        }
        printf("Received message from client: %s\n", buffer);

        // close client socket
        close(client_socket);
    }

    // close server socket
    close(listen_socket);

    return 0;
}