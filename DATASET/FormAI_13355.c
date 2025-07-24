//FormAI DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535
#define TIMEOUT 2

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <target-ip>\n", argv[0]);
        return 1;
    }
    char *target_ip = argv[1];
    struct in_addr ip;
    if (inet_aton(target_ip, &ip) == 0) {
        printf("Invalid target IP address\n");
        return 1;
    }
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        return 1;
    }
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &timeout, sizeof(timeout)) == -1) {
        printf("Error setting socket options\n");
        return 1;
    }
    struct sockaddr_in target_addr;
    memset((char *) &target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = ip.s_addr;
    int port;
    int open_ports = 0;
    for (port = 1; port <= MAX_PORTS; port++) {
        target_addr.sin_port = htons(port);
        if (connect(sockfd, (struct sockaddr *) &target_addr, sizeof(target_addr)) == 0) {
            printf("Port %d is open\n", port);
            open_ports++;
        }
    }
    if (open_ports == 0) {
        printf("No open ports found\n");
    }
    close(sockfd);
    return 0;
}