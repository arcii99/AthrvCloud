//FormAI DATASET v1.0 Category: Port Scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAX_PORT 65535

void usage();
void scan_ports(char *target_ip);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        usage();
        return -1;
    }
  
    char *target_ip = argv[1];
    scan_ports(target_ip);
  
    return 0;
}

/* Print usage instructions */
void usage() {
    printf("Usage: ./port_scan <ip_address>\n");
}

/* Scan ports of the target IP address */
void scan_ports(char *target_ip) {
    int sock, connection_status;
    struct sockaddr_in server_addr;
  
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket\n");
        exit(0);
    }

    printf("Scanning ports on %s...\n", target_ip);
  
    for (int port = 1; port <= MAX_PORT; port++) {
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(target_ip);
        server_addr.sin_port = htons(port);

        // Connect to the server
        connection_status = connect(sock , (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (connection_status == 0) {
            printf("Port %d : Open\n", port);
        }

        // Close socket
        close(sock);
        sock = socket(AF_INET, SOCK_STREAM, 0);
    }
}