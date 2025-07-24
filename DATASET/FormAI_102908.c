//FormAI DATASET v1.0 Category: Client Server Application ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>

#define PORT     8080
#define MAXLINE  1024

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAXLINE];
    char *hello = "Hello from server";
    socklen_t len = sizeof(cliaddr);

    // Creating socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(server_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) == -1 ) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    new_socket = accept(server_fd, (struct sockaddr *)&cliaddr, &len);
    if (new_socket == -1) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Send greeting message to client
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent to client.\n");

    while (1) {
        valread = read(new_socket, buffer, MAXLINE);

        if (valread > 0) {
            printf("Message received from client: %s\n", buffer);
            memset(buffer, 0, MAXLINE);
            // send message back to client
            char *reply = "Message received";
            send(new_socket, reply, strlen(reply), 0);
        }
    }

    // Close the socket
    close(server_fd);
    return 0;
}