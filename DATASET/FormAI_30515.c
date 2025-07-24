//FormAI DATASET v1.0 Category: Network Ping Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>

#define PACKET_SIZE 64
#define MAX_HOP 30
#define MAX_RETRIES 3
#define TIMEOUT 1000 // in milliseconds

struct timeval tv_start, tv_end;

int send_packet(int sockfd, struct sockaddr_in *dest, int ttl, int seq) {
    char packet[PACKET_SIZE];
    struct icmp *icmp_hdr = (struct icmp*)packet;
    struct timeval tv;
    int pkt_size;

    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = getpid() & 0xFFFF;
    icmp_hdr->icmp_seq = seq;

    gettimeofday(&tv, NULL);
    memcpy(packet + sizeof(struct icmp), &tv, sizeof(struct timeval));
    pkt_size = sizeof(struct icmp) + sizeof(struct timeval);

    if (sendto(sockfd, packet, pkt_size, 0, (struct sockaddr *)dest, sizeof(struct sockaddr_in)) < 0) {
        perror("sendto() failed");
        return -1;
    }

    return 0;
}

int recv_packet(int sockfd, struct sockaddr_in *dest, int *seq, struct timeval *tv) {
    char buf[PACKET_SIZE];
    struct iphdr *ip_hdr = (struct iphdr *)buf;
    struct icmp *icmp_hdr;
    int pkt_size, addr_len = sizeof(struct sockaddr_in);
    fd_set read_fds;
    struct timeval timeout;

    FD_ZERO(&read_fds);
    FD_SET(sockfd, &read_fds);

    timeout.tv_sec = TIMEOUT / 1000;
    timeout.tv_usec = (TIMEOUT % 1000) * 1000;

    if (select(sockfd+1, &read_fds, NULL, NULL, &timeout) <= 0) {
        return -1;
    }

    if ((pkt_size = recvfrom(sockfd, buf, PACKET_SIZE, 0, (struct sockaddr *)dest, &addr_len)) < 0) {
        return -1;
    }

    icmp_hdr = (struct icmp*)(buf + (((struct iphdr*)buf)->ihl << 2));
    if (icmp_hdr->icmp_type == ICMP_ECHOREPLY) {
        if (icmp_hdr->icmp_id == (getpid() & 0xFFFF) && icmp_hdr->icmp_seq == *seq) {
            gettimeofday(tv, NULL);
            *seq += 1;
            return 0;
        }
    }

    return -1;
}

int ping(const char *dst_ip) {
    struct sockaddr_in dest;
    int sockfd, hop = 1, tries, seq = 0, ret = -1;
    struct timeval tv_last = {0, 0}, tv_diff;
    double rtt = 0;

    if (inet_aton(dst_ip, &dest.sin_addr) == 0) {
        printf("Invalid IP address: %s\n", dst_ip);
        return -1;
    }

    dest.sin_family = AF_INET;
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sockfd < 0) {
        perror("socket() failed");
        return -1;
    }

    for (hop = 1; hop <= MAX_HOP; hop++) {
        printf("Checking hop %d...\n", hop);
        if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &hop, sizeof(hop)) < 0) {
            perror("setsockopt() failed");
            close(sockfd);
            return -1;
        }

        for (tries = 0; tries < MAX_RETRIES; tries++) {
            if (send_packet(sockfd, &dest, hop, seq) < 0) {
                close(sockfd);
                return -1;
            }

            if (recv_packet(sockfd, &dest, &seq, &tv_end) == 0) {
                timersub(&tv_end, &tv_last, &tv_diff);
                rtt = tv_diff.tv_sec * 1000 + tv_diff.tv_usec / 1000;
                printf("    Reply from %s: time=%.2fms\n", inet_ntoa(dest.sin_addr), rtt);
                if (ret < 0) {
                    ret = 0;
                }
                break;
            }
        }

        if (tries == MAX_RETRIES) {
            printf("    Timeout\n");
            if (ret < 0) {
                ret = -1;
            }
        }

        tv_last = tv_end;
    }

    close(sockfd);

    return ret;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return -1;
    }

    printf("Pinging %s...\n", argv[1]);
    if (ping(argv[1]) == 0) {
        printf("Ping succeeded\n");
        return 0;
    } else {
        printf("Ping failed\n");
        return -1;
    }
}