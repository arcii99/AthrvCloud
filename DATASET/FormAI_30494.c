//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888
#define MAX_MSG_LENGTH 1024

int main(int argc, char const *argv[]) {
    int socket_desc, client_sock, c;
    struct sockaddr_in server, client;
    char client_msg[MAX_MSG_LENGTH], server_msg[MAX_MSG_LENGTH];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Failed to bind\n");
        return 1;
    }

    // Listen
    listen(socket_desc, 3);

    printf("Server listening on port %d\n", PORT);

    // Accept incoming connections
    c = sizeof(struct sockaddr_in);
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
    if (client_sock < 0) {
        printf("Failed to accept\n");
        return 1;
    }

    printf("Connection accepted\n");

    // Receive incoming messages from the client
    while (recv(client_sock, client_msg, MAX_MSG_LENGTH, 0) > 0) {
        printf("Client: %s\n", client_msg);

        // Send a response message back to the client
        printf("Enter your message: ");
        fgets(server_msg, MAX_MSG_LENGTH, stdin);
        send(client_sock, server_msg, strlen(server_msg), 0);
        memset(client_msg, 0, MAX_MSG_LENGTH);
        memset(server_msg, 0, MAX_MSG_LENGTH);
    }

    if (client_sock < 0) {
        printf("Connection ended\n");
    }

    return 0;
}