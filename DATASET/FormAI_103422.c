//FormAI DATASET v1.0 Category: Port Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORT 65535

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ip_address>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int sockfd, connfd;
    struct sockaddr_in address;
    int start_port = 1;
    int end_port = MAX_PORT;

    // Scan open ports on the target IP address
    for (int port = start_port; port <= end_port; port++) {

        // Create a socket for the port scan
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        // Set the socket options
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = inet_addr(ip_address);
        address.sin_port = htons(port);

        // Connect to the port
        if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) == 0) {
            printf("Port %d open on %s\n", port, ip_address);
        }

        // Close the socket
        close(sockfd);
    }

    return 0;
}