//FormAI DATASET v1.0 Category: Socket programming ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int socket_fd, connection_fd, read_val;
    struct sockaddr_in server_address, client_addr;
    char buffer[MAX_BUFFER_SIZE] = {0};
    char secret_code[] = "neo_1234"; // secret code to access server

    // Create socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Assign port and IP address to socket
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to IP address and port number
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connection
    if (listen(socket_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Waiting for cyberpunk connections...\n");

    while (1) {
        // Accept incoming connection
        int addr_len = sizeof(client_addr);
        if ((connection_fd = accept(socket_fd, (struct sockaddr *)&client_addr, (socklen_t *)&addr_len)) < 0) {
            perror("Accept connection failed");
            exit(EXIT_FAILURE);
        }

        printf("New cyberpunk connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        send(connection_fd, "Welcome cyberpunk, please enter the secret code: ", strlen("Welcome cyberpunk, please enter the secret code: "), 0);

        // Read secret code from the client
        read_val = read(connection_fd, buffer, MAX_BUFFER_SIZE);
        if (read_val < 0) {
            perror("Read failed");
            exit(EXIT_FAILURE);
        }

        if (strcmp(buffer, secret_code) == 0) {
            printf("Access granted for cyberpunk at %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            send(connection_fd, "Congratulations, you have been granted access to the server\n", strlen("Congratulations, you have been granted access to the server\n"), 0);
        } else {
            printf("Access denied for cyberpunk at %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            send(connection_fd, "Access denied, the secret code is incorrect\n", strlen("Access denied, the secret code is incorrect\n"), 0);
        }

        // Close the connection
        close(connection_fd);
    }

    return 0;
}