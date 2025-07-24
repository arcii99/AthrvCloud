//FormAI DATASET v1.0 Category: Firewall ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ip_header {
    unsigned char version;
    unsigned char header_len;
    unsigned short service_field;
    unsigned short total_len;
    unsigned short id;
    unsigned short flags;
    unsigned char time_to_live;
    unsigned char protocol;
    unsigned short header_checksum;
    unsigned int source_addr;
    unsigned int dest_addr;
};

struct tcp_header {
    unsigned short source_port;
    unsigned short dest_port;
    unsigned int seq_num;
    unsigned int ack_num;
    unsigned short flags;
    unsigned short window;
    unsigned short checksum;
    unsigned short urgent;
};

int main() {
    const char* blacklisted_ips[] = {"192.168.0.1", "10.0.0.2", "172.16.0.3"};
    const int num_blacklisted_ips = sizeof(blacklisted_ips) / sizeof(blacklisted_ips[0]);
    char input_buffer[1024];
    struct ip_header* ip_hdr;
    struct tcp_header* tcp_hdr;
    unsigned int source_ip = 0;
    unsigned int dest_ip = 0;
    unsigned short source_port = 0;
    unsigned short dest_port = 0;

    while (fgets(input_buffer, sizeof(input_buffer), stdin) != NULL) {
        // Parse input into IP and TCP headers
        ip_hdr = (struct ip_header*)input_buffer;
        tcp_hdr = (struct tcp_header*)(input_buffer + sizeof(struct ip_header));

        // Extract source and destination IP addresses and ports
        source_ip = ntohl(ip_hdr->source_addr);
        dest_ip = ntohl(ip_hdr->dest_addr);
        source_port = ntohs(tcp_hdr->source_port);
        dest_port = ntohs(tcp_hdr->dest_port);

        // Check if source or destination IP is blacklisted
        for (int i = 0; i < num_blacklisted_ips; i++) {
            if (source_ip == inet_addr(blacklisted_ips[i])) {
                printf("Source IP address %s is blacklisted\n", blacklisted_ips[i]);
                break;
            }
            if (dest_ip == inet_addr(blacklisted_ips[i])) {
                printf("Destination IP address %s is blacklisted\n", blacklisted_ips[i]);
                break;
            }
        }

        // Block traffic to certain ports
        if (dest_port == 80 || dest_port == 443) {
            printf("HTTP/HTTPS traffic to port %d is blocked\n", dest_port);
            continue;
        }

        // Allow all other traffic
        printf("Traffic allowed from %d.%d.%d.%d:%d to %d.%d.%d.%d:%d\n",
            (source_ip >> 24) & 0xFF, (source_ip >> 16) & 0xFF,
            (source_ip >> 8) & 0xFF, source_ip & 0xFF,
            source_port,
            (dest_ip >> 24) & 0xFF, (dest_ip >> 16) & 0xFF,
            (dest_ip >> 8) & 0xFF, dest_ip & 0xFF,
            dest_port);
    }

    return 0;
}