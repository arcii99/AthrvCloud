//FormAI DATASET v1.0 Category: Port Scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>

typedef struct {
    unsigned short start_port;
    unsigned short end_port;
    char *ip_address;
} scan_config;

void scan_port(scan_config config);

void scan_port(scan_config config) {
    int sockfd, port;
    struct sockaddr_in target_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    char target_ip[16];
 
    strncpy(target_ip, config.ip_address, 15);
    target_ip[15] = '\0';

    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(target_ip);

    for (port = config.start_port; port <= config.end_port; port++) {
        sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        target_addr.sin_port = htons(port);

        if (connect(sockfd, (struct sockaddr *)&target_addr, len) == 0) {
            printf("Port %d is open at %s\n", port, target_ip);
            close(sockfd);
        }
    }
}

int main() {
    scan_config config;
    config.start_port = 1;
    config.end_port = 65535;
    config.ip_address = "127.0.0.1";
    scan_port(config);
}