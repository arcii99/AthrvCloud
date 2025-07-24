//FormAI DATASET v1.0 Category: Port Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <host> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);

    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    for (int port = start_port; port <= end_port; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("socket() failed");
            continue;
        }

        target.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d is open\n", port);
        }

        close(sock);
    }

    printf("Port scanning complete\n");

    return 0;
}