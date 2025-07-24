//FormAI DATASET v1.0 Category: Client Server Application ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main(int argc, char const *argv[]) {

    int sockfd, new_sockfd, len;
    struct sockaddr_in server, client;
    char buffer[1024] = {0};

    // Create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Assign IP, port and type
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind socket
    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Allow maximum of 3 pending connections for the listening socket
    if (listen(sockfd, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", PORT);

    len = sizeof(client);

    // Accept incoming connection from client
    if ((new_sockfd = accept(sockfd, (struct sockaddr *)&client, (socklen_t *)&len)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Connection established with client\n");

    while (1) {

        // Receive message from client
        memset(buffer, 0, sizeof(buffer));
        if (read(new_sockfd, buffer, sizeof(buffer)) < 0) {
            perror("Read failed");
            exit(EXIT_FAILURE);
        }

        printf("Client: %s", buffer);

        // Send message to client
        memset(buffer, 0, sizeof(buffer));
        printf("Server: ");
        fgets(buffer, sizeof(buffer), stdin);
        if (write(new_sockfd, buffer, strlen(buffer)) < 0) {
            perror("Write failed");
            exit(EXIT_FAILURE);
        }

    }

    return 0;
}