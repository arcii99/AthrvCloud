//FormAI DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535 // Maximum number of ports to scan
#define TIMEOUT 5 // Connection timeout in seconds

int main(int argc, char *argv[]) {
    int sock, port, result;
    struct sockaddr_in server;
    char *host;
    
    // Check for command line arguments
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }
    
    host = argv[1];
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    
    // Initialize server socket structure
    server.sin_addr.s_addr = inet_addr(host);
    server.sin_family = AF_INET;
    
    // Loop through specified ports
    for (port = 1; port <= MAX_PORTS; port++) {
        server.sin_port = htons(port);
        
        // Connect to port
        result = connect(sock, (struct sockaddr *)&server, sizeof(server));
        
        // Check if connection successful
        if (result == 0) {
            printf("Port %d open\n", port);
        }
        
        // Close the socket
        close(sock);
        
        // Create a new socket for next port
        sock = socket(AF_INET, SOCK_STREAM, 0);
        
        // Set socket timeout
        struct timeval timeout;
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;
        setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
        setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
    }
    
    return 0;
}