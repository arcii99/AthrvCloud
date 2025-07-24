//FormAI DATASET v1.0 Category: Port Scanner ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, flag, port, start, end;
    struct sockaddr_in addr;
    struct hostent *host;

    if(argc != 4) {
        printf("Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        exit(0);
    }

    if((host=gethostbyname(argv[1])) == NULL) {
        printf("Could not resolve hostname %s\n", argv[1]);
        exit(1);
    }

    start = atoi(argv[2]);
    end = atoi(argv[3]);

    printf("Scanning ports %d to %d on %s (%s)\n", start, end, argv[1], inet_ntoa(*(struct in_addr*)host->h_addr));

    for(port = start; port <= end; port++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr = *(struct in_addr*)host->h_addr;

        flag = connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));

        if(flag == 0) {
            printf("Port %d is open\n", port);
        }

        close(sockfd);
    }

    printf("Scan complete!\n");

    return 0;
}