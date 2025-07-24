//FormAI DATASET v1.0 Category: Client Server Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    // Creating socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Error creating socket\n");
        return -1;
    }

    // Creating server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // Connecting to server
    if (connect(socket_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return -1;
    }

    // Sending message to server
    char message[] = "Hello, World!";
    if (send(socket_fd, message, strlen(message), 0) < 0) {
        printf("Error sending message\n");
        return -1;
    }

    // Receiving response from server
    char buffer[1024] = {0};
    if (recv(socket_fd, buffer, 1024, 0) < 0) {
        printf("Error receiving message\n");
        return -1;
    }

    // Closing socket
    close(socket_fd);

    return 0;
}