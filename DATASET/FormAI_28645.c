//FormAI DATASET v1.0 Category: Port Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
 
#define MAX_PORT 65535
#define TIMEOUT 5
 
void scan_port(char*, int);
 
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP>\n", argv[0]);
        exit(1);
    }
    char* ip = argv[1];
    for (int port = 1; port <= MAX_PORT; port++) {
        scan_port(ip, port);
    }
    printf("Port scanning complete!\n");
    return 0;
}
 
void scan_port(char* ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);
    bool closed = false;
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        closed = true;
    }
    if (!closed) {
        printf("Port %d open\n", port);
    }
    close(sock);
}