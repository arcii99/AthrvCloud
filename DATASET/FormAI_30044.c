//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_BUFFER_SIZE 2048 // maximum buffer size of incoming requests
#define SERVER_PORT 8080 // the port number the proxy server listens to

void handle_request(int client_socket); // function to handle incoming requests
void proxy_request(int client_socket, char *host, int port, char *request); // function to proxy requests

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);

    // create a socket for the server
    if ((server_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("failed to create server socket");
        return EXIT_FAILURE;
    }

    // set up the server address and bind it to the socket
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(SERVER_PORT);
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("failed to bind server socket");
        return EXIT_FAILURE;
    }

    // listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("failed to listen for incoming connections");
        return EXIT_FAILURE;
    }

    printf("proxy server is running on port %d\n", SERVER_PORT);

    // handle incoming requests continuously
    while (1) {
        // accept incoming connections
        if ((client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_len)) < 0) {
            perror("failed to accept incoming connection");
            continue;
        }

        // handle the request from the client
        handle_request(client_socket);

        // close the client socket
        close(client_socket);
    }

    // close the server socket
    close(server_socket);

    return EXIT_SUCCESS;
}

void handle_request(int client_socket) {
    char buffer[MAX_BUFFER_SIZE];
    ssize_t bytes_received;

    // receive the request from the client
    memset(buffer, 0, MAX_BUFFER_SIZE);
    if ((bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE - 1, 0)) < 0) {
        perror("failed to receive request from client");
        return;
    }

    // check if the request is valid
    if (bytes_received == 0 || strstr(buffer, "GET") == NULL) {
        return;
    }

    // get the host and port from the request
    char *host_start = strstr(buffer, "Host: ") + strlen("Host: ");
    char *host_end = strstr(host_start, "\r\n");
    char host[MAX_BUFFER_SIZE];
    strncpy(host, host_start, host_end - host_start);
    host[host_end - host_start] = '\0';
    int port = 80;
    char *port_start = strchr(host, ':');
    if (port_start != NULL) {
        port = atoi(port_start + 1);
        *port_start = '\0';
    }

    // proxy the request to the host
    proxy_request(client_socket, host, port, buffer);
}

void proxy_request(int client_socket, char *host, int port, char *request) {
    int proxy_socket;
    struct sockaddr_in proxy_address;

    // create a socket for the proxy
    if ((proxy_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("failed to create proxy socket");
        return;
    }

    // connect to the host
    memset(&proxy_address, 0, sizeof(proxy_address));
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = inet_addr(host);
    proxy_address.sin_port = htons(port);
    if (connect(proxy_socket, (struct sockaddr *) &proxy_address, sizeof(proxy_address)) < 0) {
        perror("failed to connect to host");
        return;
    }

    // send the request to the host
    if (send(proxy_socket, request, strlen(request), 0) < 0) {
        perror("failed to send request to host");
        return;
    }

    // proxy the response from the host back to the client
    char buffer[MAX_BUFFER_SIZE];
    ssize_t bytes_received;
    while ((bytes_received = recv(proxy_socket, buffer, MAX_BUFFER_SIZE - 1, 0)) > 0) {
        if (send(client_socket, buffer, bytes_received, 0) < 0) {
            perror("failed to send response to client");
            break;
        }
        memset(buffer, 0, MAX_BUFFER_SIZE);
    }

    // close the proxy socket
    close(proxy_socket);
}