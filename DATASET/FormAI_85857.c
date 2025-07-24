//FormAI DATASET v1.0 Category: Port Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>

#define MAX_PORT 65535
#define BUFFER_SIZE 1024

void scan_ports(const char* target_addr) {
    int sockfd, ret;
    struct sockaddr_in target;
    char buffer[BUFFER_SIZE];
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up target address
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = 0;

    // Convert IP address to network byte order
    ret = inet_aton(target_addr, &target.sin_addr);
    if (ret == 0) {
        perror("inet_aton");
        exit(EXIT_FAILURE);
    }

    printf("Scanning ports on %s...\n", target_addr);

    // Iterate over all possible ports
    for (int port = 1; port <= MAX_PORT; port++) {
        // Set up target port
        target.sin_port = htons(port);

        // Attempt to connect to port
        ret = connect(sockfd, (struct sockaddr *)&target, sizeof(target));
        if (ret == 0) {
            printf("Port %d is open!\n", port);
        }
    }

    // Close socket
    close(sockfd);

    printf("Port scan complete.\n");
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [target IP address]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* target_addr = argv[1];
    scan_ports(target_addr);
    return 0;
}