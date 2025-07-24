//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>

#define PROXY_PORT 8888
#define SERVER_PORT 80
#define BUFFER_SIZE 4096

int main(int argc, char **argv) {
    int server_socket, client_socket;
    struct sockaddr_in proxy_address, server_address, client_address;
    char buffer[BUFFER_SIZE];

    // create a proxy socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Could not create proxy socket");
        exit(EXIT_FAILURE);
    }

    // prepare the proxy address structure
    memset(&proxy_address, 0, sizeof(proxy_address));
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_address.sin_port = htons(PROXY_PORT);

    // bind the proxy socket to the proxy address
    if (bind(server_socket, (struct sockaddr *)&proxy_address, sizeof(proxy_address)) < 0) {
        perror("Could not bind proxy socket to proxy address");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_socket, SOMAXCONN) < 0) {
        perror("Could not listen for incoming connections");
        exit(EXIT_FAILURE);
    }
    printf("Proxy running on port %d...\n", PROXY_PORT);

    // accept incoming connections
    while (1) {
        socklen_t client_address_length = sizeof(client_address);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length)) < 0) {
            perror("Could not accept incoming connection");
            exit(EXIT_FAILURE);
        }

        // create a new process to handle the connection
        if (fork() == 0) {
            close(server_socket);

            // prepare the server address structure
            memset(&server_address, 0, sizeof(server_address));
            server_address.sin_family = AF_INET;
            server_address.sin_addr.s_addr = inet_addr(argv[1]);
            server_address.sin_port = htons(SERVER_PORT);

            // create a socket for the server
            if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                perror("Could not create server socket");
                exit(EXIT_FAILURE);
            }

            // connect to the server
            if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
                perror("Could not connect to server");
                exit(EXIT_FAILURE);
            }

            // forward the data from the client to the server
            ssize_t num_bytes_read, num_bytes_written;
            while ((num_bytes_read = read(client_socket, buffer, BUFFER_SIZE)) > 0) {
                if ((num_bytes_written = write(server_socket, buffer, num_bytes_read)) != num_bytes_read) {
                    perror("Could not forward data to server");
                    exit(EXIT_FAILURE);
                }
            }

            // close the client and server sockets
            close(client_socket);
            close(server_socket);

            return 0;
        }

        close(client_socket);
    }

    return 0;
}