//FormAI DATASET v1.0 Category: Port Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PORT_RANGE 65535
#define IP_ADDRESS "127.0.0.1"

// Global variables
int open_ports[MAX_PORT_RANGE];
int count = 0;

// Recursive function to connect to each port
void check_port(int sockfd, struct sockaddr_in address, int port) {
    int result;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    result = connect(sockfd, (struct sockaddr *)&address, sizeof(address));

    if (result != -1) {
        printf("Port %d: Open\n", port);
        open_ports[count] = port;
        count++;
    }
    close(sockfd);
}

// Main function
int main() {
    struct sockaddr_in address;
    int sockfd, i;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Failed to create socket\n");
        exit(0);
    }

    // Initialize sockaddr_in structure
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(IP_ADDRESS);

    // Scan for open ports
    for (i = 1; i <= MAX_PORT_RANGE; i++) {
        if (count >= MAX_PORT_RANGE) {
            printf("Too many open ports to display\n");
            break;
        }
        check_port(sockfd, address, i);
    }

    // Display open ports
    printf("\nOpen Ports:\n");
    for (i = 0; i < count; i++) {
        printf("Port %d\n", open_ports[i]);
    }

    return 0;
}