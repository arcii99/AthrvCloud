//FormAI DATASET v1.0 Category: Port Scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXPORT 65535

int main(int argc, char *argv[]) {

    if(argc != 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    int sockfd, port, optval = 1;
    struct sockaddr_in target;
    struct timeval timeout;
    timeout.tv_sec = 3;
    timeout.tv_usec = 0;

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);    
    }

    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(hostname);
    memset(&(target.sin_zero), '\0', 8);

    printf("Target: %s\n", inet_ntoa(target.sin_addr));

    printf("   * Scanning ports 1-65535...\n");
    printf("   * This may take some time...\n\n");
    int open_ports = 0;

    for(port = 1; port <= MAXPORT; port++) {

        target.sin_port = htons(port);
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

        if(connect(sockfd, (struct sockaddr *)&target, sizeof(struct sockaddr)) == 0) {
            printf("[+] Port %d is open\n", port);
            open_ports++;
            close(sockfd);
            if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
                perror("socket");
                exit(EXIT_FAILURE);
            }
        }
    }

    if(open_ports == 0) {
        printf("[-] No open ports found...\n");
    } else {
        printf("\n   * Scanning complete! %d open ports found.\n", open_ports);
    }

    return EXIT_SUCCESS;
}