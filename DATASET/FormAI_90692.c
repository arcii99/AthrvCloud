//FormAI DATASET v1.0 Category: Port Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define NUM_PORTS 100 //number of ports to scan

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int ports[NUM_PORTS];
    int i, j, scan_socket;

    // Create a TCP socket for each port to scan
    for (i = 0; i < NUM_PORTS; i++) {
        ports[i] = i + 1;
    }

    // Try to connect to each port
    for (i = 0; i < NUM_PORTS; i++) {
        // Create a socket for this port
        scan_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (scan_socket == -1) {
            printf("Error: socket() failed\n");
            return 2;
    }

        // Configure the socket
        struct sockaddr_in address;
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = inet_addr(ip);
        address.sin_port = htons(ports[i]);

        // Try to connect to the port
        int result = connect(scan_socket, (struct sockaddr *) &address, sizeof(address));
        if (result == 0) {
            printf("Port %d is open\n", ports[i]);
        }
        close(scan_socket);
    }

    // Finish scanning
    printf("Scan complete for %s\n", ip);
    return 0;
}