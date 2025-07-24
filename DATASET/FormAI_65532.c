//FormAI DATASET v1.0 Category: Port Scanner ; Style: ephemeral
/* Ephemeral Port Scanner */
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXPORT 65535

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <target_ip>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd;
    struct sockaddr_in target_addr;

    // Fill in target address information
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(argv[1]);

    for (int port = 1; port <= MAXPORT; port++) {
        // Create a socket for connecting to target
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd == -1) {
            printf("Error: Failed to create socket.\n");
            return EXIT_FAILURE;
        }

        // Set socket options
        int option = 1;
        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) == -1) {
            printf("Error: Failed to set socket option.\n");
            return EXIT_FAILURE;
        }

        // Fill in ephemeral source address information
        struct sockaddr_in src_addr;
        src_addr.sin_family = AF_INET;
        src_addr.sin_addr.s_addr = INADDR_ANY;
        src_addr.sin_port = htons(0);

        // Bind socket to ephemeral port
        if (bind(sockfd, (struct sockaddr*)&src_addr, sizeof(src_addr)) == -1) {
            printf("Error: Failed to bind socket.\n");
            return EXIT_FAILURE;
        }

        // Fill in target port information
        target_addr.sin_port = htons(port);

        // Connect to target using the ephemeral port
        if (connect(sockfd, (struct sockaddr*)&target_addr, sizeof(target_addr)) == -1) {
            // Port is closed
            close(sockfd);
        }
        else {
            // Port is open
            printf("Port %d is open.\n", port);
            close(sockfd);
        }
    }

    printf("Scan complete.\n");
    return EXIT_SUCCESS;
}