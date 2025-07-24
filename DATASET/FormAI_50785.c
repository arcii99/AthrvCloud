//FormAI DATASET v1.0 Category: Socket programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5555

int main(int argc, char const *argv[]) {

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket.\n");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection error.\n");
        return 1;
    }

    char message[] = "Hello server!";
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Send failed.\n");
        return 1;
    }

    char server_reply[2000];
    memset(server_reply, 0, 2000);
    if (recv(sock, server_reply, 2000, 0) < 0) {
        printf("Receive failed.\n");
        return 1;
    }

    printf("Server reply: %s\n", server_reply);

    close(sock);
    return 0;
}