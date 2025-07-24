//FormAI DATASET v1.0 Category: Socket programming ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    int opt = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    int new_sock, c, read_size;
    struct sockaddr_in client = {0};
    c = sizeof(struct sockaddr_in);

    printf("Waiting for incoming connections...\n");

    while ((new_sock = accept(sock, (struct sockaddr*)&client, (socklen_t*)&c))) {
        printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        char* message = "Hello client! This is the server speaking.\n";
        write(new_sock, message, strlen(message));

        char client_message[2000] = {0};
        while ((read_size = recv(new_sock, client_message, 2000, 0)) > 0) {
            printf("Client message: %s", client_message);
            memset(client_message, 0, sizeof(client_message));
        }

        if (read_size == 0) {
            printf("Client disconnected.\n\n");
            fflush(stdout);
        } else if (read_size == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }
    }

    if (new_sock < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    return 0;
}