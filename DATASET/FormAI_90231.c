//FormAI DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_START 1
#define PORT_END 65535

int main(int argc, char *argv[]) {
    int sock, i, port;
    struct sockaddr_in target;
    char *ip_address;
    bool port_status;

    // Check for valid arguments
    if (argc != 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        return 1;
    }

    // Get the IP address from command line argument
    ip_address = argv[1];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    // Fill in target structure
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_address);

    // Scan ports
    for (port = PORT_START; port <= PORT_END; port++) {
        target.sin_port = htons(port);

        // Try to connect to port
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d - OPEN\n", port);
            port_status = true;
        } else {
            port_status = false;
        }
    }

    // Close socket before exiting
    close(sock);

    return 0;
}