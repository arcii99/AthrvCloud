//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/ip_icmp.h>

#define MAX_PACKET_SIZE 65535

// Calculate the checksum of a packet
unsigned short calculate_checksum(unsigned short *ptr, int length) {
    unsigned int sum = 0;
    while (length > 1) {
        sum += *ptr++;
        length -= 2;
    }
    if (length == 1) {
        sum += *(unsigned char *)ptr;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

// Send an ICMP echo request packet to the specified IP address
void send_ping_request(int sock, struct sockaddr_in *addr, int packet_id, int sequence) {
    char packet[MAX_PACKET_SIZE];
    memset(packet, 0, MAX_PACKET_SIZE);

    struct icmp *icmp_header = (struct icmp *)packet;
    icmp_header->icmp_type = ICMP_ECHO; // Echo request
    icmp_header->icmp_code = 0; // Always 0
    icmp_header->icmp_id = htons(packet_id); // Packet ID
    icmp_header->icmp_seq = htons(sequence); // Packet sequence number
    icmp_header->icmp_cksum = 0; // Set checksum to 0 before calculating
    icmp_header->icmp_cksum = calculate_checksum((unsigned short *)icmp_header, sizeof(struct icmp));

    sendto(sock, packet, sizeof(struct icmp), 0, (struct sockaddr *)addr, sizeof(struct sockaddr_in));
}

// Receive and parse an ICMP echo response packet
int receive_ping_response(int sock, struct sockaddr_in *addr, int packet_id, int sequence) {
    char buffer[MAX_PACKET_SIZE];
    memset(buffer, 0, MAX_PACKET_SIZE);

    struct sockaddr_in resp_addr;
    socklen_t resp_addr_len = sizeof(resp_addr);

    int resp_size = recvfrom(sock, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *)&resp_addr, &resp_addr_len);
    if (resp_size < 0) {
        perror("recvfrom");
        return -1;
    }

    struct iphdr *ip_header = (struct iphdr *)buffer;
    int ip_header_size = ip_header->ihl * 4;
    struct icmp *icmp_header = (struct icmp *)(buffer + ip_header_size);

    if (icmp_header->icmp_type == ICMP_ECHOREPLY && icmp_header->icmp_id == htons(packet_id) && icmp_header->icmp_seq == htons(sequence)) {
        return (int)(resp_addr.sin_addr.s_addr);
    }

    return -1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];

    // Create a raw socket to send and receive ICMP packets
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set socket options to allow broadcast and set TTL to 64
    int enable_broadcast = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &enable_broadcast, sizeof(enable_broadcast)) < 0) {
        perror("setsockopt");
        return 1;
    }
    int ttl = 64;
    if (setsockopt(sock, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0) {
        perror("setsockopt");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, ip_address, &(addr.sin_addr)) != 1) {
        perror("inet_pton");
        return 1;
    }

    int packet_count = 4;
    int packet_size = sizeof(struct icmp);
    int sequence = 0;

    printf("PING %s:\n", ip_address);
    for (int i = 0; i < packet_count; i++) {
        sequence++;
        send_ping_request(sock, &addr, i, sequence);

        int response_address = receive_ping_response(sock, &addr, i, sequence);
        if (response_address != -1) {
            printf("Ping Response from %s\n", inet_ntoa(*(struct in_addr *)&response_address));
        } else {
            printf("Ping Request Timeout\n");
        }

        sleep(1); // Wait 1 second between packets
    }

    close(sock);

    return 0;
}