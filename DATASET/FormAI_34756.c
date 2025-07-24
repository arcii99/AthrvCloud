//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

void process_packet(unsigned char* buffer, int size);

int main()
{
    int packet_socket;
    struct sockaddr_in addr;

    // Create socket
    packet_socket = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (packet_socket == -1)
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket to interface
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_PACKET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(0);

    if (bind(packet_socket, (struct sockaddr*) &addr, sizeof(addr)) == -1)
    {
        perror("Error binding socket to interface ");
        exit(EXIT_FAILURE);
    }

    // start listening for packets
    while(1)
    {
        struct sockaddr saddr;
        int addrlen = sizeof(saddr);
        unsigned char buffer[65536];

        int data_size = recvfrom(packet_socket, buffer, sizeof(buffer), 0, &saddr, (socklen_t*)&addrlen);
        if (data_size > 0)
        {
            process_packet(buffer, data_size);
        }
    }

    close(packet_socket);
    return 0;
}

void process_packet(unsigned char* buffer, int size)
{
    struct ethhdr* eth = (struct ethhdr*)buffer;
    if (ntohs(eth->h_proto) == ETH_P_IP)
    {
        struct iphdr* ip = (struct iphdr*)(buffer + sizeof(struct ethhdr));
        switch(ip->protocol)
        {
            case IPPROTO_TCP:
                struct tcphdr* tcp = (struct tcphdr*)(buffer + sizeof(struct ethhdr) + sizeof(struct iphdr));
                printf("TCP packet from %s:%d to %s:%d\n", inet_ntoa((struct in_addr){ip->saddr}), ntohs(tcp->source), inet_ntoa((struct in_addr){ip->daddr}), ntohs(tcp->dest));
                break;
            case IPPROTO_UDP:
                struct udphdr* udp = (struct udphdr*)(buffer + sizeof(struct ethhdr) + sizeof(struct iphdr));
                printf("UDP packet from %s:%d to %s:%d\n", inet_ntoa((struct in_addr){ip->saddr}), ntohs(udp->source), inet_ntoa((struct in_addr){ip->daddr}), ntohs(udp->dest));
                break;
            default:
                break;
        }
    }
}