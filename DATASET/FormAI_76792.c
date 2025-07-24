//FormAI DATASET v1.0 Category: Client Server Application ; Style: enthusiastic
/* Welcome to my awesome Client Server Application Example Program! */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, client_fd, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Opening the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is up and running!\n");

    // Accepting connections from clients
    if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Connection established with client.\n");

    char buffer[1024] = {0};
    char response[1024] = {0};
    while (1) {
        // Reading the client request
        if ((valread = read(client_fd, buffer, 1024)) == -1) {
            perror("Reading failed");
            exit(EXIT_FAILURE);
        }

        if (strcmp(buffer, "exit") == 0) {
            printf("Client has disconnected from the server.\n");
            break;
        }

        // Handling the client request
        printf("Client says: %s\n", buffer);
        sprintf(response, "Server says: Hi, I received your message: %s", buffer);

        // Sending response back to the client
        if (send(client_fd, response, strlen(response), 0) == -1) {
            perror("Sending failed");
            exit(EXIT_FAILURE);
        }
        memset(buffer, 0, sizeof(buffer));
        memset(response, 0, sizeof(response));
    }
    close(client_fd);
    close(server_fd);

    return 0;
}