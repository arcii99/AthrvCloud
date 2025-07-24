//FormAI DATASET v1.0 Category: Networking ; Style: visionary
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char client_message[2000];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind the socket
    if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Bind failed");
        return 1;
    }

    // Listen on the socket
    listen(socket_desc, 3);

    // Accept connection from an incoming client
    printf("Waiting for incoming connections...\n");
    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t *) &c))) {
        printf("Connection accepted\n");

        // Receive a message from client
        while ((read_size = recv(client_sock, client_message, 2000, 0)) > 0) {
            // Send the message back to client
            write(client_sock, client_message, strlen(client_message));
            memset(client_message, 0, sizeof client_message);
        }

        if (read_size == 0) {
            printf("Client disconnected\n");
        } else if (read_size == -1) {
            perror("recv failed");
        }
    }

    return 0;
}