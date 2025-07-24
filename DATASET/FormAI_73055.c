//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <signal.h>

#define MAX_PACKET_SIZE 65536

int stop = 0;

void sigintHandler(int sig)
{
    stop = 1;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(0);
    }

    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("Socket Error:");
        exit(1);
    }

    int on = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) < 0) {
        perror("setsockopt Error:");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind Error:");
        exit(1);
    }

    signal(SIGINT, sigintHandler);

    while (!stop) {
        char buffer[MAX_PACKET_SIZE];
        memset(buffer, 0, sizeof(buffer));

        int count = recvfrom(sockfd, buffer, MAX_PACKET_SIZE, 0, NULL, NULL);
        if (count < 0) {
            perror("Recvfrom Error:");
            exit(1);
        }

        struct iphdr *ip_hdr = (struct iphdr *)buffer;
        if (ip_hdr->protocol == IPPROTO_TCP) {
            struct tcphdr *tcp_hdr = (struct tcphdr *)(buffer + ip_hdr->ihl * 4);

            uint32_t src_ip = ip_hdr->saddr;
            uint32_t dst_ip = ip_hdr->daddr;
            uint16_t src_port = ntohs(tcp_hdr->source);
            uint16_t dst_port = ntohs(tcp_hdr->dest);
            uint32_t seq_num = ntohl(tcp_hdr->seq);

            printf("Source IP: %s  Source Port: %d  Destination IP: %s  Destination Port: %d  Sequence Number: %u\n",
                inet_ntoa(*(struct in_addr *)&src_ip), src_port, inet_ntoa(*(struct in_addr *)&dst_ip),
                dst_port, seq_num);
        }
    }

    close(sockfd);

    return 0;
}