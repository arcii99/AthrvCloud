//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PROXY_PORT 8080
#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <remote_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket for the proxy server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        perror("Error creating the socket");
        exit(EXIT_FAILURE);
    }

    // Set up the socket address for the proxy server
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(PROXY_PORT);

    // Bind the socket to the socket address
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding the socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Error listening for incoming connections");
        exit(EXIT_FAILURE);
    }

    // Print a message to show that the proxy server is running
    printf("Proxy server running on port %d\n", PROXY_PORT);

    while (1) {

        // Wait for a client to connect
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            perror("Error accepting incoming connection");
            exit(EXIT_FAILURE);
        }

        // Read the client's request
        char client_buffer[MAX_BUF_SIZE + 1];
        int bytes_read = read(client_socket, client_buffer, MAX_BUF_SIZE);
        if (bytes_read == -1) {
            perror("Error reading client request");
            exit(EXIT_FAILURE);
        }
        client_buffer[bytes_read] = '\0';

        // Print the client's request
        printf("Client request:\n%s\n", client_buffer);

        // Create a socket for the remote server
        int remote_socket = socket(AF_INET, SOCK_STREAM, 0);

        if (remote_socket == -1) {
            perror("Error creating the remote socket");
            exit(EXIT_FAILURE);
        }

        // Set up the socket address for the remote server
        struct sockaddr_in remote_address;
        memset(&remote_address, 0, sizeof(remote_address));
        remote_address.sin_family = AF_INET;
        remote_address.sin_addr.s_addr = inet_addr(argv[1]);
        remote_address.sin_port = htons(80);

        // Connect to the remote server
        if (connect(remote_socket, (struct sockaddr*)&remote_address, sizeof(remote_address)) == -1) {
            perror("Error connecting to remote server");
            exit(EXIT_FAILURE);
        }

        // Send the client's request to the remote server
        if (write(remote_socket, client_buffer, strlen(client_buffer)) == -1) {
            perror("Error sending request to remote server");
            exit(EXIT_FAILURE);
        }

        // Read the response from the remote server
        char remote_buffer[MAX_BUF_SIZE + 1];
        bytes_read = read(remote_socket, remote_buffer, MAX_BUF_SIZE);
        if (bytes_read == -1) {
            perror("Error reading response from remote server");
            exit(EXIT_FAILURE);
        }
        remote_buffer[bytes_read] = '\0';

        // Print the response from the remote server
        printf("Response from remote server:\n%s\n", remote_buffer);

        // Send the response from the remote server to the client
        if (write(client_socket, remote_buffer, strlen(remote_buffer)) == -1) {
            perror("Error sending response to client");
            exit(EXIT_FAILURE);
        }

        // Close the sockets
        close(remote_socket);
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}