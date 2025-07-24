//FormAI DATASET v1.0 Category: Port Scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <time.h>
#include <stdbool.h>

struct sockaddr_in server;
char *ipv4_addr = "127.0.0.1";

void scan_port(int port) {
    int sockfd;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ipv4_addr);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        return;
    }
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d open\n", port);
    }
    close(sockfd);
}

void scan_ports(int start_port, int end_port){
    int i;
    for (i = start_port; i <= end_port; i++) {
        scan_port(i);
    }
} 

int main(int argc, char **argv) {
    scan_ports(1, 1000);
    return 0;
}