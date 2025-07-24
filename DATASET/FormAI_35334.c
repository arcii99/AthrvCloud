//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Claude Shannon
# include <stdio.h>
# include <stdlib.h>
# include <arpa/inet.h>
# include <netinet/ip.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <sys/types.h>

struct ip_header {
    unsigned int ip_head_len : 4;
    unsigned int ip_version : 4;
    unsigned char ip_service_type;
    unsigned short int ip_total_len;
    unsigned short int ip_id;
    unsigned short int ip_flags;
    unsigned char ip_frag_offset;
    unsigned char ip_ttl;
    unsigned char ip_protocol;
    unsigned short int ip_checksum;
    unsigned int ip_src_addr;
    unsigned int ip_dest_addr;
};

void process_packet(unsigned char *buffer, int size) {
    struct ip_header *ip = (struct ip_header *) buffer;

    if (ip->ip_protocol == IPPROTO_TCP && size > sizeof(struct ip_header)) {
        unsigned char *tcp_packet = buffer + sizeof(struct ip_header);
        int tcp_packet_size = size - sizeof(struct ip_header);
        
        // Process TCP Packet
        // ...
    }
    else if (ip->ip_protocol == IPPROTO_UDP && size > sizeof(struct ip_header)) {
        unsigned char *udp_packet = buffer + sizeof(struct ip_header);
        int udp_packet_size = size - sizeof(struct ip_header);
        
        // Process UDP Packet
        // ...
    }
}

int main() {
    int sockfd, n;
    unsigned char buffer[65536];

    // Create raw socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Set socket options
    int one = 1;
    const int *val = &one;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0) {
        perror("setsockopt");
        return 1;
    }

    // Receive packets
    while (1) {
        printf("Waiting for packet...\n");
        n = recvfrom(sockfd, buffer, 65536, 0, NULL, NULL);
        if (n < 0) {
            perror("recvfrom");
            return 1;
        }

        printf("Received packet of size %d\n", n);
        process_packet(buffer, n);
    }

    return 0;
}