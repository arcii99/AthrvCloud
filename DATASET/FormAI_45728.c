//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <net/ethernet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 65535

int main() {
    // Create a raw socket to listen for network packets
    int sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    
    // Make sure the socket was created successfully
    if (sock < 0) {
        perror("Failed to create socket");
        exit(1);
    }
    
    // Buffer to store incoming packets
    uint8_t buffer[MAX_PACKET_SIZE];
    
    while (1) {
        // Receive a packet
        ssize_t packet_size = recvfrom(sock, buffer, MAX_PACKET_SIZE, 0, NULL, NULL);
        
        // Make sure the packet was received successfully
        if (packet_size < 0) {
            perror("Failed to receive packet");
            continue;
        }
        
        // Parse the packet header
        struct ethhdr* eth_header = (struct ethhdr*)buffer;
        
        // Check if the packet is an IP packet
        if (ntohs(eth_header->h_proto) != ETH_P_IP) {
            continue;
        }
        
        // Parse the IP header
        struct iphdr* ip_header = (struct iphdr*)(buffer + sizeof(struct ethhdr));
        
        // Check if the packet contains TCP data
        if (ip_header->protocol != IPPROTO_TCP) {
            continue;
        }
        
        // Calculate the length of the IP header (in 32-bit words)
        uint8_t ip_header_length = ip_header->ihl * 4;
        
        // Parse the TCP header
        struct tcphdr* tcp_header = (struct tcphdr*)(buffer + sizeof(struct ethhdr) + ip_header_length);
        
        // Print information about the packet
        printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *)&(ip_header->saddr)));
        printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr *)&(ip_header->daddr)));
        printf("Source Port: %u\n", ntohs(tcp_header->source));
        printf("Destination Port: %u\n", ntohs(tcp_header->dest));
    }
    
    // Close the socket
    close(sock);
    
    return 0;
}