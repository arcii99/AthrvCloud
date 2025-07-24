//FormAI DATASET v1.0 Category: Chat server ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sockfd, client_sock, valread;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = {0};
    char *message = "Hello from server!";

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Creating server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    puts("Waiting for connections...");
    socklen_t client_size = sizeof(client_addr);

    // Accept incoming connections and handle them
    while ((client_sock = accept(sockfd, (struct sockaddr *)&client_addr, &client_size))) {
        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Send a welcome message to the client
        send(client_sock, message, strlen(message), 0);

        // Receive messages from the client
        while ((valread = read(client_sock, buffer, 1024))) {
            printf("%s:%d says: %s\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);
            
            // Quit when client sends 'quit' message
            if (strcmp(buffer, "quit") == 0) {
                close(client_sock);
                exit(0);
            }
        }
    }

    return 0;
}