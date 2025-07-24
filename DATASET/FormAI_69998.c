//FormAI DATASET v1.0 Category: Port Scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        exit(-1);
    }

    int sockfd;
    struct sockaddr_in target_address;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(-1);
    }

    // Set target address
    target_address.sin_family = AF_INET;
    target_address.sin_addr.s_addr = inet_addr(argv[1]);

    // Scan ports
    for (int port = 1; port <= 65535; port++) {
        int conn_status;
        target_address.sin_port = htons(port);

        // Attempt connect
        conn_status = connect(sockfd, (struct sockaddr *)&target_address, sizeof(target_address));
        if (conn_status == 0) {
            printf("Port %d open\n", port);
        }

        // Close socket
        close(sockfd);

        // Create new socket
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            printf("Error creating socket\n");
            exit(-1);
        }
    }

    return 0;
}