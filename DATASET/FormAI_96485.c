//FormAI DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    printf("Enter Host to scan: ");

    char *host;
    int ports[65535];

    scanf("%s", &host);

    printf("Scanning Host: %s\n", host);

    // Populating ports array with port numbers
    for (int i = 0; i < 65535; i++) {
        ports[i] = i + 1;
    }

    struct sockaddr_in target;

    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(host);

    for (int i = 0; i < sizeof(ports) / sizeof(int); i++) {
        target.sin_port = htons(ports[i]);

        int sock = socket(AF_INET, SOCK_STREAM, 0);

        if (connect(sock, (struct sockaddr *) &target, sizeof(target)) == 0) {
            printf("Port %d Open\n", ports[i]);
        }

        close(sock);
    }

    printf("Scan Complete\n");

    return 0;
}