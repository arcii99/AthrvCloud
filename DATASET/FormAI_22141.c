//FormAI DATASET v1.0 Category: Firewall ; Style: safe
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <time.h>

#define MAX_PACKET_SIZE 65536
#define MAX_IP_HDR_SIZE 84
#define ICMP_HDR_SIZE 8

// Structure of IP header
typedef struct {
    unsigned char  iph_ihl:4, iph_ver:4;
    unsigned char  iph_tos;
    unsigned short iph_len;
    unsigned short iph_ident;
    unsigned short iph_flag_and_offset;
    unsigned char  iph_ttl;
    unsigned char  iph_protocol;
    unsigned short iph_checksum;
    struct in_addr iph_sourceip;
    struct in_addr iph_destip;
}   ip_header;

int main(int argc, char **argv)
{
    int sockfd;
    char buffer[MAX_PACKET_SIZE];
    memset(buffer, 0, MAX_PACKET_SIZE);

    if((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Error in creating socket");
        exit(1);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    memset(addr.sin_zero, '\0', sizeof(addr.sin_zero));

    if(bind(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr)) < 0) {
        perror("Error in binding socket");
        exit(1);
    }

    while(1) {
        ssize_t length = recv(sockfd, buffer, MAX_PACKET_SIZE, 0);
        if(length < 0) {
            perror("Error in reading packet");
            exit(1);
        }

        ip_header *ip_hdr = (ip_header *) buffer;

        if (ip_hdr->iph_ttl <= 1) {
            continue;
        }

        // Block incoming packet from specific IP address
        if (ip_hdr->iph_sourceip.s_addr == inet_addr("192.168.0.100")) {
            printf("Blocked packet from IP address: %s\n", inet_ntoa(ip_hdr->iph_sourceip));
            continue;
        }

        // Block incoming ICMP packets
        if (ip_hdr->iph_protocol == IPPROTO_ICMP) {
            printf("Blocked ICMP packet\n");
            continue;
        }

        // Block incoming packets with invalid IP header length
        if (ip_hdr->iph_ihl < 5 || ip_hdr->iph_ihl > 15) {
            printf("Blocked packet with invalid IP header length\n");
            continue;
        }

        // Block incoming packets with invalid source IP address
        if (ip_hdr->iph_sourceip.s_addr == INADDR_ANY || (ip_hdr->iph_sourceip.s_addr & htonl(0xf0000000)) == htonl(0xe0000000)) {
            printf("Blocked packet with invalid source IP address: %s\n", inet_ntoa(ip_hdr->iph_sourceip));
            continue;
        }

        // Generate random checksum to check incoming packets
        if (ip_hdr->iph_checksum == htons(0xFFFF)) {
            time_t t;
            srand((unsigned) time(&t));
            int random_checksum = rand() % 65535;
            ip_hdr->iph_checksum = htons(random_checksum);
        }
        sendto(sockfd, buffer, length, 0, (struct sockaddr *)&addr, sizeof(struct sockaddr));
    }

    return 0;
}