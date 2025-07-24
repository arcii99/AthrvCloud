//FormAI DATASET v1.0 Category: Educational ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000

int main(int argc, char **argv) {
    // create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // bind socket to address and port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // listen for connections
    if (listen(server_socket, 5) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // accept connections
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    int client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_len);
    if (client_socket == -1) {
        perror("accept");
        return EXIT_FAILURE;
    }

    // read client's data
    char buffer[1024];
    int bytes_read = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_read == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // print client's data
    printf("Received from client: %.*s\n", bytes_read, buffer);

    // send response back to the client
    char response[] = "Hello from server!";
    if (send(client_socket, response, strlen(response), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // close sockets
    close(client_socket);
    close(server_socket);

    return EXIT_SUCCESS;
}