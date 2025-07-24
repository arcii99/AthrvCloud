//FormAI DATASET v1.0 Category: Port Scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, port;
    struct sockaddr_in target;
    struct hostent *host;
    
    if(argc != 3) {
        printf("Usage: %s <IP/Hostname> <Port>\n", argv[0]);
        exit(1);
    }
    
    if((host = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        exit(1);
    }
    
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    
    target.sin_family = AF_INET;
    target.sin_port = htons(atoi(argv[2]));
    target.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(target.sin_zero), 8);
    
    if(connect(sockfd, (struct sockaddr *)&target, sizeof(struct sockaddr)) == -1) {
        printf("Port %d is closed on %s\n", atoi(argv[2]), argv[1]);
        close(sockfd);
        exit(1);
    }
    
    printf("Port %d is open on %s\n", atoi(argv[2]), argv[1]);
    close(sockfd);
    
    return 0;
}