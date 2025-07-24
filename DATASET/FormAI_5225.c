//FormAI DATASET v1.0 Category: Firewall ; Style: Claude Shannon
/*
 * Firewall example program by Claude Shannon
 * 
 * This program implements a firewall that blocks incoming
 * connections from specific IP addresses and ports.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // Define the blocked IP addresses and ports
    char *blocked_ips[] = {"192.168.1.1", "10.0.0.1"};
    int blocked_ports[] = {80, 443};

    // Parse command line arguments
    if (argc < 2) {
        printf("Usage: %s <ip_address> <port>\n", argv[0]);
        exit(1);
    }
    char *ip_address = argv[1];
    int port = atoi(argv[2]);

    // Check if IP address and port are blocked
    for (int i = 0; i < sizeof(blocked_ips) / sizeof(blocked_ips[0]); i++) {
        if (strcmp(ip_address, blocked_ips[i]) == 0) {
            printf("Connection from IP address %s is blocked.\n", ip_address);
            exit(0);
        }
    }
    for (int i = 0; i < sizeof(blocked_ports) / sizeof(blocked_ports[0]); i++) {
        if (port == blocked_ports[i]) {
            printf("Connection to port %d is blocked.\n", port);
            exit(0);
        }
    }

    // Connection is allowed
    printf("Connection from %s:%d is allowed.\n", ip_address, port);

    return 0;
}