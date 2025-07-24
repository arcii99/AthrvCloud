//FormAI DATASET v1.0 Category: Port Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_PORT 65535
#define TIMEOUT_SEC 1

/**
 * Check if a given port is open or not
 */
bool is_port_open(char *ip_address, int port) {
    // Create a socket for the connection
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return false;
    }

    // Set socket timeout
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt");
        close(sock);
        return false;
    }

    // Define server address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        close(sock);
        return false;
    }

    // Attempt to connect to the server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0) {
        printf("%d\topen\n", port);
        close(sock);
        return true;
    } else {
        close(sock);
        return false;
    }
}

int main(int argc, char *argv[]) {
    // Get IP address from command line arguments
    if (argc != 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        return 0;
    }
    char *ip_address = argv[1];

    // Scan all ports and check if they are open or not
    printf("Port\tStatus\n");
    for (int port = 0; port <= MAX_PORT; port++) {
        is_port_open(ip_address, port);
    }

    return 0;
}