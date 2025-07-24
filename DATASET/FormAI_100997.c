//FormAI DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Constants
#define TIMEOUT_SEC  1
#define MAX_PORTS    65535

// Function declarations
void scan_port(const char* ip_addr, int port);
void print_usage_and_exit(void);

int main(int argc, char* argv[]) {
    // Ensure correct usage
    if (argc != 2) {
        print_usage_and_exit();
    }
    
    // Parse IP address
    const char* ip_addr = argv[1];
    struct in_addr addr;
    if (inet_pton(AF_INET, ip_addr, &addr) != 1) {
        printf("Invalid IP address: %s\n", ip_addr);
        exit(EXIT_FAILURE);
    }
    
    // Scan all ports
    for (int i = 1; i <= MAX_PORTS; ++i) {
        scan_port(ip_addr, i);
    }
    
    // All done
    printf("Scan completed successfully.\n");
    return 0;
}

void scan_port(const char* ip_addr, int port) {
    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == -1) {
        printf("Could not create socket for port %d.\n", port);
        return;
    }
    
    // Set socket timeout
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        printf("Could not set timeout for port %d.\n", port);
        close(sock);
        return;
    }
    
    // Construct address structure
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);
    addr.sin_port = htons(port);
    
    // Connect to port
    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        close(sock);
        return;
    }
    
    // Port is open
    printf("Port %d is open.\n", port);
    close(sock);
}

void print_usage_and_exit(void) {
    printf("Usage: ./portscanner ip_address\n");
    exit(EXIT_FAILURE);
}