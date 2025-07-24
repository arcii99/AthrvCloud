//FormAI DATASET v1.0 Category: Chat server ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char *message, client_message[2000];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Failed to create socket");
        return 1;
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind
    if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        puts("bind failed");
        return 1;
    }
    puts("bind done");

    // Listen
    listen(socket_desc, 3);

    // Accept incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t *) &c))) {
        puts("Connection accepted");

        // Send welcome message to client
        message = "Welcome to the chat server! Say something: ";
        write(client_sock, message, strlen(message));

        // Receive client messages
        while ((read_size = recv(client_sock, client_message, 2000, 0)) > 0) {
            // Shape-shift into uppercase
            for (int i = 0; client_message[i]; i++) {
                if (client_message[i] >= 'a' && client_message[i] <= 'z') {
                    client_message[i] -= 32;
                }
            }

            // Echo message back to client
            write(client_sock, client_message, strlen(client_message));
        }

        // Client disconnected
        if (read_size == 0) {
            puts("Client disconnected");
            fflush(stdout);
        } else if (read_size == -1) {
            perror("recv failed");
        }
    }

    if (client_sock < 0) {
        perror("accept failed");
        return 1;
    }
    return 0;
}