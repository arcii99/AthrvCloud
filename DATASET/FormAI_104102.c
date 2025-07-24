//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFSIZE 1024

int main(int argc, char const *argv[]) {

    struct sockaddr_in server_address, client_address;
    memset(&server_address, 0, sizeof(server_address));

    // create a socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    // bind the socket to the port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    int bind_result = bind(server_fd, (struct sockaddr*) &server_address, sizeof(server_address));
    if (bind_result < 0) {
        printf("Failed to bind to port: %d\n", PORT);
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    int listen_result = listen(server_fd, 5);
    if (listen_result < 0) {
        printf("Failed to listen for incoming connections\n");
        exit(EXIT_FAILURE);
    }

    // accept incoming connections
    socklen_t client_address_size = sizeof(client_address);
    int client_fd = accept(server_fd, (struct sockaddr*) &client_address, &client_address_size);
    if (client_fd < 0) {
        printf("Failed to accept incoming connection\n");
        exit(EXIT_FAILURE);
    }

    printf("Client connected\n");

    // receive data from client
    char buffer[BUFSIZE];
    int read_bytes = read(client_fd, buffer, BUFSIZE - 1);
    if (read_bytes < 0) {
        printf("Failed to receive data from client\n");
        exit(EXIT_FAILURE);
    }

    buffer[read_bytes] = '\0';
    printf("Received data from client: %s\n", buffer);

    // send data to client
    char message[] = "Hello from server!";
    int send_bytes = send(client_fd, message, strlen(message), 0);
    if (send_bytes < 0) {
        printf("Failed to send data to client\n");
        exit(EXIT_FAILURE);
    }

    printf("Message sent to client\n");

    // close the connections
    close(client_fd);
    close(server_fd);

    return 0;
}