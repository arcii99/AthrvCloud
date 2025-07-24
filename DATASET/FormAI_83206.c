//FormAI DATASET v1.0 Category: Port Scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_PORT 65535
#define BUFFER_SIZE 1024

bool check_port(char *ip_address, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        return false;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip_address);
    server.sin_port = htons(port);

    int ret = connect(sock, (struct sockaddr *)&server, sizeof(server));
    close(sock);

    return (ret == 0);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./portscanner <ip_address>\n");
        return 1;
    }

    char *ip_address = argv[1];

    for (int port = 1; port <= MAX_PORT; port++) {
        if (check_port(ip_address, port)) {
            printf("Port %d is open.\n", port);
        }
    }

    return 0;
}