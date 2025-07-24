//FormAI DATASET v1.0 Category: Client Server Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 5000
#define MAX_CLIENTS 10

int main(int argc, char const *argv[]) {
    int server_fd, addrlen;
    struct sockaddr_in address;
    int opt = 1;
    char buffer[1024] = {0};

    // Create a Socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set Socket Options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Define the Address to Bind
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    addrlen = sizeof(address);

    // Bind the Socket to the Address
    if (bind(server_fd, (struct sockaddr *) &address, addrlen) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for Clients
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept Clients and Send/Receive Messages
    int client_socket;
    for (;;) {
        if ((client_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t*) &addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Client connected\n");

        // Send Welcome Message
        char *welc_msg = "Welcome to my server!";
        send(client_socket, welc_msg, strlen(welc_msg), 0);

        // Receive Client Message
        while (1) {
            memset(buffer, 0, sizeof(buffer));
            int valread = recv(client_socket, buffer, 1024, 0);
            if (valread <= 0) {
                printf("Client disconnected\n");
                break;
            }
            
            printf("Received Message: %s\n", buffer);
            
            // Echo Back Client Message
            send(client_socket, buffer, strlen(buffer), 0);
        }

        close(client_socket);
    }

    return 0;
}