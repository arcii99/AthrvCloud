//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/if_ether.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>

void process_packet(unsigned char*, int);
void print_tcp_packet(unsigned char*, int);
void print_udp_packet(unsigned char*, int);

int main() {
    int sock_raw;
    struct sockaddr_in saddr;
    unsigned char buffer[65536];
    int saddr_size, data_size;

    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (sock_raw < 0) {
        printf("Socket Error\n");
        return 1;
    }

    while (1) {
        saddr_size = sizeof(saddr);
        data_size = recvfrom(sock_raw, buffer, 65536, 0, (struct sockaddr*)&saddr, &saddr_size);
        if (data_size < 0) {
            printf("Recvfrom Error\n");
            return 1;
        }
        process_packet(buffer, data_size);
    }
    close(sock_raw);
    return 0;
}

void process_packet(unsigned char* buffer, int size) {
    struct iphdr* ip = (struct iphdr*)(buffer + sizeof(struct ethhdr));
    switch (ip->protocol) {
        case IPPROTO_TCP:
            print_tcp_packet(buffer, size);
            break;
        case IPPROTO_UDP:
            print_udp_packet(buffer, size);
            break;
        default:
            break;
    }
}

void print_tcp_packet(unsigned char* buffer, int size) {
    struct iphdr* ip = (struct iphdr*)(buffer + sizeof(struct ethhdr));
    unsigned short iphdrlen = ip->ihl * 4;
    struct tcphdr* tcp = (struct tcphdr*)(buffer + iphdrlen + sizeof(struct ethhdr));
    int header_size = sizeof(struct ethhdr) + iphdrlen + tcp->doff * 4;

    printf("\n\t\t-----TCP Packet-----\n");

    printf("\t\tSource Port      : %u\n", ntohs(tcp->source));
    printf("\t\tDestination Port : %u\n", ntohs(tcp->dest));
    printf("\t\tSequence Number  : %u\n", ntohl(tcp->seq));
    printf("\t\tAcknowledge Number : %u\n", ntohl(tcp->ack_seq));
    printf("\t\tHeader Length    : %d bytes\n", tcp->doff * 4);
    printf("\t\tACK Flag         : %d\n", tcp->ack);
}

void print_udp_packet(unsigned char* buffer, int size) {
    struct iphdr* ip = (struct iphdr*)(buffer + sizeof(struct ethhdr));
    unsigned short iphdrlen = ip->ihl * 4;
    struct udphdr* udp = (struct udphdr*)(buffer + iphdrlen + sizeof(struct ethhdr));
    int header_size = sizeof(struct ethhdr) + iphdrlen + sizeof(udp);

    printf("\n\t\t-----UDP Packet-----\n");

    printf("\t\tSource Port      : %u\n", ntohs(udp->source));
    printf("\t\tDestination Port : %u\n", ntohs(udp->dest));
    printf("\t\tHeader Length    : %d bytes\n", sizeof(udp));
}