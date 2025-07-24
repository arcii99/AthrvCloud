//FormAI DATASET v1.0 Category: Port Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535

int main(int argc, char *argv[]) {

    int sockfd, scan_port;
    struct sockaddr_in target;
    
    if (argc != 2) {
        printf("Usage: %s <IP>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);
    
    printf("Starting port scan on %s...\n\n", argv[1]);
    
    for (scan_port = 1; scan_port <= MAX_PORTS; scan_port++) {
        
        target.sin_port = htons(scan_port);
        
        if (connect(sockfd, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("[+] Port %d open.\n", scan_port);
        }
        
    }
    
    printf("\nScan complete.\n");
    
    return EXIT_SUCCESS;
    
}