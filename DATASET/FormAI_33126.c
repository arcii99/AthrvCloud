//FormAI DATASET v1.0 Category: Port Scanner ; Style: genious
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PORTS 65536

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(0);
    }

    char *host = argv[1];
    struct hostent *he;
    struct sockaddr_in addr;

    if ((he = gethostbyname(host)) == NULL) {
        printf("Unable to resolve host: %s\n", host);
        exit(1);
    }

    printf("Scanning ports on %s (%s):\n", host, inet_ntoa(*(struct in_addr*)he->h_addr_list[0]));
    
    int sockfd, n, err;
    for(int i = 0; i < MAX_PORTS; i++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if(sockfd < 0) {
            perror("socket");
            exit(2);
        }

        memset(&addr, 0, sizeof(struct sockaddr_in));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(i);
        addr.sin_addr = *(struct in_addr*)he->h_addr_list[0];

        err = connect(sockfd, (struct sockaddr*)&addr, sizeof(struct sockaddr_in));
        if(err != -1) {
            printf("Port %d is open\n", i);
        }

        close(sockfd);
    }
    return 0;
}