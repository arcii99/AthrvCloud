//FormAI DATASET v1.0 Category: Networking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    struct sockaddr_in server_address;
    int socket_fd;

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    char message[BUFFER_SIZE];
    memset(message, 0, BUFFER_SIZE);

    while (1) {
        printf("Enter a message to send to the server: ");
        fgets(message, BUFFER_SIZE, stdin);

        if (send(socket_fd, message, strlen(message), 0) < 0) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }

        memset(message, 0, BUFFER_SIZE);  

        if (recv(socket_fd, message, BUFFER_SIZE, 0) < 0) {
            perror("recv failed");
            break;
        }

        printf("Server reply: %s\n", message);
    }

    close(socket_fd);
    return 0;
}