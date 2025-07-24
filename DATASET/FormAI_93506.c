//FormAI DATASET v1.0 Category: Port Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAXPORT 65535 // Maximum number of ports to scan

// Connects to the given TCP port on the given IP address and returns 0 for success, or an error code.
int connect_to_port(const char *ip_address, int port) {
    // Create a socket descriptor.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() failed");
        return -1;
    }

    // Fill in the server's address information.
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
        puts("Invalid IP address");
        return -2;
    }

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        return -3;
    }

    // Close the socket.
    close(sockfd);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        puts("Usage: portscanner IP_ADDRESS");
        return 1;
    }

    printf("Scanning ports on %s...\n", argv[1]);

    // Scan all possible ports up to MAXPORT.
    for (int port = 1; port <= MAXPORT; port++) {
        if (connect_to_port(argv[1], port) == 0) {
            printf("Port %d is open\n", port);
        }
    }

    puts("Done.");
    return 0;
}