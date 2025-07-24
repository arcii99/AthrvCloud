//FormAI DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535 // Maximum number of ports to scan
#define TIMEOUT 2       // Timeout for each port in seconds

// Function to verify if a given port is open
int is_port_open(char *ip, int port) {
    int sockfd;
    struct sockaddr_in target_addr;
    fd_set fds;
    struct timeval timeout;

    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(port);
    target_addr.sin_addr.s_addr = inet_addr(ip);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set the socket to non-blocking mode
    if (fcntl(sockfd, F_SETFL, O_NONBLOCK) < 0) {
        perror("Failed to set socket to non-blocking mode");
        exit(EXIT_FAILURE);
    }

    // Attempt to connect to the port
    if (connect(sockfd, (struct sockaddr *) &target_addr, sizeof(target_addr)) < 0) {
        if (errno != EINPROGRESS) {
            close(sockfd);
            return 0;
        }
    }

    FD_ZERO(&fds);
    FD_SET(sockfd, &fds);

    // Wait for the socket to become writable or timeout
    if (select(sockfd + 1, NULL, &fds, NULL, &timeout) > 0) {
        int err;
        socklen_t len = sizeof(err);
        // Check for any errors on the socket
        if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &err, &len) == 0 && err == 0) {
            close(sockfd);
            return 1;
        }
    }
    close(sockfd);
    return 0;
}

int main(int argc, char *argv[]) {
    int opt;
    char ip[16];
    int start_port = 1;
    int end_port = MAX_PORTS;

    while ((opt = getopt(argc, argv, "i:s:e:")) != -1) {
        switch (opt) {
            case 'i':
                strncpy(ip, optarg, sizeof(ip) - 1);
                break;
            case 's':
                start_port = atoi(optarg);
                break;
            case 'e':
                end_port = atoi(optarg);
                break;
        }
    }

    printf("Scanning ports %d - %d on %s...\n", start_port, end_port, ip);

    for (int port = start_port; port <= end_port; port++) {
        if (is_port_open(ip, port)) {
            printf("Port %d is open\n", port);
        }
    }

    printf("Scan complete.\n");
    return 0;
}