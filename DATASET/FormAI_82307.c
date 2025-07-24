//FormAI DATASET v1.0 Category: Port Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Please enter a host/IP address.\n");
        exit(1);
    }
    char *host = argv[1];
    struct hostent *he;
    he = gethostbyname(host);
    if(he == NULL) {
        printf("Error: Couldn't resolve host %s.\n", host);
        exit(1);
    }
    printf("Starting port scan for %s...\n", host);
    printf("____________________________\n");

    int sockfd;
    struct sockaddr_in addr;
    for(int port=1; port<=65535; port++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr = *((struct in_addr *)he->h_addr);
        memset(&(addr.sin_zero), 0, 8);
        
        int result = connect(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr));
        if(result == 0) {
            printf("[+] %d/tcp open\n", port);
            close(sockfd);
            continue;
        }
        close(sockfd);
    }
    printf("____________________________\n");
    printf("Scan complete.\n");
    printf("Thank you for using my Port Scanner. I hope no one is hacking you!\n");
    return 0;
}