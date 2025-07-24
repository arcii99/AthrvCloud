//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_NUMBER 7777
#define MESSAGE "Hello, this is a wireless network scanner program."

int main() {
    int socket_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    pid_t child_pid;

    // Creating the socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Failed to create socket.\n");
        exit(EXIT_FAILURE);
    }

    // Setting up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT_NUMBER);

    // Binding the socket to the address
    if (bind(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to bind socket.\n");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(socket_fd, 1) == -1) {
        printf("Failed to listen on socket.\n");
        exit(EXIT_FAILURE);
    }

    printf("Wireless network scanner program is running...\n");

    while (1) {
        socklen_t client_len = sizeof(client_addr);

        // Accepting incoming connections
        conn_fd = accept(socket_fd, (struct sockaddr *) &client_addr, &client_len);
        if (conn_fd == -1) {
            printf("Failed to accept connection.\n");
            continue;
        }

        // Forking the process to handle incoming requests in parallel
        child_pid = fork();
        if (child_pid == 0) { // Child process
            close(socket_fd);

            // Sending the message to the client
            if (send(conn_fd, MESSAGE, strlen(MESSAGE), 0) == -1) {
                printf("Failed to send message.\n");
            }

            // Receiving the response from the client
            memset(buffer, 0, sizeof(buffer));
            if (recv(conn_fd, buffer, sizeof(buffer), 0) == -1) {
                printf("Failed to receive message.\n");
            } else {
                // Printing the response from the client
                printf("Received message from %s: %s", inet_ntoa(client_addr.sin_addr), buffer);
            }

            close(conn_fd);
            exit(EXIT_SUCCESS);
        } else if (child_pid > 0) { // Parent process
            close(conn_fd);
        } else { // Error
            printf("Failed to fork process.\n");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}