//FormAI DATASET v1.0 Category: Port Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define START_PORT 1
#define END_PORT 65535

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *host = argv[1];
    struct sockaddr_in address;

    // Resolve DNS for the host
    if (inet_pton(AF_INET, host, &address.sin_addr) != 1) {
        printf("Failed to resolve host: %s\n", host);
        exit(EXIT_FAILURE);
    }

    printf("Scanning ports on host: %s\n", host);

    // Loop through all the possible ports and test if they are open
    for (int port = START_PORT; port <= END_PORT; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);

        if (sock == -1) {
            printf("Failed to create socket\n");
            exit(EXIT_FAILURE);
        }

        address.sin_family = AF_INET;
        address.sin_port = htons(port);

        int result = connect(sock, (struct sockaddr *)&address, sizeof(address));

        if (result == 0) {
            printf("Port %d is open\n", port);
        }

        close(sock);
    }

    printf("Scan completed\n");

    return 0;
}