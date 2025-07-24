//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

int main(int argc, char *argv[]) {
    int sock_raw;
    int read_size;
    struct sockaddr_in saddr;
    struct in_addr in;
    unsigned char buffer[65536];

    // Create a raw socket
    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);

    if(sock_raw < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Loop through packets
    while(1) {
        memset(buffer, 0, sizeof(buffer));
        read_size = recvfrom(sock_raw, buffer, 65536, 0, (struct sockaddr *)&saddr, (socklen_t *)&saddr);

        if(read_size < 0) {
            perror("Error receiving packet");
            return 1;
        }

        // Extract IP header and TCP header
        struct iphdr *iph = (struct iphdr *)buffer;
        struct tcphdr *tcph = (struct tcphdr *)(buffer + (iph->ihl * 4));

        // Convert IP address to human-readable format
        in.s_addr = iph->saddr;
        char *src_ip = inet_ntoa(in);
        in.s_addr = iph->daddr;
        char *dst_ip = inet_ntoa(in);

        // Print packet information
        printf("Packet from %s:%d to %s:%d\n", src_ip, ntohs(tcph->source), dst_ip, ntohs(tcph->dest));
    }

    return 0;
}