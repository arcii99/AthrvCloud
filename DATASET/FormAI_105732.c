//FormAI DATASET v1.0 Category: Port Scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MIN_PORT 1
#define MAX_PORT 65535

bool isPortOpen(const char *ip, int port) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        return false;
    }

    // Set up the socket address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_aton(ip, &addr.sin_addr);

    // Try to connect to the specified port
    int result = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (result == 0) {
        // Connection was successful, so port is open
        close(sockfd);
        return true;
    } else {
        // Connection failed, so port is closed
        close(sockfd);
        return false;
    }
}

int main(int argc, char *argv[]) {
    // Make sure the user provided an IP address
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ip address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the IP address from the command line arguments
    const char *ip = argv[1];

    // Test all ports from the minimum to the maximum port
    for (int port = MIN_PORT; port <= MAX_PORT; port++) {
        if (isPortOpen(ip, port)) {
            printf("Port %d is open\n", port);
        }
    }

    return EXIT_SUCCESS;
}