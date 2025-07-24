//FormAI DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<netdb.h>

int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(-1);
    }
    struct hostent *host = gethostbyname(argv[1]);
    if(host == NULL) {
        printf("Cannot resolve the hostname %s\n", argv[1]);
        exit(-1);
    }
    int fd;
    if((fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("socket()");
        exit(-1);
    }
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(80);
    address.sin_addr = *((struct in_addr*) host->h_addr);

    if(connect(fd, (struct sockaddr *) &address, sizeof(struct sockaddr)) < 0) {
        perror("connect()");
        exit(-1);
    }

    printf("Port 80 is open on %s\n", argv[1]);

}