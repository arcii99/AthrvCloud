//FormAI DATASET v1.0 Category: Socket programming ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sock, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char client_message[2000];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind
    if (bind(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Bind failed. Error");
        return 1;
    }
    puts("Bind done");

    // Listen
    listen(sock, 3);

    // Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(sock, (struct sockaddr *) &client, (socklen_t *) &c))) {
        puts("Connection accepted");

        // Receive a message from client
        while ((read_size = recv(client_sock, client_message, 2000, 0)) > 0) {
            // Send the message back to client
            write(client_sock, client_message, strlen(client_message));
            memset(client_message, 0, sizeof(client_message));
        }

        if (read_size == 0) {
            puts("Client disconnected");
            fflush(stdout);
            close(client_sock);
        } else if (read_size == -1) {
            perror("Recv failed");
        }
    }

    if (client_sock < 0) {
        perror("Accept failed");
        return 1;
    }

    return 0;
}