//FormAI DATASET v1.0 Category: Socket programming ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int sock_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE] = {0};
    int addr_len = sizeof(server_addr);

    // Creating socket file descriptor
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons( PORT );

    // Bind the socket with the server address
    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))<0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d\n", PORT);

    while(1) {
        // Accept incoming connection
        if ((client_fd = accept(sock_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addr_len))<0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        char *welcome_message = "Welcome to my chat server!\n";
        send(client_fd, welcome_message, strlen(welcome_message), 0);

        while(1) {
            // Read incoming message
            int message_len = read(client_fd, buffer, BUFFER_SIZE);
            if(message_len <= 0) {
                break;
            }
            buffer[message_len] = '\0';

            // Handle incoming message
            printf("Received: %s", buffer);
            char *response = strtok(buffer, "\n");
            if(strcmp(response, "bye") == 0) {
                char *bye_message = "Goodbye!\n";
                send(client_fd, bye_message, strlen(bye_message), 0);
                break;
            }
            char *outgoing_message = "Your message was received!\n";
            send(client_fd, outgoing_message, strlen(outgoing_message), 0);
            memset(buffer, 0, BUFFER_SIZE);
        }

        // Close client connection
        close(client_fd);
    }

    // Close server socket
    close(sock_fd);

    return 0;
}