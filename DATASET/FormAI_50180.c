//FormAI DATASET v1.0 Category: Networking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    // create a socket to listen for incoming connections
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket creation failed");
        return 1;
    }

    // fill in the server address details
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9000);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to the server address and start listening
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        perror("bind failed");
        return 1;
    }
    if (listen(server_socket, 5) == -1) {
        perror("listen failed");
        return 1;
    }

    printf("Server started...\n");

    while (1) {
        // accept incoming connections
        struct sockaddr_in client_address;
        int client_socket = accept(server_socket, (struct sockaddr*) &client_address, sizeof(client_address));
        if (client_socket == -1) {
            perror("accept failed");
            continue;
        }

        printf("New client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // read client message
        char buffer[1024] = {0};
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received == -1) {
            perror("recv failed");
            continue;
        }
        else if (bytes_received == 0) {
            printf("Client disconnected\n");
            continue;
        }

        printf("Received message from client: %s\n", buffer);

        // process the message
        if (strcmp(buffer, "hello") == 0) {
            // send response to client
            char response[] = "Hello there!";
            send(client_socket, response, sizeof(response), 0);
        } else {
            // send error message to client
            char response[] = "Invalid command";
            send(client_socket, response, sizeof(response), 0);
        }

        // close client socket
        close(client_socket);
    }

    // close server socket
    close(server_socket);

    return 0;
}