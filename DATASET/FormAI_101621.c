//FormAI DATASET v1.0 Category: Network Ping Test ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>
#include <netinet/ip_icmp.h>

#define PACKET_SIZE 4096
#define PORT_NO 0
#define WAIT_TIME 10

int ping(int sockfd, struct sockaddr_in destination_addr);

unsigned short checksum(void *b, int len);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <IP address or URL>\n", argv[0]);
        exit(1);
    }

    char *destination_host = argv[1];
    struct sockaddr_in destination_addr;
    int sockfd;
    memset(&destination_addr, 0, sizeof(destination_addr));

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0)
    {
        printf("Failed to create socket.\n");
        exit(1);
    }

    destination_addr.sin_family = AF_INET;
    destination_addr.sin_port = htons(PORT_NO);
    destination_addr.sin_addr.s_addr = inet_addr(destination_host);

    printf("Pinging %s ...\n", destination_host);
    printf("--------------------------\n");

    int i;
    for (i = 0; i < 5; i++) // Ping 5 times
    {
        int ping_result = ping(sockfd, destination_addr);
        if (ping_result == -1)
        {
            printf("Ping error.\n");
        }
        else
        {
            printf("Ping reply received from %s in %d ms.\n", destination_host, ping_result);
        }

        sleep(1);
    }

    close(sockfd);
    printf("--------------------------\n");
    printf("Ping test complete.\n");

    return 0;
}

int ping(int sockfd, struct sockaddr_in destination_addr)
{
    struct timeval tv;
    tv.tv_sec = WAIT_TIME;
    tv.tv_usec = 0;

    char packet[PACKET_SIZE];
    struct icmp *icmp_hdr = (struct icmp *)packet;

    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = htons(getpid());
    icmp_hdr->icmp_seq = 0;
    memset(icmp_hdr->icmp_data, 0xa5, PACKET_SIZE - sizeof(struct icmp));
    icmp_hdr->icmp_cksum = checksum(icmp_hdr, PACKET_SIZE);

    int send_result = sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)&destination_addr, sizeof(destination_addr));
    if (send_result < 0)
    {
        return -1;
    }

    char receive_packet[PACKET_SIZE];
    struct sockaddr_in receive_addr;
    socklen_t receive_addr_len = sizeof(receive_addr);
    int receive_result = recvfrom(sockfd, receive_packet, PACKET_SIZE, 0, (struct sockaddr *)&receive_addr, &receive_addr_len);
    if (receive_result < 0)
    {
        return -1;
    }

    struct ip *ip_hdr = (struct ip *)receive_packet;
    unsigned int ip_hdr_len = ip_hdr->ip_hl << 2;
    struct icmp *received_icmp_hdr = (struct icmp *)(receive_packet + ip_hdr_len);
    unsigned int received_icmp_hdr_len = receive_result - ip_hdr_len;

    if (received_icmp_hdr->icmp_type == ICMP_ECHOREPLY && received_icmp_hdr_len >= 8)
    {
        struct timeval *tv_send = (struct timeval *)received_icmp_hdr->icmp_data;
        struct timeval tv_receive;
        gettimeofday(&tv_receive, NULL);

        int round_trip_time = (tv_receive.tv_sec - tv_send->tv_sec) * 1000 + (tv_receive.tv_usec - tv_send->tv_usec) / 1000;
        return round_trip_time;
    }
    else
    {
        return -1;
    }
}

unsigned short checksum(void *b, int len)
{
    unsigned short *buf = (unsigned short *)b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
    {
        sum += *buf++;
    }

    if (len == 1)
    {
        sum += *(unsigned char *)buf;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}