//FormAI DATASET v1.0 Category: Port Scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

void scanPort(const char *host, int port) {
    struct sockaddr_in address;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, host, &address.sin_addr);
    int result = connect(sock, (struct sockaddr *)&address, sizeof(address));
    if (result == 0) {
        printf("%s:%d is open\n", host, port);
    }
    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *host = argv[1];
    struct hostent *hostinfo = gethostbyname(host);
    if (hostinfo == NULL) {
        fprintf(stderr, "Unknown host %s\n", host);
        exit(EXIT_FAILURE);
    }

    printf("Scanning ports for %s...\n", host);
    for (int port = 1; port <= 65535; port++) {
        scanPort(host, port);
    }
    printf("Scan complete.\n");

    return 0;
}