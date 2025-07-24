//FormAI DATASET v1.0 Category: Chat server ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

void send_message(int socket_fd, char* message) {
    write(socket_fd, message, strlen(message));
}

int main() {
    int server_socket_fd, client_socket_fd;
    char buffer[256];
    struct sockaddr_in server_address, client_address;
    int option = 1;
    socklen_t client_address_len = sizeof(client_address);

    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option))) {
        printf("Error setting socket options\n");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    if (bind(server_socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket_fd, 3) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server started listening on port 8080\n");

    while(1) {
        client_socket_fd = accept(server_socket_fd, (struct sockaddr*)&client_address, &client_address_len);

        if (client_socket_fd < 0) {
            printf("Error accepting client connection\n");
            exit(1);
        }

        printf("Client connected\n");

        send_message(client_socket_fd, "Welcome to the mind-bending chat server. What's on your mind?\n");

        while(1) {
            bzero(buffer, sizeof(buffer));
            read(client_socket_fd, buffer, sizeof(buffer));

            if(strcmp("exit\n", buffer) == 0) {
                send_message(client_socket_fd, "Goodbye!\n");
                close(client_socket_fd);
                printf("Client disconnected\n");
                break;
            }

            send_message(client_socket_fd, "I'm sorry, I don't understand. Let's try something else.\n");
        }
    }

    close(server_socket_fd);
    return 0;
}