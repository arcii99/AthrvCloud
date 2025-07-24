//FormAI DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_START 1
#define PORT_END 65535

void scan_port(char *ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0) {
        printf("[+] Port %d is open\n", port);
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    char *ip;
    int i;

    if (argc < 2) {
        printf("[!] Error: no IP address specified\n");
        return -1;
    }

    ip = argv[1];

    printf("[+] Starting port scan on %s\n", ip);

    for (i = PORT_START; i <= PORT_END; i++) {
        scan_port(ip, i);
    }

    printf("[+] Scan complete\n");

    return 0;
}