//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define PING_PKT_S 64
#define RECV_TIMEOUT 1

struct ping_pkt {
    struct icmphdr hdr;
    char msg[PING_PKT_S-sizeof(struct icmphdr)];
};

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum=0;
    unsigned short result;

    for (sum=0; len>1; len-=2)
        sum += *buf++;

    if (len==1)
        sum += *(unsigned char*)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

void send_ping(int sockfd, struct sockaddr *dest_addr, int seq_no) {
    int ttl_val=64;
    int msg_count=0;
    struct ping_pkt pkt;
    int addr_len = sizeof(struct sockaddr);

    memset(&pkt, 0, sizeof(pkt));

    pkt.hdr.type = ICMP_ECHO;
    pkt.hdr.un.echo.id = getpid();

    for (int i = 0; i < sizeof(pkt.msg) - 1; i++)
        pkt.msg[i] = i + '0';

    pkt.msg[sizeof(pkt.msg) - 1] = 0;
    pkt.hdr.un.echo.sequence = seq_no;
    pkt.hdr.checksum = checksum(&pkt, sizeof(pkt));

    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl_val, sizeof(ttl_val)) < 0) {
        perror("Error in setting TTL of socket");
        return;
    }

    clock_t start_time = clock();
    if (sendto(sockfd, &pkt, sizeof(pkt), 0, dest_addr, addr_len) <= 0) {
        perror("Error in sending Ping request");
    }

    return;
}

int recv_ping(int sockfd, struct sockaddr *dest_addr, int seq_no) {
    struct ping_pkt pkt;
    int addr_len = sizeof(struct sockaddr);
    int ret, len;

    clock_t start_time = clock();
    while (((double) (clock() - start_time) / CLOCKS_PER_SEC) < RECV_TIMEOUT) {
        ret = recvfrom(sockfd, &pkt, sizeof(pkt), MSG_WAITALL, dest_addr, &addr_len);
        if (ret == -1)
            continue;

        if (pkt.hdr.type == ICMP_ECHOREPLY && pkt.hdr.un.echo.id == getpid() && pkt.hdr.un.echo.sequence == seq_no) {
            len = 0;
            printf("Ping Reply received from %s (%d bytes)\n", inet_ntoa(*(struct in_addr*)dest_addr->sa_data), ret);
            return 1;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    int sockfd, seq_no = 0;
    struct sockaddr_in dest_addr;
    struct hostent* hostptr;

    if (argc != 2) {
        printf("Usage: %s <destination_ip>\n", argv[0]);
        return 0;
    }

    bzero( &dest_addr , sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(0);
    inet_aton(argv[1], &dest_addr.sin_addr);

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Error in creating socket");
        return -1;
    }

    for (int i = 0; i < 4; i++) {
        seq_no++;
        send_ping(sockfd, (struct sockaddr *)&dest_addr, seq_no);
        if (recv_ping(sockfd, (struct sockaddr *)&dest_addr, seq_no) == 1)
            printf("Ping Successful\n");
        else
            printf("Ping Failed\n");

        sleep(1);
    }

    return 0;
}