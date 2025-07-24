//FormAI DATASET v1.0 Category: Port Scanner ; Style: systematic
// C Port Scanner Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>

// Prototypes
int scan_port(const char *ip_address, int port);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Invalid arguments. Usage: %s <IP Address> <Port>\n", argv[0]);
        return 0;
    }

    const char *ip_address = argv[1];
    int port = atoi(argv[2]);

    if (scan_port(ip_address, port)) {
        printf("Port %d is open on %s\n", port, ip_address);
    } else {
        printf("Port %d is closed on %s\n", port, ip_address);
    }

    return 0;
}

int scan_port(const char *ip_address, int port) {
    struct sockaddr_in server;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_addr.s_addr = inet_addr(ip_address);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Try to connect to the specified port
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
        close(sock);
        return 1; // Port is open
    }

    close(sock);
    return 0; // Port is closed
}