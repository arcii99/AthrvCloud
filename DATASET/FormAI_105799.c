//FormAI DATASET v1.0 Category: Socket programming ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sock_fd, conn_fd, len;
    struct sockaddr_in serv_address, client_address;
    char buffer[1024];
    char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting up the address
    memset(&serv_address, 0, sizeof(serv_address));

    serv_address.sin_family = AF_INET;
    serv_address.sin_addr.s_addr = INADDR_ANY;
    serv_address.sin_port = htons(8888);

    // Binding socket to address
    if (bind(sock_fd, (struct sockaddr *) &serv_address, sizeof(serv_address)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(sock_fd, 10) == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", ntohs(serv_address.sin_port));

    while (1) {
        // Accepting incoming connection
        len = sizeof(client_address);
        conn_fd = accept(sock_fd, (struct sockaddr *) &client_address, &len);

        if (conn_fd == -1) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Send message to client
        if (send(conn_fd, hello, strlen(hello), 0) == -1) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }

        // Receive message from client
        if (recv(conn_fd, buffer, 1024, 0) == -1) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }

        printf("Message received from client: %s\n", buffer);

        // Closing connection
        close(conn_fd);
        printf("Connection closed\n");
    }

    return 0;
}