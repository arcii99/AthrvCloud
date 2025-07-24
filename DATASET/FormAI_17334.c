//FormAI DATASET v1.0 Category: Port Scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PORT 65535 
#define TIMEOUT 1

int main(int argc, char **argv) {
    if (argc != 2) {  // if no argument is given
        printf("Please provide IP address to scan.\n");
        exit(1);
    }

    char *ip_addr = argv[1];

    printf("Starting port scan on %s...\n", ip_addr);

    int sockfd; // socket file descriptor
    struct sockaddr_in target_addr = {0};

    target_addr.sin_family = AF_INET;  // set address family to IPv4
    target_addr.sin_addr.s_addr = inet_addr(ip_addr);

    for (int port = 1; port <= MAX_PORT; port++) { // loop through all possible port range
        sockfd = socket(AF_INET, SOCK_STREAM, 0);  // create socket
        if (sockfd < 0) {
            perror("error in creating socket");
            exit(1);
        }
        target_addr.sin_port = htons(port); // set target port

        if (connect(sockfd, (struct sockaddr*) &target_addr, sizeof(target_addr)) == 0) { // if port is open
            printf("Port %d is open!\n", port);
        }
        close(sockfd); // close connection
    }

    printf("Port scan complete!\n");

    return 0;
}