//FormAI DATASET v1.0 Category: Socket programming ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

void *recv_msg(void *arg);

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(8080);

    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Connected to server...\n");

    pthread_t thread;
    pthread_create(&thread, NULL, recv_msg, (void *)&sock);

    char msg[256];
    while (1) {
        fgets(msg, sizeof(msg), stdin);
        send(sock, msg, strlen(msg)+1, 0);
    }

    close(sock);
    return 0;
}

void *recv_msg(void *arg) {
    int sock = *(int *)arg;
    char msg[256];

    while (1) {
        if (recv(sock, msg, sizeof(msg), 0) <= 0) {
            printf("Disconnected from server...\n");
            exit(0);
        }
        printf("Server: %s", msg);
    }
}