//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

void analyze_packet(unsigned char* buffer, int size);

int main()
{
    int sock_fd;
    struct sockaddr_in server;
    unsigned char buffer[65536];
    int n_read;

    // create raw socket
    sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock_fd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // set socket options
    int one = 1;
    if (setsockopt(sock_fd, IPPROTO_IP, IP_HDRINCL, &one, sizeof(one)) < 0) {
        perror("Error setting socket options");
        return 1;
    }

    // zero out the server struct
    memset((char*) &server, 0, sizeof(server));

    // set server properties
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(0);

    // bind socket to server
    if (bind(sock_fd, (struct sockaddr*) &server, sizeof(server)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    // start monitoring
    while (1) {
        n_read = recv(sock_fd, buffer, 65536, 0);
        if (n_read < 0) {
            perror("Error receiving packet");
            continue;
        }
        analyze_packet(buffer, n_read);
    }

    return 0;
}

void analyze_packet(unsigned char* buffer, int size)
{
    // retrieve ethernet header
    struct ethhdr* eth = (struct ethhdr*) buffer;

    // retrieve ip header
    struct iphdr* ip = (struct iphdr*) (buffer + sizeof(struct ethhdr));

    // check if packet contains a tcp header
    if (ip->protocol != IPPROTO_TCP) {
        return;
    }

    // retrieve tcp header
    struct tcphdr* tcp = (struct tcphdr*) (buffer + sizeof(struct ethhdr) + sizeof(struct iphdr));

    printf("Packet Information:\n");
    printf("Source MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n", 
        eth->h_source[0], eth->h_source[1], eth->h_source[2], 
        eth->h_source[3], eth->h_source[4], eth->h_source[5]);
    printf("Destination MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n", 
        eth->h_dest[0], eth->h_dest[1], eth->h_dest[2], 
        eth->h_dest[3], eth->h_dest[4], eth->h_dest[5]);
    printf("Source IP address: %s\n", inet_ntoa(*(struct in_addr*)&ip->saddr));
    printf("Destination IP address: %s\n", inet_ntoa(*(struct in_addr*)&ip->daddr));
    printf("Source port: %u\n", ntohs(tcp->source));
    printf("Destination port: %u\n", ntohs(tcp->dest));
    printf("\n");

    return;
}