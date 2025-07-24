//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 1337
#define MSG_SIZE 100

int main()
{
    int fd, client_fd, n;
    struct sockaddr_in server_address, client_address;
    char buffer[MSG_SIZE];
    socklen_t len = sizeof(struct sockaddr_in);

    // Create socket file descriptor
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed.");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed.");
        exit(EXIT_FAILURE);
    }

    // Listen for client connections
    if (listen(fd, 5) < 0) {
        perror("listen failed.");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d\n", PORT);

    // Accept incoming client connection
    if ((client_fd = accept(fd, (struct sockaddr *)&client_address, &len)) < 0) {
        perror("accept failed.");
        exit(EXIT_FAILURE);
    }

    inet_ntop(AF_INET, &(client_address.sin_addr), buffer, INET_ADDRSTRLEN);
    printf("New incoming connection from %s:%d\n", buffer, ntohs(client_address.sin_port));

    // Receive message from client
    while((n = recv(client_fd, buffer, MSG_SIZE, 0)) > 0) {
        printf("Received message: %s\n", buffer);

        // Echo message back to client
        if(send(client_fd, buffer, strlen(buffer), 0) < 0) {
            perror("send failed.");
            exit(EXIT_FAILURE);
        }

        memset(buffer, 0, MSG_SIZE);
    }

    close(client_fd);
    close(fd);
    return 0;
}