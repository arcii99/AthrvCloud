//FormAI DATASET v1.0 Category: Networking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_ADDR "127.0.0.1"

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return -1;
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return -1;
    }

    printf("Connected to server\n");

    char message[] = "Hello from client";
    if (send(sock, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return -1;
    }

    printf("Message sent to server\n");

    char server_reply[2000];
    if (recv(sock, server_reply, 2000, 0) < 0) {
        puts("Receive failed");
        return -1;
    }

    printf("Server reply: %s\n", server_reply);

    close(sock);
    return 0;
}