//FormAI DATASET v1.0 Category: Socket programming ; Style: innovative
// This is a chat application using C Sockets
// The program is innovative and unique in its own way 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080

void *receiver(void *args);
void *sender(void *args);

int main(int argc, char const *argv[]) {
    int sock = 0;
    struct sockaddr_in server_addr;
    char message[1024];

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&server_addr, '0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    pthread_t tid1;
    pthread_t tid2;
    pthread_create(&tid1, NULL, &receiver, &sock);
    pthread_create(&tid2, NULL, &sender, &sock);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    close(sock);

    return 0;
}

void *receiver(void *args) {
    int sock = *(int*)args;
    char message[1024];

    while (1) {
        memset(&message, 0, sizeof(message));
        if (recv(sock, message, sizeof(message), 0) > 0) {
            printf("\nServer: %s\n", message);
        } else {
            break;
        }
    }
}

void *sender(void *args) {
    int sock = *(int*)args;
    char message[1024];

    printf("Enter message: ");

    while (fgets(message, sizeof(message), stdin) != NULL) {
        send(sock, message, strlen(message), 0);
        printf("Enter message: ");
    }

    close(sock);
    exit(0);
}