//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define MAX_PACKET_SIZE 65536
#define ETHER_ADDR_LEN 6

struct sniff_ethernet {
    u_char ether_dhost[ETHER_ADDR_LEN];
    u_char ether_shost[ETHER_ADDR_LEN];
    u_short ether_type;
};

struct sniff_ip {
    u_char ip_vhl;
    u_char ip_tos;
    u_short ip_len;
    u_short ip_id;
    u_short ip_off;
    #define IP_RF 0x8000
    #define IP_DF 0x4000
    #define IP_MF 0x2000
    #define IP_OFFMASK 0x1fff
    u_char ip_ttl;
    u_char ip_p;
    u_short ip_sum;
    struct in_addr ip_src,ip_dst;
};

struct sniff_udp {
    u_short udp_srcport;
    u_short udp_dstport;
    u_short udp_len;
    u_short udp_sum;
};

void print_ethernet(const u_char *packet) {
    struct sniff_ethernet *ethernet;
    ethernet = (struct sniff_ethernet*)(packet);
    printf("\t\tEthernet Header\n");
    printf("\t\tDestination MAC: %02X:%02X:%02X:%02X:%02X:%02X\n",
            ethernet->ether_dhost[0], ethernet->ether_dhost[1],
            ethernet->ether_dhost[2], ethernet->ether_dhost[3],
            ethernet->ether_dhost[4], ethernet->ether_dhost[5]);
    printf("\t\tSource MAC: %02X:%02X:%02X:%02X:%02X:%02X\n",
            ethernet->ether_shost[0], ethernet->ether_shost[1],
            ethernet->ether_shost[2], ethernet->ether_shost[3],
            ethernet->ether_shost[4], ethernet->ether_shost[5]);
    printf("\t\tEthernet Type: %hu\n", ethernet->ether_type);
}

void print_ip(const u_char *packet) {
    struct sniff_ip *ip;
    ip = (struct sniff_ip*)(packet);
    printf("\t\tIP Header\n");
    printf("\t\tSource IP: %s\n", inet_ntoa(ip->ip_src));
    printf("\t\tDestination IP: %s\n", inet_ntoa(ip->ip_dst));
}

void print_udp(const u_char *packet) {
    struct sniff_udp *udp;
    udp = (struct sniff_udp*)(packet);
    printf("\t\tUDP Header\n");
    printf("\t\tSource Port: %hu\n", udp->udp_srcport);
    printf("\t\tDestination Port: %hu\n", udp->udp_dstport);
    printf("\t\tUDP Length: %hu\n", udp->udp_len);
    printf("\t\tUDP Checksum: %hu\n", udp->udp_sum);
}

int main(int argc, char **argv) {
    int sockfd, result;
    struct sockaddr_in addr;
    char *dest_ip;
    unsigned short int port;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip_addr> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    dest_ip = argv[1];
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(dest_ip);
    addr.sin_port = htons(port);

    char packet[MAX_PACKET_SIZE], recv_packet[MAX_PACKET_SIZE];
    memset(packet, 0, sizeof(packet));
    packet[0] = 'H'; packet[1] = 'i';

    result = sendto(sockfd, packet, strlen(packet), 0, (struct sockaddr *)&addr, sizeof(addr));
    if (result <= 0) {
        fprintf(stderr, "Error sending packet: %s\n", strerror(errno));
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    memset(recv_packet, 0, sizeof(recv_packet));
    struct sockaddr_in recv_addr;
    socklen_t addr_len = sizeof(recv_addr);
    result = recvfrom(sockfd, recv_packet, MAX_PACKET_SIZE, 0, (struct sockaddr *)&recv_addr, &addr_len);
    if (result <= 0) {
        fprintf(stderr, "Error receiving packet: %s\n", strerror(errno));
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    print_ethernet(recv_packet);
    print_ip(recv_packet+sizeof(struct sniff_ethernet));
    print_udp(recv_packet+sizeof(struct sniff_ethernet)+sizeof(struct sniff_ip));

    close(sockfd);

    exit(EXIT_SUCCESS);
}