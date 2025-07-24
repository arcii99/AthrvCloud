//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netpacket/packet.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

void print_packet_info(const u_char *packet, int len);

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[2048];
    struct sockaddr_ll addr;
    socklen_t addr_len = sizeof(addr);

    // create a raw socket to receive all packets (including those not destined for us)
    if ((sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) < 0) {
        perror("socket() failed");
        exit(1);
    }

    // bind the socket to the network interface specified on the command line
    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        exit(1);
    }
    memset(&addr, 0, sizeof(addr));
    addr.sll_family = AF_PACKET;
    addr.sll_ifindex = if_nametoindex(argv[1]);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind() failed");
        exit(1);
    }

    // receive packets and print their information
    while (1) {
        if ((n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, &addr_len)) < 0) {
            perror("recvfrom() failed");
            exit(1);
        }
        print_packet_info((u_char *)buffer, n);
    }

    return 0;
}

void print_packet_info(const u_char *packet, int len) {
    struct ethhdr *eth = (struct ethhdr *)packet;
    printf("Source MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n", eth->h_source[0], eth->h_source[1], eth->h_source[2],
           eth->h_source[3], eth->h_source[4], eth->h_source[5]);
    printf("Destination MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n", eth->h_dest[0], eth->h_dest[1], eth->h_dest[2],
           eth->h_dest[3], eth->h_dest[4], eth->h_dest[5]);

    if (ntohs(eth->h_proto) == ETH_P_IP) {
        struct iphdr *ip = (struct iphdr *)(packet + sizeof(struct ethhdr));
        printf("Source IP address: %s\n", inet_ntoa(*(struct in_addr *)&ip->saddr));
        printf("Destination IP address: %s\n", inet_ntoa(*(struct in_addr *)&ip->daddr));

        if (ip->protocol == IPPROTO_TCP) {
            struct tcphdr *tcp = (struct tcphdr *)(packet + sizeof(struct ethhdr) + sizeof(struct iphdr));
            printf("Source port: %d\n", ntohs(tcp->source));
            printf("Destination port: %d\n", ntohs(tcp->dest));
        }
    }

    printf("Packet length: %d bytes\n", len);
    printf("-----------------------------------------------\n");
}