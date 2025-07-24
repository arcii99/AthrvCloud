//FormAI DATASET v1.0 Category: Port Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void scan_port(char *ip, int port)
{
    struct sockaddr_in server_address;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip);
    server_address.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == 0) {
        printf("[+] Port %d is open!\n", port);
    }

    close(sockfd);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s <ip address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip = argv[1];

    printf("[*] Starting port scan on %s\n", ip);

    for (int port = 1; port <= 65535; port++) {
        scan_port(ip, port);
    }

    printf("[*] Port scan complete!\n");

    return 0;
}