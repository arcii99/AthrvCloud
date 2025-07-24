//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        return 1;
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);

    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    printf("Connected to server %s:%d\n\n", server_ip, server_port);

    char message[MAX_SIZE];
    char response[MAX_SIZE];

    while (1) {
        printf("Enter a HTTP request (or 'exit' to quit):\n");
        fgets(message, MAX_SIZE, stdin);

        if (strcmp(message, "exit\n") == 0) {
            break;
        }

        write(sock, message, strlen(message));

        read(sock, response, MAX_SIZE);

        printf("Response from server:\n%s\n", response);
    }

    close(sock);

    return 0;
}