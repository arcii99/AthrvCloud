//FormAI DATASET v1.0 Category: Client Server Application ; Style: standalone
// This is a simple example of a C Client Server Application using sockets
// The server listens on a port for incoming client connections
// When a client connects, the server sends a message to the client and waits for a response
// The client responds with a message which the server receives and prints to the console

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 9000
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int serv_sock, cli_sock, recv_len;
    struct sockaddr_in serv_addr, cli_addr;
    char buf[BUFSIZE];

    // Create a socket for the server to listen on
    serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serv_sock == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address information
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    // Bind the server socket to the specified IP address and port
    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections from clients
    if (listen(serv_sock, SOMAXCONN) == -1) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    // Accept incoming client connection
    socklen_t cli_len = sizeof(cli_addr);
    cli_sock = accept(serv_sock, (struct sockaddr *)&cli_addr, &cli_len);
    if (cli_sock == -1) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    // Send message to client
    char message[] = "Welcome to the server!";
    if (send(cli_sock, message, strlen(message), 0) == -1) {
        perror("Error sending message to client");
        exit(EXIT_FAILURE);
    }

    // Receive response from client
    memset(buf, 0, BUFSIZE);
    recv_len = recv(cli_sock, buf, BUFSIZE, 0);
    if (recv_len == -1) {
        perror("Error receiving message from client");
        exit(EXIT_FAILURE);
    }

    // Print response from client
    printf("Client says: %s\n", buf);

    // Close client and server sockets
    close(cli_sock);
    close(serv_sock);

    return 0;
}