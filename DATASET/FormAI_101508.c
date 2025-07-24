//FormAI DATASET v1.0 Category: Client Server Application ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 8080
#define QUEUE_LENGTH 20
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket, opt = 1;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE] = {0};
    int addrlen = sizeof(server_address);

    // create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed.");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed.");
        exit(EXIT_FAILURE);
    }

    // set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed.");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_socket, QUEUE_LENGTH) < 0) {
        perror("Listen failed.");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // accept incoming connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed.");
            exit(EXIT_FAILURE);
        }

        // get client IP address
        char *client_ip = inet_ntoa(client_address.sin_addr);

        printf("Connection established with %s:%d\n", client_ip, ntohs(client_address.sin_port));

        // receive data from client
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received < 0) {
            perror("Receive failed.");
            exit(EXIT_FAILURE);
        }

        printf("Received data: %s\n", buffer);

        // send response to client
        char *response = "Hello from server!";
        if (send(client_socket, response, strlen(response), 0) < 0) {
            perror("Send failed.");
            exit(EXIT_FAILURE);
        }

        printf("Response sent: %s\n", response);

        // close client socket
        close(client_socket);
        printf("Connection with %s:%d closed.\n", client_ip, ntohs(client_address.sin_port));
    }

    // close server socket
    close(server_socket);

    return 0;
}