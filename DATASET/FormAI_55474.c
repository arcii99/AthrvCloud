//FormAI DATASET v1.0 Category: Port Scanner ; Style: safe
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAX_PORT 65535

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <target IP>\n", argv[0]);
        return 1;
    }

    char *target_ip = argv[1];
    int open_ports[MAX_PORT] = {0};

    int sock;
    struct sockaddr_in target_addr;

    // Create TCP socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Socket creation failed\n");
        return 1;
    }

    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(target_ip);

    printf("Scanning open ports...\n");

    // Loop through all possible ports
    for (int port = 1; port <= MAX_PORT; port++) {
        target_addr.sin_port = htons(port);

        // Try to connect to the port
        if (connect(sock, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
            printf("Port %d is open!\n", port);
            open_ports[port-1] = 1;
        }
    }

    // Print the list of open ports
    printf("\n\nList of open ports:\n");
    for (int port = 1; port <= MAX_PORT; port++) {
        if (open_ports[port-1] == 1) {
            printf("%d\n", port);
        }
    }

    close(sock);
    return 0;
}