//FormAI DATASET v1.0 Category: Port Scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT_START 1
#define PORT_END 65535

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <ip address>\n",argv[0]);
        exit(1);
    }

    struct hostent *host = gethostbyname(argv[1]);
    char *ip = inet_ntoa(*((struct in_addr*) host->h_addr_list[0]));
    printf("Scanning %s (%s)\n",argv[1],ip);

    int fd;
    for(int port = PORT_START; port <= PORT_END; port++) {
        fd = socket(AF_INET, SOCK_STREAM, 0);
        if(fd == -1) {
            perror("socket");
            exit(1);
        }
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        inet_aton(ip, &(addr.sin_addr));
        if(connect(fd, (struct sockaddr*) &addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", port);
        }
        close(fd);
    }
    return 0;
}