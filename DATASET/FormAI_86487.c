//FormAI DATASET v1.0 Category: Client Server Application ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MESSAGE_LENGTH 1024
#define PORT 8080

void error_check(int val, char *message) {
    if (val < 0) {
        perror(message);
        exit(EXIT_FAILURE);
    }
}

void handle_client(int client_socket) {
    char message[MESSAGE_LENGTH];
    while (1) {
        memset(message, 0, MESSAGE_LENGTH);
        int read_val = read(client_socket, message, MESSAGE_LENGTH);
        if (read_val == 0) {
            printf("Client disconnected\n");
            break;
        }
        printf("Client says: %s\n", message);
        write(client_socket, message, strlen(message));
    }
}

int main() {
    int server_socket, client_socket, sock_opt = 1, addrlen = sizeof(struct sockaddr_in);
    struct sockaddr_in server_address, client_address;
    char message[MESSAGE_LENGTH];

    error_check((server_socket = socket(AF_INET, SOCK_STREAM, 0)), "socket creation failed");

    error_check(setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &sock_opt, sizeof(sock_opt)),
                "setsockopt");

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    error_check(bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)), "bind failed");

    error_check(listen(server_socket, 3), "listen failed");

    printf("Server is now listening on port %d\n", PORT);

    while (1) {
        error_check((client_socket = accept(server_socket, (struct sockaddr *) &client_address, (socklen_t *) &addrlen)),
                    "accept failed");

        printf("New client connected with IP address: %s and port: %d\n", inet_ntoa(client_address.sin_addr),
               ntohs(client_address.sin_port));

        int child_pid = fork();
        error_check(child_pid, "fork failed");

        if (child_pid == 0) {
            close(server_socket);
            handle_client(client_socket);
            exit(EXIT_SUCCESS);
        }

        close(client_socket);
    }
    return 0;
}