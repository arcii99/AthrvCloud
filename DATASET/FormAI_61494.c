//FormAI DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PORT 65535

bool is_port_open(char *ip, int port) {
    struct sockaddr_in server;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        return false;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) == 0) {
        close(sockfd);
        return true;
    }

    close(sockfd);
    return false;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        return -1;
    }

    char *ip = argv[1];

    for (int port = 1; port <= MAX_PORT; port++) {
        if (is_port_open(ip, port)) {
            printf("%-5d  open\n", port);
        }
    }

    return 0;
}