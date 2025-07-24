//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT 65535

int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return -1;
    }

    struct in_addr ip_addr;

    if(!inet_aton(argv[1], &ip_addr)) {
        printf("Invalid IP address: %s\n", argv[1]);
        return -1;
    }

    printf("Scanning IP address %s...\n", argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0) {
        perror("Unable to create socket");
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = ip_addr.s_addr;

    int port;
    for(port = 1; port <= MAX_PORT; port++) {
        server_addr.sin_port = htons(port);
        if(connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) >= 0) {
            printf("Port %d is open.\n", port);
        }
    }

    close(sockfd);
    return 0;
}