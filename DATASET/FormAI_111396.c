//FormAI DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT 65535

void scan_port(int port, const char* ip_addr) {
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        perror("socket() error");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_addr);
    server_addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) != -1) {
        printf("[+] Port %d is open.\n", port);
        close(sock);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s IP_ADDRESS\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* ip_addr = argv[1];
    bool found_open_ports = false;

    printf("Scanning ports for IP Address: %s\n", ip_addr);

    for (int i = 1; i <= MAX_PORT; i++) {
        scan_port(i, ip_addr);
    }

    if (!found_open_ports) {
        printf("No open ports on %s were found.\n", ip_addr);
    }

    return EXIT_SUCCESS;
}