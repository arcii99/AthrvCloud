//FormAI DATASET v1.0 Category: Network Ping Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netdb.h>
 
#define PACKET_SIZE 4096
#define MAX_WAIT_TIME 5
#define MAX_NO_PACKETS 3
 
struct packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};
 
int ping(const char *ip)
{
    struct timeval tv_begin, tv_end;
    struct packet p;
    struct sockaddr_in addr_ping;
    struct sockaddr_in addr_pong;
    int sockfd, i,  packetsize, count = 0, nbytes, recvcount = 0;
    long double rtt[MAX_NO_PACKETS];
    struct hostent *host;
    struct timeval timeout = {
        .tv_sec = MAX_WAIT_TIME,
        .tv_usec = 0
    };
 
    memset(&addr_ping, 0, sizeof(addr_ping));
    memset(&addr_pong, 0, sizeof(addr_pong));
 
    addr_ping.sin_family = AF_INET;
    addr_pong.sin_family = AF_INET;
 
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("socket");
        return -1;
    }
 
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt");
        return -1;
    }
 
    packetsize = sizeof(struct icmphdr) + sizeof(struct timeval);
 
    memset(&p, 0, packetsize);
    p.hdr.type = ICMP_ECHO;
    p.hdr.un.echo.id = getpid();
 
    for (i = 0; i < sizeof(p.msg) - 1; i++)
        p.msg[i] = i + '0';
 
    if ((host = gethostbyname(ip)) == NULL) {
        perror("gethostbyname");
        return -1;
    }
 
    memcpy(&addr_ping.sin_addr, host->h_addr, host->h_length);
    printf("PING %s (%s) %d bytes of data.\n", ip, inet_ntoa(addr_ping.sin_addr), packetsize - sizeof(struct icmphdr));
 
    while (count < MAX_NO_PACKETS) {
        if (sendto(sockfd, &p, packetsize, 0, (struct sockaddr *)&addr_ping, sizeof(addr_ping)) < 0) {
            perror("sendto");
            return -1;
        }
 
        if ((nbytes = recvfrom(sockfd, &p, packetsize, 0, (struct sockaddr *)&addr_pong, (socklen_t *)&packetsize)) < 0) {
            printf("timeout\n");
        } else {
            gettimeofday(&tv_end, NULL);
 
            if (p.hdr.type == ICMP_ECHOREPLY) {
                struct timeval *tval = (struct timeval *)p.msg;
 
                tval->tv_sec = ntohl(tval->tv_sec);
                tval->tv_usec = ntohl(tval->tv_usec);
 
                long double rtt_msec = (tv_end.tv_sec - tv_begin.tv_sec) * 1000.0 + (tv_end.tv_usec - tv_begin.tv_usec) / 1000.0;
                printf("%d bytes from %s: icmp_seq=%u ttl=%d time=%.1Lf ms\n", nbytes, inet_ntoa(addr_pong.sin_addr), p.hdr.un.echo.sequence, p.hdr.un.echo.id, rtt_msec);
                rtt[recvcount] = rtt_msec;
                recvcount++;
            }
        }
 
        count++;
        sleep(1);
    }
 
    if (recvcount > 0) {
        long double total = 0.0;
 
        for (i = 0; i < recvcount; i++)
            total += rtt[i];
 
        printf("rtt min/avg/max = %.1Lf/%.1Lf/%.1Lfs\n", rtt[0], total / recvcount, rtt[recvcount - 1]);
    } else {
        printf("Request timed out.\n");
    }
 
    close(sockfd);
 
    return 0;
}
 
int main(int argc, char *argv[])
{
    if (argc <= 1) {
        printf("Usage: %s <hostname or IP>\n", argv[0]);
        return -1;
    }
 
    return ping(argv[1]);
}