//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, val_read;
    struct sockaddr_in server_address;

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening on the socket
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on localhost:%d\n", PORT);

    while (1) {
        struct sockaddr_in client_address;
        int client_address_length = sizeof(client_address);

        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t*)&client_address_length)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        char buffer[BUFFER_SIZE] = {0};
        char request[BUFFER_SIZE] = {0};

        // Read the request from the client
        val_read = read(new_socket, buffer, BUFFER_SIZE);
        if (val_read < 0) {
            perror("Read failed");
            exit(EXIT_FAILURE);
        }

        printf("Received request:\n%s", buffer);

        // Parse the request and extract the hostname and port
        char *hostname_start = strchr(buffer, ' ') + 1;
        char *hostname_end = strchr(hostname_start, ':');
        int port_offset = 0;
        if (hostname_end == NULL) {
            hostname_end = strchr(hostname_start, '/');
            port_offset = 4;
        }

        char hostname[hostname_end - hostname_start + 1];
        memcpy(hostname, hostname_start, hostname_end - hostname_start);
        hostname[hostname_end - hostname_start] = '\0';

        char *port_start = hostname_end + port_offset;
        char *port_end = strchr(port_start, ' ');
        char port[port_end - port_start + 1];
        memcpy(port, port_start, port_end - port_start);
        port[port_end - port_start] = '\0';

        printf("Fetching data from %s:%s\n", hostname, port);

        // Create a new socket to connect to the remote server
        int remote_socket;
        if ((remote_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("Remote socket creation failed");
            exit(EXIT_FAILURE);
        }

        struct sockaddr_in remote_address;
        remote_address.sin_family = AF_INET;
        remote_address.sin_port = htons(atoi(port));
        if (inet_pton(AF_INET, hostname, &remote_address.sin_addr) <= 0) {
            perror("Invalid address");
            exit(EXIT_FAILURE);
        }

        // Connect to the remote server
        if (connect(remote_socket, (struct sockaddr *)&remote_address, sizeof(remote_address)) < 0) {
            perror("Connection failed");
            exit(EXIT_FAILURE);
        }

        // Forward the request to the remote server and receive the response
        if (write(remote_socket, buffer, strlen(buffer)) < 0) {
            perror("Write failed");
            exit(EXIT_FAILURE);
        }

        int bytes_received = 0;
        char response_buffer[BUFFER_SIZE] = {0};
        while ((val_read = read(remote_socket, response_buffer + bytes_received, BUFFER_SIZE - bytes_received)) > 0) {
            bytes_received += val_read;
        }

        if (val_read < 0) {
            perror("Read failed");
            exit(EXIT_FAILURE);
        }

        // Forward the response to the client
        if (write(new_socket, response_buffer, bytes_received) < 0) {
            perror("Write failed");
            exit(EXIT_FAILURE);
        }

        printf("Forwarded response:\n%s", response_buffer);

        // Close the sockets
        close(new_socket);
        close(remote_socket);
    }

    return 0;
}