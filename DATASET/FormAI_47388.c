//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(int argc, char const *argv[]) {
    int socket_fd;
    struct sockaddr_in server_addr;
    char message[BUFFER_SIZE], server_reply[BUFFER_SIZE];

    // create a socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }

    memset(&server_addr, '0', sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // convert IP address to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported\n");
        return -1;
    }

    // connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed\n");
        return -1;
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter message to send: ");
        fgets(message, BUFFER_SIZE, stdin);

        // send message
        if (send(socket_fd, message, strlen(message), 0) < 0) {
            printf("Send failed\n");
            return -1;
        }

        // receive reply
        if (recv(socket_fd, server_reply, BUFFER_SIZE, 0) < 0) {
            printf("Receive failed\n");
            return -1;
        }

        printf("Server reply: %s", server_reply);
    }

    close(socket_fd);
    return 0;
}