//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define IP "127.0.0.1"
#define PING_MS 5000
int main(int argc, char* argv[]) {
    struct sockaddr_in sin;
    struct timeval tv;
    int s;
    int ret;
    s = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    if (s < 0) {
        fprintf(stderr, "socket() error\n");
        exit(1);
    }
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(IP);
    sin.sin_port = htons(0);
    ret = connect(s, (struct sockaddr*)&sin, sizeof(sin));
    if (ret < 0) {
        fprintf(stderr, "connect() error\n");
        close(s);
        exit(1);
    }
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    ret = setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));
    if (ret < 0) {
        fprintf(stderr, "setsockopt() error\n");
        close(s);
        exit(1);
    }
    ret = sendto(s, NULL, 0, 0, (struct sockaddr*)&sin, sizeof(sin));
    if (ret < 0) {
        fprintf(stderr, "sendto() error\n");
        close(s);
        exit(1);
    }
    printf("Ping sent to %s, waiting for response...\n", IP);
    char buffer[80];
    struct sockaddr_in rec_addr;
    socklen_t addrlen = sizeof(rec_addr);
    ret = recvfrom(s, buffer, sizeof(buffer), 0, (struct sockaddr*)&rec_addr, &addrlen);
    if (ret < 0) {
        fprintf(stderr, "recvfrom() error\n");
        close(s);
        exit(1);
    }
    printf("Received %d bytes from %s\n", ret, IP);
    printf("Device is up and running!\n");
    return 0;
}