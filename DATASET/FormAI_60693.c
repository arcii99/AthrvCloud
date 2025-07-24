//FormAI DATASET v1.0 Category: Port Scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PORT 65535

int main(int argc, char *argv[]) {
    int sock, result, port;
    struct sockaddr_in target;
    char *ip_address;

    if (argc != 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ip_address = argv[1];
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_address);

    for (port = 1; port <= MAX_PORT; ++port) {
        target.sin_port = htons(port);
        sock = socket(AF_INET, SOCK_STREAM, 0);

        if (sock < 0) {
            perror("socket creation failed");
            exit(EXIT_FAILURE);
        }

        result = connect(sock, (struct sockaddr *) &target, sizeof(target));

        if (result >= 0) {
            printf("Port %d is open\n", port);
        }

        close(sock);
    }

    return 0;
}