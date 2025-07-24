//FormAI DATASET v1.0 Category: Chat server ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024 // buffer size for incoming messages
#define PORT 12345 // example port number

int main(int argc, char *argv[]) {
    int server_fd, client_fd; // file descriptors for server and client sockets
    struct sockaddr_in server_addr, client_addr; // server and client addresses
    char buffer[BUFFER_SIZE]; // buffer for incoming messages
    ssize_t read_length; // length of read message

    // create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    // bind socket to server address
    if (bind(server_fd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    // accept incoming connections
    socklen_t client_addr_len = sizeof(client_addr);
    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // main loop for receiving and sending messages
    while (1) {
        // read incoming message
        if ((read_length = read(client_fd, buffer, BUFFER_SIZE)) < 0) {
            perror("Error reading from socket");
            exit(EXIT_FAILURE);
        }

        if (read_length == 0) {
            // client disconnected
            printf("Client disconnected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            close(client_fd);
            break;
        }

        // print incoming message
        printf("Message from %s:%d - %s", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);

        // send response
        if (send(client_fd, buffer, read_length, 0) < 0) {
            perror("Error sending response");
            exit(EXIT_FAILURE);
        }
    }

    // close server socket
    close(server_fd);

    return 0;
}