//FormAI DATASET v1.0 Category: Port Scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in target;
    struct hostent *host;
    int start_port, end_port, port;
    char *target_ip;

    if (argc != 4) {
        printf("Usage: %s <ip_address> <start_port> <end_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    target_ip = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    bzero(&target, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(target_ip);
    host = gethostbyname(target_ip);
    memcpy(&target.sin_addr.s_addr, host->h_addr_list[0], host->h_length);

    printf("Starting port scan on target %s (IP: %s)\n", host->h_name, inet_ntoa(target.sin_addr));

    for (port = start_port; port <= end_port; port++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        target.sin_port = htons(port);
        if (connect(sockfd, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("[+] Port %d open\n", port);
            close(sockfd);
        }
    }
    printf("Port scanning on target %s (IP: %s) completed\n", host->h_name, inet_ntoa(target.sin_addr));

    return 0;
}