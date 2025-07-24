//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/time.h>

#define MAX_HOSTS 1000
#define MAX_PORTS 100

int main(int argc, char **argv) {
    struct timeval tv;
    tv.tv_sec = 2; // Change timeout as needed
    tv.tv_usec = 0;

    if(argc < 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(1);
    }
    char *addr_str = argv[1];

    struct in_addr addr;
    if(inet_aton(addr_str, &addr) == 0) {
        fprintf(stderr, "Invalid IP Address: %s\n", addr_str);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Could not create socket");
        exit(1);
    }

    if(setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("Could not set receive timeout");
        exit(1);
    }

    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(struct sockaddr_in));
    sa.sin_family = AF_INET;
    memcpy(&sa.sin_addr, &addr, sizeof(struct in_addr));

    int ports[MAX_PORTS] = {80, 443, 21, 22, 23, 25, 53, 587, 989, 990, 993, 995, 1433, 1434, 1521, 1723, 3306, 3389, 5800, 5900, 8080};
    int num_ports = sizeof(ports) / sizeof(int);

    char hostnames[MAX_HOSTS][256] = {0};
    int num_hosts = 0;

    for(int i = 0; i < num_ports; i++) {
        sa.sin_port = htons(ports[i]);

        if(connect(sockfd, (struct sockaddr *)&sa, sizeof(sa)) == 0) {
            struct hostent *he = gethostbyaddr(&addr, sizeof(addr), AF_INET);
            if(he != NULL) {
                strncpy(hostnames[num_hosts], he->h_name, 255);
            } else {
                sprintf(hostnames[num_hosts], "%s", addr_str);
            }

            printf("%s, %d\n", hostnames[num_hosts], ports[i]);
            num_hosts++;

            close(sockfd);

            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if(sockfd < 0) {
                perror("Could not create socket");
                exit(1);
            }

            if(setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
                perror("Could not set receive timeout");
                exit(1);
            }
        }
    }

    if(num_hosts == 0) {
        printf("No open ports found\n");
    }

    return 0;
}