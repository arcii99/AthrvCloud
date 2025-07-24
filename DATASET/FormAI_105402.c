//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>

#define BUFFER_SIZE 65536

struct sockaddr_in source, dest;
int tcp_packets = 0, udp_packets = 0, icmp_packets = 0, total_packets = 0;

int map_topology() {
    int sockfd, data_size, i;
    struct sockaddr saddr;
    char buffer[BUFFER_SIZE];

    // Create a raw socket that listens to all packets
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);

    if (sockfd < 0) {
        perror("Socket error");
        return 1;
    }

    // Receive all the packets
    for (;;) {
        memset(buffer, 0, BUFFER_SIZE);
        data_size = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, &saddr, (socklen_t *) &saddr);

        if (data_size < 0) {
            perror("Receive error");
            return 1;
        }

        // Extract the IP header and payload
        struct iphdr *ip_header = (struct iphdr *) buffer;
        unsigned short ip_hdr_len = ip_header->ihl * 4;

        struct tcphdr *tcp_header = (struct tcphdr *) (buffer + ip_hdr_len);
        unsigned short tcp_hdr_len = tcp_header->doff * 4;

        // Get the source and destination IP addresses
        memset(&source, 0, sizeof(source));
        source.sin_addr.s_addr = ip_header->saddr;

        memset(&dest, 0, sizeof(dest));
        dest.sin_addr.s_addr = ip_header->daddr;

        // Print the information about the packet
        printf("Packet #%d\n", total_packets);
        printf("Source IP Address: %s\n", inet_ntoa(source.sin_addr));
        printf("Destination IP Address: %s\n", inet_ntoa(dest.sin_addr));

        // Update counters based on type of packet
        if (ip_header->protocol == IPPROTO_TCP) {
            tcp_packets++;
        } else if (ip_header->protocol == IPPROTO_UDP) {
            udp_packets++;
        } else if (ip_header->protocol == IPPROTO_ICMP) {
            icmp_packets++;
        }

        total_packets++;

        printf("Total packets processed: %d\n", total_packets);
        printf("TCP packets: %d\n", tcp_packets);
        printf("UDP packets: %d\n", udp_packets);
        printf("ICMP packets: %d\n", icmp_packets);
        printf("\n");
    }

    return 0;
}

int main() {
    map_topology();
    return 0;
}