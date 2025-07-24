//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Could not bind socket");
        return 1;
    }

    printf("Listening on port %d\n", PORT);
    listen(sock, 3);

    int client_sock;
    struct sockaddr_in client;
    socklen_t client_size = sizeof(client);
    char client_message[2000];

    while((client_sock = accept(sock, (struct sockaddr*)&client, &client_size))) {
        printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        int read_size;
        char* message = "Hello, Brave World!\n";

        write(client_sock, message, strlen(message) + 1);
    }

    if (client_sock == -1) {
        printf("Could not accept connection");
        return 1;
    }

    close(sock);
    return 0;
}