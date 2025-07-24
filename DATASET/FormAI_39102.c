//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>

void print_packet(unsigned char* buffer, int size) {
    printf("----------------------------------------------\n");
    printf("Received packet of size %d\n", size);
    struct ethhdr* eth = (struct ethhdr*)buffer;
    printf("Ethernet Header\n");
    printf("\tSource MAC Address: %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n",
            eth->h_source[0], eth->h_source[1], eth->h_source[2],
            eth->h_source[3], eth->h_source[4], eth->h_source[5]);
    printf("\tDestination MAC Address: %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n",
            eth->h_dest[0], eth->h_dest[1], eth->h_dest[2],
            eth->h_dest[3], eth->h_dest[4], eth->h_dest[5]);
    printf("\tProtocol: %d\n", eth->h_proto);

    // Now parse IP header
    struct iphdr* ip = (struct iphdr*)(buffer + sizeof(struct ethhdr));
    printf("IP Header\n");
    printf("\tSource IP Address: %s\n", inet_ntoa(*(struct in_addr*)&ip->saddr));
    printf("\tDestination IP Address: %s\n", inet_ntoa(*(struct in_addr*)&ip->daddr));
    printf("\tProtocol: %d\n", ip->protocol);

    // Now parse TCP/UDP header
    unsigned short iphdrlen = ip->ihl*4;
    void* payload = buffer + sizeof(struct ethhdr) + iphdrlen;
    int payload_size = size - sizeof(struct ethhdr) - iphdrlen;
    if (ip->protocol == IPPROTO_TCP) {
        printf("TCP Header\n");
        // parse TCP header...
    } else if (ip->protocol == IPPROTO_UDP) {
        printf("UDP Header\n");
        // parse UDP header...
    } else {
        printf("Payload\n");
        // simply printing the payload
        printf("\tData: %.*s\n", payload_size, (char*)payload);
    }

    printf("----------------------------------------------\n");
}

int main() {
    int sock = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock < 0) {
        perror("Error in creating socket:");
        return 1;
    }

    unsigned char buffer[65536];
    int length;

    while (1) {
        length = recvfrom(sock, buffer, 65536, 0, NULL, NULL);
        if (length < 0) {
            perror("Error in receiving data:");
            return 1;
        }
        print_packet(buffer, length);
    }

    return 0;
}