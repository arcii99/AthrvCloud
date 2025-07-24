//FormAI DATASET v1.0 Category: Network Ping Test ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define PACKET_SIZE 64
#define ICMP_HDR_SIZE 8
#define MAX_HOPS 30

struct icmp_packet {
    struct icmphdr icmp_hdr;
    char padding[PACKET_SIZE - ICMP_HDR_SIZE];
};

void print_usage(char* program_name) {
    printf("Usage: %s <target IP address>", program_name);
    exit(EXIT_FAILURE);
}

u_short compute_checksum(void* buf, int len) {
    u_short* ptr = (u_short*)buf;
    int sum = 0;
    u_short answer = 0;

    for (int i = 0; i < len / 2; i++) {
        sum += *ptr++;
    }

    if (len % 2) {
        sum += *(u_char*)ptr;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum = sum + (sum >> 16);
    answer = ~sum;

    return answer;
}

int ping(char* target_ip, int ttl, int timeout) {
    struct icmp_packet packet;
    struct sockaddr_in addr;
    int sockfd;
    int datalen = ICMP_HDR_SIZE + sizeof(packet.padding);
    int fromlen = sizeof(addr);
    struct timeval tv;
    tv.tv_sec = timeout / 1000;
    tv.tv_usec = (timeout % 1000) * 1000;
    int rtt;
    int attempts = 3;
    int result = 0;

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, target_ip, &addr.sin_addr);

    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0) {
        perror("setsockopt error");
        exit(EXIT_FAILURE);
    }

    bzero(&packet, sizeof(packet));
    packet.icmp_hdr.type = ICMP_ECHO;
    packet.icmp_hdr.code = 0;
    packet.icmp_hdr.un.echo.sequence = rand() % 65536;
    packet.icmp_hdr.un.echo.id = getpid() & 0xFFFF;
    packet.icmp_hdr.checksum = compute_checksum(&packet, datalen);

    if (sendto(sockfd, &packet, datalen, 0, (struct sockaddr*)&addr, sizeof(addr)) <= 0) {
        perror("sendto error");
        result = 1;
        goto cleanup;
    }

    char recvbuf[PACKET_SIZE];
    struct sockaddr_in from;
    struct timeval start_time, end_time;
    int num_replies = 0;

    gettimeofday(&start_time, NULL);

    for (int i = 0; i < attempts; i++) {
        fd_set read_set;
        FD_ZERO(&read_set);
        FD_SET(sockfd, &read_set);
        int n_ready = select(sockfd + 1, &read_set, NULL, NULL, &tv);

        if (n_ready < 0) {
            perror("select error");
            result = 1;
            goto cleanup;
        }
        else if (n_ready == 0) {
            continue;
        }

        ssize_t recvlen = recvfrom(sockfd, recvbuf, sizeof(recvbuf), 0, (struct sockaddr*)&from, &fromlen);

        if (recvlen < 0) {
            perror("recvfrom error");
            result = 1;
            goto cleanup;
        }

        if (from.sin_addr.s_addr != addr.sin_addr.s_addr) {
            continue;
        }

        num_replies++;
        gettimeofday(&end_time, NULL);
        rtt = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;

        struct icmphdr* icmp_hdr_reply = (struct icmphdr*)recvbuf;
        if (icmp_hdr_reply->type == ICMP_ECHOREPLY) {
            printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%d ms\n", (int)recvlen, target_ip, icmp_hdr_reply->un.echo.sequence, ttl, rtt);
        }
        else {
            printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%d ms (unhandled type=%d code=%d)\n", (int)recvlen, target_ip, icmp_hdr_reply->un.echo.sequence, ttl, rtt, icmp_hdr_reply->type, icmp_hdr_reply->code);
        }

        if (num_replies >= 1) {
            break;
        }
    }

cleanup:
    close(sockfd);
    return result;
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    if (argc != 2) {
        print_usage(argv[0]);
    }

    char* target_ip = argv[1];
    int ttl = 1;

    printf("PING %s\n", target_ip);

    while (ttl <= MAX_HOPS) {
        printf("TTL=%d\n", ttl);
        if (ping(target_ip, ttl, 500) == 1) {
            break;
        }

        ttl++;
    }

    return 0;
}