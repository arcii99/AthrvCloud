//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netdb.h>
#include <ctype.h>

#define PORT 3074
#define BUFSIZE 8192

void send_packet(int sd, struct sockaddr_in target, int ttl);

int main(int argc, char* argv[]) {
    int sd;
    struct sockaddr_in target;
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = htonl(INADDR_BROADCAST);
    target.sin_port = htons(PORT);

    if ((sd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1) {
        perror("Cannot create socket");
        return -1;
    }

    int ttl = 1;

    while(ttl<=30) {
        setsockopt(sd, IPPROTO_IP, IP_MULTICAST_TTL, &ttl, sizeof(ttl));
        send_packet(sd, target, ttl);
        ttl++;
    }

    close(sd);
    return 0;
}

void send_packet(int sd, struct sockaddr_in target, int ttl) {
    char buffer[BUFSIZE];
    int len = sprintf(buffer, "PING %s (ttl=%d)\n", inet_ntoa(target.sin_addr), ttl);
    sendto(sd, buffer, len, 0, (struct sockaddr*)&target, sizeof(target));
}