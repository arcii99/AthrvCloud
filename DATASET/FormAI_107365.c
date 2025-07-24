//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define BUFFER_SIZE 65536

void packet_handler(unsigned char*, int);

int main() {
    int packet_socket;
    struct sockaddr_in address;
    unsigned char buffer[BUFFER_SIZE];
    int address_size = sizeof(address);

    // Create raw socket to receive packets
    packet_socket = socket(AF_INET, SOCK_RAW, htons(ETH_P_ALL));
    if (packet_socket < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    printf("Packet sniffing initiated...\n");

    while (1) {
        recvfrom(packet_socket, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&address, &address_size);
        packet_handler(buffer, address_size);
    }

    return 0;
}

void packet_handler(unsigned char* buffer, int size) {
    struct iphdr* ip_header = (struct iphdr*)(buffer + sizeof(struct ethhdr));
    struct tcphdr* tcp_header = (struct tcphdr*)(buffer + sizeof(struct ethhdr) + sizeof(struct iphdr));
    char source_ip[16];
    char dest_ip[16];

    // Convert source and destination IP from network format to string format
    snprintf(source_ip, 16, "%pI4", &ip_header->saddr);
    snprintf(dest_ip, 16, "%pI4", &ip_header->daddr);

    // Print packet details
    printf("\nPacket Received!");
    printf("\n===============================");
    printf("\nSource IP: %s", source_ip);
    printf("\nDestination IP: %s", dest_ip);
    printf("\nSource Port: %d", ntohs(tcp_header->source));
    printf("\nDestination Port: %d", ntohs(tcp_header->dest));
    printf("\nSequence Number: %u", ntohl(tcp_header->seq));
    printf("\nAcknowledgment Number: %u\n", ntohl(tcp_header->ack_seq));

    // Check for HTTP Packet
    if (ntohs(tcp_header->dest) == 80) {
        int header_length = sizeof(struct ethhdr) + sizeof(struct iphdr) + sizeof(struct tcphdr);
        int payload_length = size - header_length;
        unsigned char* payload = buffer + header_length;
        if (payload_length > 0) {
            printf("===============================");
            printf("\nHTTP Payload: ");
            for (int i = 0; i < payload_length; i++) {
                printf("%c", isprint(payload[i]) ? payload[i] : '.');
            }
        }
    }
}