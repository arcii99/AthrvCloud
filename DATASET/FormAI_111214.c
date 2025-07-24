//FormAI DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT_RANGE 65535  // Maximum number of ports to scan
#define TIMEOUT 2  // Timeout value for connection

int main(int argc, char *argv[]) {
    
    if (argc != 2) {  // Usage message
        printf("Usage: %s <target IP address>\n", argv[0]);
        return 1;
    }
    
    char *target = argv[1];
    
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(target);
    
    int sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock_fd < 0) {  // Error checking
        perror("socket()");
        return 1;
    }
    
    int port = 1;
    
    while (port <= PORT_RANGE) {
        server_addr.sin_port = htons(port);
        int result = connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (result < 0) {  // Connection failed, port is closed
            printf("Port %d is closed\n", port);
        } else {  // Connection successful, port is open
            printf("Port %d is open\n", port);
        }
        port++;
    }
    
    close(sock_fd);
    
    return 0;
}