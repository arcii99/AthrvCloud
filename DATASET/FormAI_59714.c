//FormAI DATASET v1.0 Category: Port Scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

#define MAX_PORTS 65535

int main(int argc, char *argv[]) {
    int sockfd, result, count = 0;
    struct sockaddr_in target_addr;
    bool open_ports[MAX_PORTS];
    
    if (argc < 2) {
        printf("Usage: %s <target IP address>\n", argv[0]);
        return 1;
    }
    
    memset(open_ports, 0, sizeof(open_ports));
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() error");
        return 1;
    }
    
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(argv[1]);
    
    for (int port = 1; port <= MAX_PORTS; ++port) {
        target_addr.sin_port = htons(port);
        result = connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr));
        if (result != -1) {
            open_ports[port] = true;
            printf("Port %d is open.\n", port);
        }
        close(sockfd);
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("socket() error");
            return 1;
        }
    }
    
    printf("The following ports are open: ");
    for (int i = 1; i <= MAX_PORTS; ++i) {
        if (open_ports[i]) {
            printf("%d ", i);
            ++count;
        }
    }
    if (count == 0) {
        printf("none");
    }
    printf("\n");
    
    return 0;
}