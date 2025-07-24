//FormAI DATASET v1.0 Category: Email Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 4096

int main(int argc, char **argv) {
    
    int sockfd, n;
    char sendline[MAX_LINE], recvline[MAX_LINE + 1];
    struct sockaddr_in servaddr;
    
    if (argc < 3) {
        printf("usage: %s <IPaddress> <Port>\n", argv[0]);
        exit(1);
    }
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket error\n");
        exit(1);
    }
    
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("inet_pton error for %s\n", argv[1]);
        exit(1);
    }
    
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("connect error\n");
        exit(1);
    }
    
    while (fgets(sendline, MAX_LINE, stdin) != NULL) {
        if (write(sockfd, sendline, strlen(sendline)) < 0) {
            printf("write error\n");
            exit(1);
        }
        
        if ((n = read(sockfd, recvline, MAX_LINE)) < 0) {
            printf("read error\n");
            exit(1);
        }
        
        recvline[n] = 0;
        if (fputs(recvline, stdout) == EOF) {
            printf("fputs error\n");
            exit(1);
        }
    }
    
    if (n < 0) {
        printf("read error\n");
        exit(1);
    }
    
    exit(0);
}