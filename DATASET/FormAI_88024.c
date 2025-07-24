//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <unistd.h>

void packet_handler(unsigned char *buffer, int size);

int main()
{
    int raw_socket;
    struct sockaddr_in server;
    unsigned char buffer[65536];

    // Create raw socket
    raw_socket = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (raw_socket < 0)
    {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options to receive all packets
    int one = 1;
    const int *val = &one;
    if (setsockopt(raw_socket, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0)
    {
        perror("Error setting socket option");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port 0 to receive all incoming packets
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = 0;
    if (bind(raw_socket, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }
    printf("Packet monitoring started...\n");

    // Receive packets and parse them
    while (1)
    {
        int buffer_size = recv(raw_socket, buffer, 65536, 0);
        if (buffer_size < 0)
        {
            perror("Error receiving packet");
            exit(EXIT_FAILURE);
        }
        packet_handler(buffer, buffer_size);
    }

    return 0;
}

void packet_handler(unsigned char *buffer, int size)
{
    struct iphdr *ip = (struct iphdr *)buffer;
    if (ip->protocol == IPPROTO_TCP) // Check if the packet is TCP
    {
        struct tcphdr *tcp = (struct tcphdr *)(buffer + ip->ihl * 4); // Calculate the TCP header offset

        // Print source IP, source port, destination IP, destination port, and sequence number
        printf("Source IP: %s | ", inet_ntoa((struct in_addr){ip->saddr}));
        printf("Source port: %d | ", ntohs(tcp->source));
        printf("Destination IP: %s | ", inet_ntoa((struct in_addr){ip->daddr}));
        printf("Destination port: %d | ", ntohs(tcp->dest));
        printf("Sequence Number: %u\n", ntohl(tcp->seq));
    }
}