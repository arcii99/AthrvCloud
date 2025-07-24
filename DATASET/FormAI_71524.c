//FormAI DATASET v1.0 Category: Socket programming ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

void error(char *message) {
    fprintf(stderr, "%s", message);
    exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("Socket creation failed.\n");
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        error("Socket binding failed.\n");
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        error("Socket binding failed.\n");
    }

    // Allowing maximum 3 pending connections
    if (listen(server_fd, 3) < 0) {
        error("Server listening failed.\n");
    }

    printf("Server is listening on port %d...\n", PORT);

    // Accepting incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
        error("Connection could not be established.\n");
    }

    // Processing the incoming message
    valread = read(new_socket, buffer, MAX_BUFFER_SIZE);
    printf("Received message: %s\n", buffer);

    // Sending the response
    char *response = "Hello from server!";
    send(new_socket, response, strlen(response), 0);
    printf("Response sent to the client.\n");

    close(new_socket);
    close(server_fd);
    return 0;
}