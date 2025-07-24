//FormAI DATASET v1.0 Category: Client Server Application ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 9999

void serve_client(int client_soc) {
    char buffer[1024];
    char *welcome_message = "Welcome to the server!";

    send(client_soc, welcome_message, strlen(welcome_message), 0);

    int message_len;
    while((message_len = recv(client_soc, buffer, 1024, 0)) > 0) {
        buffer[message_len] = '\0';
        printf("Received message from client: %s\n", buffer);

        if(strcmp(buffer, "quit\n") == 0) {
            printf("Client disconnected.\n");
            close(client_soc);
            return;
        }

        send(client_soc, buffer, message_len, 0);
    }

    if(message_len == 0) {
        printf("Client disconnected.\n");
    } else {
        perror("Error receiving message from client");
    }
    close(client_soc);
}

int main() {
    int listen_soc;
    
    // Create socket
    if ((listen_soc = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind socket to a port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(listen_soc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_soc, 5) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    printf("Server listening on port %d...\n", SERVER_PORT);

    while(1) {
        int client_soc;
        struct sockaddr_in client_addr;
        int client_addr_len = sizeof(client_addr);

        // Accept incoming client connection
        client_soc = accept(listen_soc, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_soc < 0) {
            perror("Error accepting incoming connection");
            exit(1);
        }

        printf("Accepted incoming client connection from %s\n", inet_ntoa(client_addr.sin_addr));

        // Fork a new process to handle the incoming client connection
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            close(listen_soc);
            serve_client(client_soc);
            exit(0);
        } else if (pid < 0) {
            perror("Error forking");
            exit(1);
        } else {
            // Parent process
            close(client_soc);
        }
    }

    // Close listening socket
    close(listen_soc);

    return 0;
}