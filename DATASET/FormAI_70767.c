//FormAI DATASET v1.0 Category: Port Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void scan_port(char* ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in target;
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip);
    target.sin_port = htons(port);

    if (connect(sock, (struct sockaddr*)&target, sizeof(target)) == 0) {
        printf("[*] Port %d open\n", port);
    } else {
        printf("[*] Port %d closed\n", port);
    }

    close(sock);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <ip>\n", argv[0]);
        exit(EXIT_SUCCESS);
    }
    
    char* ip = argv[1];
    printf("[*] Scanning %s...\n", ip);

    for (int port = 1; port <= 65535; port++) {
        scan_port(ip, port);
    }

    printf("[*] Finished scanning %s.\n", ip);
    return EXIT_SUCCESS;
}