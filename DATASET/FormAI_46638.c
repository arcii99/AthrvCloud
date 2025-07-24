//FormAI DATASET v1.0 Category: Network Ping Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define BUF_SIZE 64
#define ICMP_ECHO_REQUEST 8 /* ICMP Echo Request */
#define ICMP_ECHO_REPLY 0 /* ICMP Echo Reply */

/* ICMP header structure */
struct icmp_hdr {
    uint8_t type; /* message type */
    uint8_t code; /* type sub-code */
    uint16_t checksum; /* 16-bit ICMP checksum */
    union {
        struct {
            uint16_t id; /* identifier */
            uint16_t sequence; /* sequence number */
        } echo; /* echo datagram */
        uint32_t gateway; /* gateway address */
        struct {
            uint16_t unused;
            uint16_t mtu;
        } frag; /* path mtu discovery */
    } un;
};

/* IP header structure */
struct ip_hdr {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    uint8_t ihl : 4;
    uint8_t version : 4;
#elif __BYTE_ORDER == __BIG_ENDIAN
    uint8_t version : 4;
    uint8_t ihl : 4;
#else
#error "Byte order not defined"
#endif
    uint8_t tos; /* type of service */
    uint16_t len; /* total length */
    uint16_t id; /* identification */
    uint16_t off; /* fragment offset field */
    uint8_t ttl; /* time to live */
    uint8_t protocol; /* protocol */
    uint16_t chksum; /* checksum */
    struct in_addr src; /* source IP address */
    struct in_addr dst; /* destination IP address */
};

/* Calculate checksum */
uint16_t checksum(void *buf, int len) {
    uint16_t *data = (uint16_t *)buf;
    uint32_t sum = 0;

    for (; len > 1; len -= 2)
        sum += *data++;

    if (len == 1)
        sum += *(uint8_t *)data;

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);

    return (uint16_t)~sum;
}

/* Send ICMP echo request */
int send_icmp_echo_request(int sockfd, struct sockaddr_in *dest_addr,
                           int seq, int ttl) {
    char buf[BUF_SIZE];
    int datalen = 56;
    struct icmp_hdr *icmp_hdr;

    memset(buf, 0, sizeof(buf));

    icmp_hdr = (struct icmp_hdr *)buf;
    icmp_hdr->type = ICMP_ECHO_REQUEST;
    icmp_hdr->code = 0;
    icmp_hdr->un.echo.id = htons(getpid());
    icmp_hdr->un.echo.sequence = htons(seq);
    memset(&buf[sizeof(struct icmp_hdr)], 0xa5, datalen);

    icmp_hdr->checksum = 0;
    icmp_hdr->checksum = checksum(icmp_hdr, sizeof(struct icmp_hdr) + datalen);

    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0) {
        perror("setsockopt");
        return -1;
    }

    if (sendto(sockfd, buf, sizeof(struct icmp_hdr) + datalen, 0,
               (struct sockaddr *)dest_addr, sizeof(*dest_addr)) < 0) {
        perror("sendto");
        return -1;
    }

    return 0;
}

/* Receive ICMP echo reply */
int recv_icmp_echo_reply(int sockfd, struct sockaddr_in *src_addr,
                         int seq, struct timeval *tv) {
    char buf[BUF_SIZE];
    socklen_t len = sizeof(*src_addr);
    struct ip_hdr *ip_hdr;
    struct icmp_hdr *icmp_hdr;
    int n;
    double rtt;

    while (1) {
        fd_set readfds;
        struct timeval timeout;
        struct timeval start;
        struct timeval end;

        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        timeout.tv_sec = 2;
        timeout.tv_usec = 0;

        gettimeofday(&start, NULL);

        /* Wait for response */
        if (select(sockfd + 1, &readfds, NULL, NULL, &timeout) <= 0) {
            fprintf(stdout, "*\n");
            return -1;
        }

        if ((n = recvfrom(sockfd, buf, sizeof(buf), 0,
                          (struct sockaddr *)src_addr, &len)) >= 0) {
            /* Get IP header */
            ip_hdr = (struct ip_hdr *)buf;

            /* Get ICMP header */
            icmp_hdr = (struct icmp_hdr *)(buf + (ip_hdr->ihl * 4));

            /* Check if it's an ICMP echo reply */
            if (icmp_hdr->type == ICMP_ECHO_REPLY && ntohs(icmp_hdr->un.echo.id) == getpid()) {
                if (ntohs(icmp_hdr->un.echo.sequence) != seq)
                    continue;

                /* Calculate round-trip time */
                gettimeofday(&end, NULL);

                tv->tv_sec = end.tv_sec - start.tv_sec;
                tv->tv_usec = end.tv_usec - start.tv_usec;

                if (tv->tv_usec < 0) {
                    tv->tv_sec--;
                    tv->tv_usec += 1000000;
                }

                rtt = tv->tv_sec * 1000.0 + tv->tv_usec / 1000.0;

                fprintf(stdout, "%.3f ms\n", rtt);

                return 0;
            }
        }
    }
}

/* Perform ping test */
void ping_test(const char *ipaddr) {
    int sockfd;
    struct sockaddr_in dest_addr;
    struct sockaddr_in src_addr;
    int ttl = 64;
    int seq = 0;
    struct timeval tv;

    /* Create socket */
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    /* Set source and destination addresses */
    memset(&src_addr, 0, sizeof(src_addr));
    src_addr.sin_family = AF_INET;
    src_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    if (inet_aton(ipaddr, &dest_addr.sin_addr) == 0) {
        fprintf(stderr, "Invalid IP address\n");
        exit(EXIT_FAILURE);
    }

    /* Print ping header */
    fprintf(stdout, "PING %s (%s) %d bytes of data.\n", ipaddr,
            inet_ntoa(dest_addr.sin_addr), BUF_SIZE - sizeof(struct icmp_hdr));

    while (1) {
        /* Send echo request */
        seq++;
        if (send_icmp_echo_request(sockfd, &dest_addr, seq, ttl) < 0)
            continue;

        /* Receive echo reply */
        if (recv_icmp_echo_reply(sockfd, &src_addr, seq, &tv) < 0)
            continue;
    }

    /* Close socket */
    close(sockfd);
}

int main(int argc, char *argv[]) {
    /* Check command-line arguments */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Perform ping test */
    ping_test(argv[1]);

    return 0;
}