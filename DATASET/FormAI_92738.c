//FormAI DATASET v1.0 Category: Network Ping Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <unistd.h>

#define PACKETSIZE 64

int ping(char *host, int ttl, int timeout, int max_hop);

unsigned short checksum(void *b, int len);

int receive_ping(int sock, struct timeval *start_time, int timeout, char *from_addr);

int main(int argc, char *argv[]) {
    char *host;
    int ttl, timeout, max_hop;

    if (argc != 4) {
        printf("Usage: %s <host> <ttl> <timeout>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    ttl = atoi(argv[2]);
    timeout = atoi(argv[3]);
    max_hop = ttl + 5;

    printf("Pinging %s with max hop %d, timeout %d and %d initial TTL\n", host, max_hop, timeout, ttl);

    ping(host, ttl, timeout, max_hop);

    return 0;
}

int ping(char *host, int ttl, int timeout, int max_hop) {
    struct hostent *hname;
    struct sockaddr_in pingaddr;
    struct in_addr addr;
    struct timeval start_time;

    int sock, count, len;
    char packet[PACKETSIZE];
    int ttl_array[max_hop];

    memset(packet, 0, PACKETSIZE);
    memset(&pingaddr, 0, sizeof(pingaddr));
    memset(ttl_array, 0, sizeof(ttl_array));

    if ((sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Can not create socket");
        return -1;
    }

    if (setsockopt(sock, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) != 0) {
        perror("Error setting TTL value");
        return -1;
    }

    if ((hname = gethostbyname(host)) == NULL) {
        printf("Unknown host %s\n", host);
        return -1;
    }

    bcopy(hname->h_addr, &pingaddr.sin_addr, hname->h_length);
    pingaddr.sin_family = AF_INET;

    addr.s_addr = *(unsigned int *) hname->h_addr_list[0];
    printf("Ping address: %s\n", inet_ntoa(addr));

    int i;
    for (i = ttl; i <= max_hop; i++) {
        count = 0;
        int j;
        for (j = 0; j < 3; j++) {
            len = sizeof(struct sockaddr_in);
            gettimeofday(&start_time, NULL);
            sprintf(packet, "PING %d %ld", i, start_time.tv_usec);
            *((unsigned short *) packet) = htons(checksum(packet, strlen(packet)));
            if (setsockopt(sock, IPPROTO_IP, IP_TTL, &i, sizeof(i)) != 0) {
                perror("Error setting TTL value");
                close(sock);
                return -1;
            }

            if (sendto(sock, packet, strlen(packet), 0, (struct sockaddr *) &pingaddr, len) <= 0) {
                perror("Error in sendto");
                close(sock);
                return -1;
            }

            char from_addr[20];
            int icmp_type = receive_ping(sock, &start_time, timeout, from_addr);
            if (icmp_type == ICMP_TIME_EXCEEDED) {
                printf("%d hop router is %s - Time to live exceeded\n", i, from_addr);
            } else if (icmp_type == ICMP_ECHOREPLY) {
                printf("%d hop router is %s - Ping Response, RTT : %ld microseconds\n", i, from_addr, ((&start_time)->tv_usec - start_time.tv_usec));
                break;
            } else {
                printf("unexpected reply %d - %s", icmp_type, from_addr);
            }

            count++;
        }
    }

    close(sock);
    return 0;
}

int receive_ping(int sock, struct timeval *start_time, int timeout, char *from_addr) {
    struct sockaddr_in addr;
    struct icmp *icmp_packet;

    int addrlen, ret;

    fd_set read_fd;
    struct timeval wait_timer;

    FD_ZERO(&read_fd);
    FD_SET(sock, &read_fd);

    wait_timer.tv_sec = timeout / 1000;
    wait_timer.tv_usec = (timeout % 1000) * 1000;

    if ((ret = select(sock + 1, &read_fd, NULL, NULL, &wait_timer)) == -1) {
        perror("select");
    } else if (!ret) {
        return -1;
    } else {
        addrlen = sizeof(struct sockaddr_in);
        if (recvfrom(sock, (void *) &icmp_packet, sizeof(struct icmp), 0, (struct sockaddr *) &addr, &addrlen) < 0) {
            perror("recvfrom");
        } else {
            sprintf(from_addr, "%s", inet_ntoa(addr.sin_addr));
            if (icmp_packet->icmp_type == ICMP_ECHOREPLY)
                return ICMP_ECHOREPLY;
            else if (icmp_packet->icmp_type == ICMP_TIME_EXCEEDED)
                return ICMP_TIME_EXCEEDED;
            else
                return -1;
        }
    }

    return -1;
}

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    if (len == 1) {
        sum += *(unsigned char *) buf;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}