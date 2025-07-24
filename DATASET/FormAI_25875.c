//FormAI DATASET v1.0 Category: Port Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT_NUM 65535

int main(int argc, char *argv[]) {
    int sock, port, start_port, end_port, err;
    struct sockaddr_in addr;
    char ip[16];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <host> <start_port> <end_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strncpy(ip, argv[1], 16);
    start_port = (argc > 2) ? atoi(argv[2]) : 1;
    end_port = (argc > 3) ? atoi(argv[3]) : PORT_NUM;

    if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);

    for (port = start_port; port <= end_port; port++) {
        addr.sin_port = htons(port);
        err = connect(sock, (struct sockaddr *) &addr, sizeof(addr));
        if (err != -1) {
            printf("Port %d is open\n", port);
        } else {
            if (errno != ECONNREFUSED) {
                fprintf(stderr, "Error connecting to port %d: %s\n",
                        port, strerror(errno));
                exit(EXIT_FAILURE);
            }
        }
    }

    close(sock);
    exit(EXIT_SUCCESS);
}