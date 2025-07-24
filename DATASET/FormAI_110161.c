//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

#define BUFFER_SIZE 1024

void parse_packet(unsigned char*, int);

int main() {
    int raw_socket, len;
    unsigned char buffer[BUFFER_SIZE];

    if ((raw_socket = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    while (1) {
        len = recvfrom(raw_socket, buffer, BUFFER_SIZE, 0, NULL, NULL);
        
        if (len < 0) {
            perror("recvfrom");
            continue;
        }

        parse_packet(buffer, len);
    } 

    close(raw_socket);
    return 0;
}

void parse_packet(unsigned char* buffer, int len) {
    struct iphdr *iph = (struct iphdr*)buffer;
    unsigned short iphdr_len = iph->ihl * 4;

    if (iph->protocol == IPPROTO_TCP) {
        struct tcphdr *tcph = (struct tcphdr*)(buffer + iphdr_len);

        printf("Source IP: %s\n", inet_ntoa(*(struct in_addr*)&iph->saddr));
        printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr*)&iph->daddr));
        printf("Source Port: %d\n", ntohs(tcph->source));
        printf("Destination Port: %d\n", ntohs(tcph->dest));

        unsigned char *payload = buffer + iphdr_len + tcph->doff * 4;
        int payload_len = len - iphdr_len - tcph->doff * 4;

        printf("Payload:\n");
        for (int i = 0; i < payload_len; i++) {
            printf("%.2x ", *(payload+i));
        }
        printf("\n\n");
    } else if (iph->protocol == IPPROTO_UDP) {
        struct udphdr *udph = (struct udphdr*)(buffer + iphdr_len);

        printf("Source IP: %s\n", inet_ntoa(*(struct in_addr*)&iph->saddr));
        printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr*)&iph->daddr));
        printf("Source Port: %d\n", ntohs(udph->source));
        printf("Destination Port: %d\n", ntohs(udph->dest));

        unsigned char *payload = buffer + iphdr_len + sizeof(struct udphdr);
        int payload_len = len - iphdr_len - sizeof(struct udphdr);

        printf("Payload:\n");
        for (int i = 0; i < payload_len; i++) {
            printf("%.2x ", *(payload+i));
        }
        printf("\n\n");
    } else {
        printf("Not a TCP/UDP packet.\n\n");
    }
}