//FormAI DATASET v1.0 Category: Port Scanner ; Style: expert-level
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in target_addr;
    unsigned short port_start, port_end;

    if(argc < 4) {
        fprintf(stderr, "Usage: %s <target IP> <port start> <port end>\n", argv[0]);
        exit(1);
    }

    bzero((char*)&target_addr, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(argv[1]);
    port_start = atoi(argv[2]);
    port_end = atoi(argv[3]);

    for(unsigned short port=port_start; port<=port_end; port++) {
        sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if(sockfd < 0) {
            perror("Cannot open socket");
            exit(1);
        }

        target_addr.sin_port = htons(port);

        if(connect(sockfd, (struct sockaddr*)&target_addr, sizeof(target_addr)) == 0) {
            printf("Port %d is open!\n", port);
        } else {
            printf("Port %d is closed.\n", port);
        }

        close(sockfd);
    }

    return 0;
}