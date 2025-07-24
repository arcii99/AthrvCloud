//FormAI DATASET v1.0 Category: Port Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_PORT 65535

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: portscanner [ip_address]\n");
        return 1;
    }

    char* ip_address = argv[1];
    struct in_addr ip;
    if (inet_aton(ip_address, &ip) == 0) {
        printf("Invalid IP address\n");
        return 1;
    }

    printf("Scanning ports on %s...\n", ip_address);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr = ip;

    for (int port = 1; port <= MAX_PORT; ++port) {
        server_address.sin_port = htons(port);

        if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) == 0) {
            printf("Port %d is open\n", port);
        }
    }

    close(sock);
    printf("Scan complete\n");

    return 0;
}