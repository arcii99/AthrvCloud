//FormAI DATASET v1.0 Category: Simple Web Server ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 4096

void error(char *msg) {
    // Display error message and terminate program
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    char buffer[BUFSIZE];
    int optval = 1;
    int n;

    // Create socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        error("ERROR opening socket");
    }

    // Set socket options
    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        error("ERROR setting socket options");
    }

    // Bind socket
    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR binding socket");
    }

    // Listen for incoming connections
    if (listen(server_sock, 5) < 0) {
        error("ERROR listening for connections");
    }

    printf("Server is up and running!\n");

    while (1) {
        client_len = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            error("ERROR accepting connection");
        }

        printf("Handling request...\n");

        // Receive request from client
        memset(buffer, 0, BUFSIZE);
        n = read(client_sock, buffer, BUFSIZE - 1);
        if (n < 0) {
            error("ERROR reading from socket");
        }

        // Send response to client
        n = write(client_sock, "HTTP/1.1 200 OK\n", 16);
        if (n < 0) {
            error("ERROR writing to socket");
        }
        n = write(client_sock, "Content-length: 20\n", 19);
        if (n < 0) {
            error("ERROR writing to socket");
        }
        n = write(client_sock, "Content-Type: text/html\n\n", 25);
        if (n < 0) {
            error("ERROR writing to socket");
        }
        n = write(client_sock, "<h1>Hello World!</h1>", 22);
        if (n < 0) {
            error("ERROR writing to socket");
        }

        // Close client socket
        close(client_sock);
    }

    // Close server socket
    close(server_sock);

    return 0;
}