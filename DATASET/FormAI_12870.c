//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define ETH_HDR_LEN 14

#define IP_HDR_LEN 20

typedef unsigned short uint16;
typedef unsigned int uint32;

struct ethhdr {
    uint8_t dst[6];
    uint8_t src[6];
    uint16_t type;
};

struct iphdr {
    uint8_t ihl : 4;
    uint8_t ver : 4;
    uint8_t tos;
    uint16_t len;
    uint16_t id;
    uint16_t offset;
    uint8_t ttl;
    uint8_t protocol;
    uint16_t checksum;
    uint8_t src[4];
    uint8_t dst[4];
};

void print_ethhdr(struct ethhdr* eth) {
    printf("Dest MAC: %02X:%02X:%02X:%02X:%02X:%02X\n", eth->dst[0], eth->dst[1], eth->dst[2], eth->dst[3], eth->dst[4], eth->dst[5]);
    printf("Src MAC: %02X:%02X:%02X:%02X:%02X:%02X\n", eth->src[0], eth->src[1], eth->src[2], eth->src[3], eth->src[4], eth->src[5]);
    printf("Type: %04X\n", ntohs(eth->type));
}

void print_iphdr(struct iphdr* ip) {
    printf("Src IP: %d.%d.%d.%d\n", ip->src[0], ip->src[1], ip->src[2], ip->src[3]);
    printf("Dst IP: %d.%d.%d.%d\n", ip->dst[0], ip->dst[1], ip->dst[2], ip->dst[3]);
    printf("Protocol: %d\n", ip->protocol);
}

void handle_packet(const uint8_t* packet, int len) {
    if (len < ETH_HDR_LEN + IP_HDR_LEN) {
        return;
    }

    struct ethhdr* eth = (struct ethhdr*)packet;
    if (ntohs(eth->type) != 0x0800) {
        return;
    }

    struct iphdr* ip = (struct iphdr*)(packet + ETH_HDR_LEN);
    print_ethhdr(eth);
    print_iphdr(ip);
}

int main(int argc, char* argv[]) {
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    uint8_t buf[1500];

    while (1) {
        int n = recv(sockfd, buf, sizeof(buf), 0);
        if (n < 0) {
            perror("recv");
            exit(1);
        }

        handle_packet(buf, n);
    }

    return 0;
}