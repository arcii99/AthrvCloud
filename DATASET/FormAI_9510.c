//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MESSAGE_LENGTH 256
#define SERVER_PORT 8888

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char message[MESSAGE_LENGTH] = {0};

    // Create socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost
    server_addr.sin_port = htons(SERVER_PORT);

    // Connect to server
    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send message to server
    strcpy(message, "Hello from client!");
    if(send(sock, message, strlen(message), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Receive message from server
    memset(message, 0, MESSAGE_LENGTH);
    if(read(sock, message, MESSAGE_LENGTH) < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    printf("Server response: %s\n", message);

    // Close socket
    close(sock);

    return 0;
}