//FormAI DATASET v1.0 Category: Port Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void showUsage(char *programName) {
    printf("Usage: %s <target_ip_address> <start_port> <end_port>\n", programName);
}

int main(int argc, char *argv[]) {
    if(argc != 4) {
        showUsage(argv[0]);
        return 1;
    }

    char *targetIp = argv[1];
    int startPort = atoi(argv[2]);
    int endPort = atoi(argv[3]);

    struct sockaddr_in target;

    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(targetIp);

    printf("Starting port scan on %s from port %d to %d\n", targetIp, startPort, endPort);

    for(int port = startPort; port <= endPort; port++) {
        target.sin_port = htons(port);

        int sock = socket(AF_INET, SOCK_STREAM, 0);

        if(connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d is open.\n", port);
        }

        close(sock);
    }

    return 0;
}