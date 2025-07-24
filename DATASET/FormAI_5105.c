//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 9000
#define PROXY_PORT 8000
#define PROXY_IP "127.0.0.1"

/* This function displays an error message and exits the program */
void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int server_socket, proxy_socket, client_socket;
    struct sockaddr_in server_addr, proxy_addr, client_addr;
    char buffer[1024];
    int bytes_read;

    /* Create the server socket */
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) 
        error("ERROR: Could not create server socket");

    /* Bind the server socket to the server address */
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        error("ERROR: Could not bind server socket");

    /* Listen for incoming connections from clients */
    listen(server_socket, 5);
    printf("Server running on port %d ...\n", SERVER_PORT);

    /* Set up the proxy address */
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = inet_addr(PROXY_IP);
    proxy_addr.sin_port = htons(PROXY_PORT);

    /* Loop forever to accept incoming client connections */
    while (1) {
        socklen_t client_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_len);
        if (client_socket < 0) 
            error("ERROR: Could not accept client connection");

        printf("Accepted a connection from client %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        /* Create the proxy socket */
        proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (proxy_socket < 0) 
            error("ERROR: Could not create proxy socket");

        /* Connect to the proxy server */
        if (connect(proxy_socket, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) 
            error("ERROR: Could not connect to proxy server");

        while (1) {
            /* Read data from the client */
            bytes_read = read(client_socket, buffer, sizeof(buffer)-1);
            if (bytes_read < 0) 
                error("ERROR: Could not read from client");

            if (bytes_read == 0) 
                break;

            /* Write the data to the proxy */
            if (write(proxy_socket, buffer, bytes_read) < 0) 
                error("ERROR: Could not write to proxy");

            /* Read data from the proxy */
            bytes_read = read(proxy_socket, buffer, sizeof(buffer)-1);
            if (bytes_read < 0) 
                error("ERROR: Could not read from proxy");

            if (bytes_read == 0) 
                break;

            /* Write the data to the client */
            if (write(client_socket, buffer, bytes_read) < 0) 
                error("ERROR: Could not write to client");
        }

        printf("Closing connection with client %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        /* Close the sockets */
        close(client_socket);
        close(proxy_socket);
    }

    /* Close the server socket */
    close(server_socket);

    return 0;
}