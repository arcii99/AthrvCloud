//FormAI DATASET v1.0 Category: Firewall ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

#define BUF_LEN 65535
#define TCP 6
#define UDP 17

void check_packet(unsigned char* buf);

int main()
{
    int sockfd;
    struct sockaddr_in addr;
    unsigned char buf[BUF_LEN];

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(0);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }

    while(1) {
        int len = recv(sockfd, buf, BUF_LEN, 0);
        if(len < 0) {
            perror("recv");
            exit(1);
        }

        check_packet(buf);
    }

    return 0;
}

void check_packet(unsigned char* buf)
{
    struct iphdr *ip = (struct iphdr *)buf;
    unsigned short iphdrlen = ip->ihl * 4;
    struct tcphdr *tcp = (struct tcphdr *)(buf + iphdrlen);
    struct udphdr *udp = (struct udphdr *)(buf + iphdrlen);

    if(ip->protocol == TCP) {
        printf("TCP packet received\n");

        printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *)&ip->saddr));
        printf("Source Port: %u\n", ntohs(tcp->source));
        printf("destination IP: %s\n", inet_ntoa(*(struct in_addr *)&ip->daddr));
        printf("Destination Port: %u\n", ntohs(tcp->dest));
        
        // firewall logic goes here
    } else if(ip->protocol == UDP) {
        printf("UDP packet received\n");

        printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *)&ip->saddr));
        printf("Source Port: %u\n", ntohs(udp->source));
        printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr *)&ip->daddr));
        printf("Destination Port: %u\n", ntohs(udp->dest));
        
        // firewall logic goes here
    }
}