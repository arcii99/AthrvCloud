//FormAI DATASET v1.0 Category: Port Scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAX_PORT 5000
#define MIN_PORT 1

int scan_port(char *ip, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        return -1;
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        close(sockfd);
        return -1;
    }

    printf("[+] Port %d open\n", port);
    close(sockfd);
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <ip address>\n", argv[0]);
        return 0;
    }

    char *ip = argv[1];

    printf("Scanning started for %s...\n", ip);

    for (int i = MIN_PORT; i <= MAX_PORT; i++) {
        if (scan_port(ip, i) == 0) {
            printf("[+] Port %d open\n", i);
        }
    }

    printf("Scanning complete.\n");

    return 0;
}