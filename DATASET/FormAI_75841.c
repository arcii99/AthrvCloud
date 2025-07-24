//FormAI DATASET v1.0 Category: Port Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT 65535
#define TIMEOUT_SEC 1

bool isPortOpen(const char *ipaddr, int port) {
    struct sockaddr_in addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ipaddr);
    addr.sin_port = htons(port);
    
    // Set connection timeout
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
    
    int result = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    close(sock);
    
    if (result < 0) {
        return false;
    }
    return true;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <ip address>\n", argv[0]);
        return 1;
    }

    const char *ipaddr = argv[1];
    printf("Scanning for open ports on %s...\n", ipaddr);

    for (int port = 1; port <= MAX_PORT; port++) {
        if (isPortOpen(ipaddr, port)) {
            printf("Port %d is open!\n", port);
        }
    }
    
    printf("Scan complete.\n");

    return 0;
}