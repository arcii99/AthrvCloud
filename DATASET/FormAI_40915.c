//FormAI DATASET v1.0 Category: Port Scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_PORT 65355

void scan_port(struct sockaddr_in addr, int port) {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    addr.sin_port = htons(port);

    if (connect(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d is open.\n", port);
    }

    close(sock_fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s IP address\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;

    if (inet_pton(AF_INET, ip_address, &addr.sin_addr) == 0) {
        printf("Invalid IP address.\n");
        exit(EXIT_FAILURE);
    }

    printf("Starting port scan on %s...\n", ip_address);

    for (int port=0; port <= MAX_PORT; port++) {
        scan_port(addr, port);
    }

    printf("Port scan of %s is complete.\n", ip_address);
    return 0;
}