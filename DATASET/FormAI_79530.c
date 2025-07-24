//FormAI DATASET v1.0 Category: Port Scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_PORT 65535
#define MAX_CONCURRENCY 512

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(1);
    }
    
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }
    
    printf("Scanning %s... \n", argv[1]);
    
    for (int port = 1; port <= MAX_PORT; port++) {
        struct sockaddr_in sock_info = {0};
        sock_info.sin_family = AF_INET;
        sock_info.sin_addr.s_addr = inet_addr(argv[1]);
        sock_info.sin_port = htons(port);
        int connfd = socket(AF_INET, SOCK_STREAM, 0);
        
        if (connfd == -1) {
            perror("error creating socket");
            exit(1);
        }
        
        int status = connect(connfd, (struct sockaddr *)&sock_info, sizeof(sock_info));
        if (status == 0) {
            printf("[*] Port %d - open \n", port);
        }
        
        close(connfd);
    }
    
    printf("Scan complete.\n");
    
    return 0;
}