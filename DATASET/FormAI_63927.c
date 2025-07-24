//FormAI DATASET v1.0 Category: Socket programming ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    // Create the socket
    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    // Prepare the sockaddr_in structure
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind the socket to a specific address and port
    if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");

    // Listen for incoming connections
    listen(socket_desc, 3);

    puts("Waiting for incoming connections...");

    // Accept incoming connections
    int client_sock, c, read_size;
    struct sockaddr_in client;
    char client_message[2000];

    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t*) &c))) {
        puts("Connection accepted");

        // Receive a message from the client and send it back
        while ((read_size = recv(client_sock, client_message, 2000, 0)) > 0) {
            write(client_sock, client_message, strlen(client_message));
            memset(client_message, 0, strlen(client_message));
        }

        // Close the connection
        close(client_sock);
        puts("Client disconnected");
    }

    if (client_sock < 0) {
        perror("accept failed");
        return 1;
    }

    return 0;
}