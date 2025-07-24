//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: lively
/* Welcome to our Simple HTTP Proxy example program!
 * This program will act as a middleman between the client and the server,
 * intercepting and modifying HTTP requests and responses.
 *
 * Before we start, we need to include some necessary libraries and define a few constants.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define BACKLOG 10

/* Next, we define a function that will handle each client connection.
 * This function will receive an open socket connected to a client and will forward the request to the server.
 * It will also receive the server's response and forward it back to the client.
 */

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int bytes_received, bytes_sent;
    size_t total_bytes_sent = 0;

    // Receive request from client
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("Failed to receive request from client");
        close(client_socket);
        return;
    }
    // Copy request to a separate buffer to modify it if necessary
    strncpy(request, buffer, bytes_received);

    // Extract host and port from the request
    char *host = strstr(request, "Host: ");
    if (host) {
        host += strlen("Host: ");
        char *end_of_host = strchr(host, '\r');
        *end_of_host = '\0';
        char *delimiter = strchr(host, ':');
        if (delimiter) {
            *delimiter = '\0';
            delimiter++;
            int port = atoi(delimiter);
            host = strtok(host, "/");
            printf("Connecting to %s on port %d\n", host, port);

            // Resolve hostname to IP address
            struct addrinfo hints, *res;
            memset(&hints, 0, sizeof(hints));
            hints.ai_family = AF_INET;
            if (getaddrinfo(host, NULL, &hints, &res) != 0) {
                perror("Failed to resolve hostname");
                close(client_socket);
                return;
            }

            // Open socket to server
            int server_socket = socket(AF_INET, SOCK_STREAM, 0);
            if (server_socket < 0) {
                perror("Failed to create socket to server");
                close(client_socket);
                return;
            }
            struct sockaddr_in server_address;
            server_address.sin_family = AF_INET;
            server_address.sin_port = htons(port);
            server_address.sin_addr = ((struct sockaddr_in *)res->ai_addr)->sin_addr;
            freeaddrinfo(res);
            if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
                perror("Failed to connect to server");
                close(server_socket);
                close(client_socket);
                return;
            }

            // Forward request to server
            bytes_sent = send(server_socket, buffer, bytes_received, 0);
            if (bytes_sent < 0) {
                perror("Failed to forward request to server");
                close(server_socket);
                close(client_socket);
                return;
            }

            // Receive response from server and forward it to client
            while ((bytes_received = recv(server_socket, response, BUFFER_SIZE, 0)) > 0) {
                bytes_sent = send(client_socket, response, bytes_received, 0);
                if (bytes_sent < 0) {
                    perror("Failed to forward response to client");
                    close(server_socket);
                    close(client_socket);
                    return;
                }
                total_bytes_sent += bytes_sent;
                memset(response, 0, BUFFER_SIZE);
            }
            printf("Forwarded %zu bytes from server to client\n", total_bytes_sent);
            close(server_socket);
            return;
        }
    }
    printf("Malformed HTTP request received from client: %s", buffer);
    close(client_socket);
    return;
}

/* Finally, we write our main function that will initialize the listening socket and will wait for incoming connections. */

int main(int argc, char **argv) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;

    // Open socket for listening
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket");
        exit(1);
    }
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind socket");
        exit(1);
    }
    if (listen(server_socket, BACKLOG) < 0) {
        perror("Failed to listen on socket");
        exit(1);
    }

    printf("Simple HTTP proxy listening on port 8080...\n");

    // Wait for incoming connections
    while (1) {
        socklen_t client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket < 0) {
            perror("Failed to accept incoming connection");
            continue;
        }
        handle_client(client_socket);
    }

    close(server_socket);
    return 0;
}