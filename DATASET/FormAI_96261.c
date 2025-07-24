//FormAI DATASET v1.0 Category: Port Scanner ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in target;
    int start_port, end_port;
    int port;
    char* target_address;

    if (argc != 4) {
        printf("Usage: %s <target_address> <start_port> <end_port>\n", argv[0]);
        exit(0);
    }

    target_address = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    printf("Starting portscan on %s from port %d to %d\n", target_address, start_port, end_port);

    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(target_address);

    for (port = start_port; port <= end_port; port++) {
        target.sin_port = htons(port);
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (connect(sockfd, (struct sockaddr *)&target, sizeof(target)) == 0) {
            close(sockfd);
            printf("Port %d is open\n", port);
        }
    }
    printf("Portscan complete\n");
    return 0;
}