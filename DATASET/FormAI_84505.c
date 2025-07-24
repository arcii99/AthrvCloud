//FormAI DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT 65535
#define PORT_RANGE 100

void scan_ports(char *ip_addr, int start_port, int end_port) {
int sockfd, port;
struct sockaddr_in target_addr;
socklen_t len = sizeof(struct sockaddr_in);

memset(&target_addr, 0, sizeof(struct sockaddr_in));
target_addr.sin_family = AF_INET;
target_addr.sin_addr.s_addr = inet_addr(ip_addr);

for (port = start_port; port <= end_port; port++) {
    target_addr.sin_port = htons(port);
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (connect(sockfd, (struct sockaddr *)&target_addr, len) == 0) {
        printf("Port %d is opened.\n", port);
        close(sockfd);
    }
}
}

int main(int argc, char **argv) {
if (argc < 2) {
    printf("Usage: %s IP_address.\n", argv[0]);
    exit(EXIT_FAILURE);
}

char *ip_addr = argv[1];
int start_port = 1;
int end_port = start_port + PORT_RANGE;

printf("Scanning ports for %s...\n", ip_addr);

while (end_port < MAX_PORT) {
    scan_ports(ip_addr, start_port, end_port);
    start_port = end_port + 1;
    end_port = start_port + PORT_RANGE;
}

printf("Scanning completed.\n");

return 0;
}