//FormAI DATASET v1.0 Category: Port Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define START_PORT 1
#define END_PORT 65535
#define TIMEOUT_SEC 2

void scan_ports(const char* ip_address, int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = 0;

    if (sock == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip_address);

    for (int port = start_port; port <= end_port; port++) {
        server_address.sin_port = htons(port);

        if (connect(sock, (struct sockaddr*) &server_address, sizeof(server_address)) >= 0) {
            printf("Port %d is open\n", port);
            close(sock);
            sock = socket(AF_INET, SOCK_STREAM, 0);
            setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
            continue;
        }
    }

    close(sock);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <ip address>\n", argv[0]);
        exit(1);
    }

    char* ip_address = argv[1];
    printf("Scanning ports for %s...\n", ip_address);
    scan_ports(ip_address, START_PORT, END_PORT);

    return 0;
}