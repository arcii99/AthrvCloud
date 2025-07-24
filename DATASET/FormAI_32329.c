//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8888

int main(int argc, char const *argv[]) {
    int sock = 0, val_read;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char message[1024] = "Hello from client!";

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return -1;
    }

    // Connecting to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        return -1;
    }

    // Sending message to server
    send(sock, message, strlen(message), 0);
    printf("Message sent to server: %s\n", message);

    // Receiving message from server
    val_read = read(sock, buffer, 1024);
    printf("Message received from server: %s\n", buffer);

    return 0;
}