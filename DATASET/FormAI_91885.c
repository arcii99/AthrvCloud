//FormAI DATASET v1.0 Category: Chat server ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 8080

int main(int argc, char *argv[]) {

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *welcome_message = "Welcome to Retro Chat!\n";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for clients to connect...\n");

    // Handle incoming connections
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New Connection! IP: %s Port: %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Send welcome message to the client
        send(new_socket, welcome_message, strlen(welcome_message), 0);

        // Handle chat
        while (1) {
            memset(buffer, 0, sizeof(buffer));
            valread = read(new_socket, buffer, 1024);
            if (valread < 0) {
                if (errno == EINTR) {
                    // Interrupted by signal, continue waiting for input
                    continue;
                }
                perror("read");
                exit(EXIT_FAILURE);
            } else if (valread == 0) {
                // Socket closed by client, end chat
                break;
            } else {
                printf("Message Received: %s", buffer);
                send(new_socket, buffer, strlen(buffer), 0);
            }
        }

        // Close the socket
        close(new_socket);
        printf("Client Disconnected\n");
    }

    return 0;
}