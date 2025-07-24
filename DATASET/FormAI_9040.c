//FormAI DATASET v1.0 Category: Networking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT_NUMBER 8888

int main(int argc, char *argv[]) {
    int socket_file_descriptor, client_file_descriptor;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);
    char buffer[BUFFER_SIZE] = {0};
    char *welcome_message = "Welcome to my networking program!\n";

    // Creating socket file descriptor
    if ((socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    int opt = 1;
    if (setsockopt(socket_file_descriptor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setting socket options failed");
        exit(EXIT_FAILURE);
    }

    // Setting server address and binding with socket
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT_NUMBER);

    if (bind(socket_file_descriptor, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Binding socket with server address failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(socket_file_descriptor, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT_NUMBER);

    while (1) {
        // Accepting incoming connection
        if ((client_file_descriptor = accept(socket_file_descriptor, (struct sockaddr *) &client_address, &client_address_len)) < 0) {
            perror("Accepting connection failed");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Sending welcome message to client
        if (send(client_file_descriptor, welcome_message, strlen(welcome_message), 0) < 0) {
            perror("Sending welcome message failed");
            exit(EXIT_FAILURE);
        }

        while (1) {
            // Receiving client message
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(client_file_descriptor, buffer, BUFFER_SIZE, 0);
            if (bytes_received < 0) {
                perror("Receiving message failed");
                exit(EXIT_FAILURE);
            } else if (bytes_received == 0) {
                printf("Connection closed by %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                break;
            }

            printf("Received message from %s:%d: %s", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), buffer);

            // Echoing back client message
            if (send(client_file_descriptor, buffer, strlen(buffer), 0) < 0) {
                perror("Sending message failed");
                exit(EXIT_FAILURE);
            }
        }

        close(client_file_descriptor);
        printf("Waiting for incoming connections...\n");
    }

    close(socket_file_descriptor);
    return 0;
}