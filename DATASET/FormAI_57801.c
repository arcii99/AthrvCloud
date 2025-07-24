//FormAI DATASET v1.0 Category: Firewall ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SOURCE_IP "127.0.0.1"   // The source IP address to be blocked
#define PORT 22                  // The port number being used

int main(int argc, char **argv)
{
    // Create socket
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock < 0)
    {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int one = 1;
    const int *val = &one;
    if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0)
    {
        perror("Cannot set IP_HDRINCL option");
        exit(EXIT_FAILURE);
    }

    // Set up sockaddr_in structure
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
    sin.sin_addr.s_addr = inet_addr(SOURCE_IP);

    // Initialize buffer for packet
    char packet[4096];
    memset(packet, 0, sizeof(packet));

    // Initialize IP header
    struct iphdr *ip_header = (struct iphdr *) packet;
    ip_header->version = 4;
    ip_header->ihl = 5;
    ip_header->ttl = 20;
    ip_header->protocol = IPPROTO_TCP;
    ip_header->saddr = sin.sin_addr.s_addr;
    ip_header->daddr = sin.sin_addr.s_addr;

    // Initialize TCP header
    struct tcphdr *tcp_header = (struct tcphdr *) (packet + sizeof(struct iphdr));
    tcp_header->source = htons(5678);
    tcp_header->dest = htons(PORT);
    tcp_header->doff = 5;
    tcp_header->syn = 1;
    tcp_header->window = htons(64240);

    // Calculate IP header checksum
    ip_header->check = 0;
    ip_header->check = htons(~(ip_header->check));

    // Send packet
    if (sendto(sock, packet, sizeof(struct iphdr) + sizeof(struct tcphdr), 0, (struct sockaddr *) &sin, sizeof(sin)) < 0)
    {
        perror("sendto failed");
        exit(EXIT_FAILURE);
    }

    printf("Packet sent! %s:%d -> %s:%d\n", SOURCE_IP, 5678, SOURCE_IP, PORT);

    // Close socket
    close(sock);

    return 0;
}