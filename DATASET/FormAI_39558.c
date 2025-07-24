//FormAI DATASET v1.0 Category: Port Scanner ; Style: secure
/* A secure C Port Scanner example program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

void scan_port(const char* host, int port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(host);
    addr.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: failed to open socket.");
        exit(1);
    }

    struct timeval timeout;
    timeout.tv_sec = 3; // Set a timeout of 3 seconds to avoid long waiting times
    timeout.tv_usec = 0;

    // Set the socket options to allow the port scan to occur
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

    if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == 0) {
        printf("Port %d is open on host %s\n", port, host);
    }
    close(sockfd);
}

int main(int argc, char* argv[]) {
    if (argc < 2) { // Check that a hostname is entered
        printf("Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    char* hostname = argv[1];
    struct hostent* host_info = gethostbyname(hostname);

    if (host_info == NULL) {
        printf("Invalid hostname entered.\n");
        exit(1);
    }

    printf("Scanning ports for host %s...\n", hostname);
    for (int port = 1; port < 65536; port++) { // Iterate over all possible port numbers
        scan_port(hostname, port);
    }

    printf("Port scan complete.\n");
    return 0;
}