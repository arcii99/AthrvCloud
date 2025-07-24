//FormAI DATASET v1.0 Category: Client Server Application ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000

int main(int argc, char const *argv[]) {

    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the port and listen for connections
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is up and listening on port %d...\n", PORT);

    // Accept incoming connections and handle the requests
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: [%s:%d]\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Read the message from the client
        memset(buffer, 0, sizeof(buffer));
        if (read(new_socket, buffer, 1024) < 0) {
            perror("read failed");
            exit(EXIT_FAILURE);
        }

        printf("Received message from client: %s\n", buffer);

        // Send a response back to the client
        const char *message = "Server received your message!";
        send(new_socket, message, strlen(message), 0);
        printf("Response sent to client\n");

        // Close the connection
        close(new_socket);
    }

    return 0;
}