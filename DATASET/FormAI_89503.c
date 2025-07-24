//FormAI DATASET v1.0 Category: Client Server Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_LENGTH 1024
#define SERVER_PORT 8080

int main(int argc, char const *argv[]) {

    int socket_desc, new_socket;
    struct sockaddr_in server, client;
    char message[MAX_MSG_LENGTH];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket\n");
        return 1;
    }

    printf("Socket created\n");

    // Configure server
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(SERVER_PORT);

    // Bind socket to address and port
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Bind failed\n");
        return 1;
    }

    printf("Bind successful\n");

    // Listen for incoming connections
    listen(socket_desc, 1);

    printf("Waiting for incoming connections...\n");

    // Accept incoming connection
    int client_size = sizeof(struct sockaddr_in);
    new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&client_size);
    if (new_socket < 0) {
        printf("Accept failed\n");
        return 1;
    }

    printf("Connection accepted\n");

    // Receive messages from client and send response
    while (1) {
        memset(message, 0, sizeof(message));
        if (recv(new_socket, message, MAX_MSG_LENGTH, 0) < 0) {
            printf("Receive failed\n");
            return 1;
        }

        printf("Message received: %s\n", message);

        if (strcmp(message, "exit") == 0) {
            printf("Client has disconnected\n");
            break;
        }

        strcat(message, " received");
        if (send(new_socket, message, strlen(message), 0) < 0) {
            printf("Send failed\n");
            return 1;
        }

        printf("Response sent: %s\n", message);
    }

    // Close sockets
    close(new_socket);
    close(socket_desc);

    return 0;
}