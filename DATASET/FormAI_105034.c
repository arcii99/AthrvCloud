//FormAI DATASET v1.0 Category: Client Server Application ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

    // Step 1: Create the socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Step 2: Bind the socket to a specific port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Step 3: Listen for incoming connections
    if (listen(server_fd, 10) == -1) {
        perror("Failed to listen");
        exit(EXIT_FAILURE);
    }

    // Step 4: Accept incoming connections and communicate with the client
    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));
    socklen_t sock_len = sizeof(client_addr);

    int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &sock_len);
    if (client_fd == -1) {
        perror("Failed to accept");
        exit(EXIT_FAILURE);
    }

    // Establish bi-directional communication with the client
    char buffer[1024];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int n_read = read(client_fd, buffer, sizeof(buffer));
        if (n_read == -1) {
            perror("Failed to read from client");
            exit(EXIT_FAILURE);
        } else if (n_read == 0) {
            break;
        } else {
            printf("Received message from client: %s", buffer);
        }

        // Send a response back to the client
        char* response = "Hello client, I received your message!";
        int n_sent = write(client_fd, response, strlen(response));
        if (n_sent == -1) {
            perror("Failed to send response to client");
            exit(EXIT_FAILURE);
        }
    }

    // Step 5: Close the sockets
    close(client_fd);
    close(server_fd);

    return 0;
}