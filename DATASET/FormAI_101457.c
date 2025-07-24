//FormAI DATASET v1.0 Category: Networking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8888
#define MAX_MSG_LENGTH 1024

int main() {
    int socket_desc, client_sock, client_size;
    struct sockaddr_in server, client;
    char client_msg[MAX_MSG_LENGTH];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Error creating socket");
        return 1;
    }

    // Prepare server address structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the socket to a port
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error binding socket");
        return 1;
    }

    // Listen for incoming connections
    listen(socket_desc, 3);

    printf("Waiting for incoming connections...\n");

    // Accept incoming connection
    client_size = sizeof(struct sockaddr_in);
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&client_size);
    if (client_sock < 0) {
        printf("Error accepting client connection");
        return 1;
    }

    printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

    // Receive data from client
    while (recv(client_sock, client_msg, MAX_MSG_LENGTH, 0) > 0) {
        printf("Received message: %s", client_msg);

        // Send response back to client
        char response[] = "Hello client, I received your message!";
        send(client_sock, response, strlen(response), 0);

        memset(client_msg, 0, MAX_MSG_LENGTH);
    }

    printf("Client disconnected\n");

    return 0;
}