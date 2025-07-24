//FormAI DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_PORTS 65535

void print_usage(char *name) {
    printf("Usage: %s <target_ip>\n", name);
    printf("Example: %s 192.168.1.1\n", name);
}

void scan_ports(char *ip_address) {
    int sockfd, connfd;
    struct sockaddr_in target;
    bool open_ports[MAX_PORTS] = { false };
    int num_open_ports = 0;

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse the socket
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Fill in target information
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_address);

    // Scan all ports from 1 to MAX_PORTS
    for (int port = 1; port <= MAX_PORTS; port++) {
        target.sin_port = htons(port);

        // Connect to the port
        if (connect(sockfd, (struct sockaddr *)&target, sizeof(target)) == 0) {
            open_ports[port] = true;
            num_open_ports++;
        }

        // Close the connection
        close(sockfd);
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        // Set socket options to reuse the socket
        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
            perror("Setsockopt failed");
            exit(EXIT_FAILURE);
        }
    }

    // Print the open port numbers
    printf("Open ports on %s:\n", ip_address);
    for (int port = 1; port <= MAX_PORTS; port++) {
        if (open_ports[port]) {
            printf("%d\n", port);
        }
    }

    printf("Scan complete. Found %d open port(s).\n", num_open_ports);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];

    printf("Scanning ports on %s...\n", ip_address);
    scan_ports(ip_address);

    return 0;
}