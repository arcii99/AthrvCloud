//FormAI DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return -1;
    }

    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return -1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);

    for (int port = 1; port <= 65535; port++) {
        server.sin_port = htons(port);
        if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
            printf("Port %d is closed.\n", port);
        } else {
            printf("Port %d is open.\n", port);
            close(socket_desc);
            socket_desc = socket(AF_INET, SOCK_STREAM, 0);
            if (socket_desc == -1) {
                printf("Could not create socket");
                return -1;
            }
        }
    }

    return 0;
}