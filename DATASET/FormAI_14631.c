//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT_NUMBER 8888
#define MAX_CONNECTIONS 10
#define MAX_BUFFER 1024

void handle_client(int client_socket);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t addr_len = sizeof(client_address);
    memset(&server_address, 0, sizeof(server_address));

    // create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // set server address fields
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT_NUMBER);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    // bind socket to address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("Failed to listen for connections");
        exit(EXIT_FAILURE);
    }

    printf("HTTP Proxy Server listening on port %d\n", PORT_NUMBER);

    while (1) {
        // accept incoming connection
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &addr_len);
        if (client_socket < 0) {
            perror("Failed to accept connection");
            continue;
        }

        // fork a child process to handle client request
        if (fork() == 0) {
            close(server_socket);
            handle_client(client_socket);
            close(client_socket);
            exit(EXIT_SUCCESS);
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[MAX_BUFFER] = {0};
    ssize_t read_size, send_size;

    // receive request from client
    read_size = recv(client_socket, buffer, MAX_BUFFER, 0);
    if (read_size < 0) {
        perror("Failed to receive request");
        return;
    }

    // parse request to extract destination host and port
    char *host, *port;
    host = strstr(buffer, "Host:");
    if (host) {
        host += strlen("Host:");
        while (*host == ' ') host++;
        port = strstr(host, ":");
        if (port) {
            *port = '\0';
            port += 1;
        } else {
            port = "80";
        }
    } else {
        perror("Failed to extract host from request");
        return;
    }

    // establish connection to destination server
    int server_socket;
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket");
        return;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(port));

    if (inet_pton(AF_INET, host, &server_address.sin_addr) <= 0) {
        perror("Invalid destination address");
        return;
    }

    if (connect(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to destination server");
        return;
    }

    printf("Connected to %s:%s\n", host, port);

    // forward request to destination server
    send_size = send(server_socket, buffer, strlen(buffer), 0);
    if (send_size < 0) {
        perror("Failed to send request");
        return;
    }

    // receive response from destination server and forward to client
    while ((read_size = recv(server_socket, buffer, MAX_BUFFER, 0)) > 0) {
        send_size = send(client_socket, buffer, read_size, 0);
        if (send_size < 0) {
            perror("Failed to send response");
            return;
        }
    }

    if (read_size < 0) {
        perror("Failed to receive response");
        return;
    }

    printf("Request forwarded successfully\n");
}