//FormAI DATASET v1.0 Category: Networking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_SIZE 1024
#define PORT_NUMBER 8080

int main() {
    int server_fd, client_fd, msg_len, addr_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_MSG_SIZE];

    // Creating the socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting sockaddr_in parameters
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT_NUMBER);

    // Binding socket to the given address and port number
    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming client connections
    if (listen(server_fd, 5) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT_NUMBER);

    addr_len = sizeof(client_addr);

    // Accepting incoming connections and handling them one by one
    while ((client_fd = accept(server_fd, (struct sockaddr *) &client_addr, (socklen_t *) &addr_len)) > 0) {
        printf("Incoming connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Receiving messages from the client
        while ((msg_len = read(client_fd, buffer, MAX_MSG_SIZE)) > 0) {
            printf("%s:%d -> %s\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);

            // Sending message back to client
            if (write(client_fd, buffer, strlen(buffer)) < 0) {
                perror("write failed");
                exit(EXIT_FAILURE);
            }
        }

        // Closing the client socket
        close(client_fd);
        printf("Connection with %s:%d closed\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    }

    if (client_fd < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Closing the server socket
    close(server_fd);

    return 0;
}