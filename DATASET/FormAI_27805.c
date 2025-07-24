//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 80        // Default HTTP port
#define PACKET_SIZE 4096      // Packet size for scanning
#define IP_HEADER_LEN 20      // Length of IP header in bytes
#define TCP_HEADER_LEN 20     // Length of TCP header in bytes
#define SCAN_TIMEOUT 3        // Timeout for each scan

// Struct for various fields in the IP header
struct iphdr {
    unsigned char ihl:4, version:4;
    unsigned char tos;
    unsigned short tot_len;
    unsigned short id;
    unsigned short frag_off;
    unsigned char ttl;
    unsigned char protocol;
    unsigned short check;
    unsigned int saddr;
    unsigned int daddr;
};

// Struct for various fields in the TCP header
struct tcphdr {
    unsigned short source;
    unsigned short dest;
    unsigned int seq;
    unsigned int ack_seq;
    unsigned char res1:4, doff:4;
    unsigned char flags;
    unsigned short window;
    unsigned short check;
    unsigned short urg_ptr;
};

// Function for computing the TCP checksum
unsigned short compute_checksum(unsigned short *ptr, int nbytes) {
    register long sum;
    unsigned short oddbyte;
    register short answer;

    sum = 0;
    while (nbytes > 1) {
        sum += *ptr++;
        nbytes -= 2;
    }
    if (nbytes == 1) {
        oddbyte = 0;
        *((unsigned char *)&oddbyte) = *(unsigned char *)ptr;
        sum += oddbyte;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = (short)~sum;

    return(answer);
}

// Function for scanning a single IP address and port
void scan_ip_port(char *ip_addr, unsigned short port_num) {
    int sockfd;
    struct sockaddr_in target;
    struct timeval timeout;
    timeout.tv_sec = SCAN_TIMEOUT;
    timeout.tv_usec = 0;

    // Create a raw socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) == -1) {
        perror("socket");
        exit(1);
    }
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    // Fill in the TCP header
    struct tcphdr tcp_hdr;
    tcp_hdr.source = htons(rand() % 65536);
    tcp_hdr.dest = htons(port_num);
    tcp_hdr.seq = rand();
    tcp_hdr.ack_seq = 0;
    tcp_hdr.res1 = 0;
    tcp_hdr.doff = 5;
    tcp_hdr.flags = 2;
    tcp_hdr.window = htons(8192);
    tcp_hdr.check = 0;
    tcp_hdr.urg_ptr = 0;

    // Fill in the IP header
    struct iphdr ip_hdr;
    ip_hdr.ihl = 5;
    ip_hdr.version = 4;
    ip_hdr.tos = 0;
    ip_hdr.tot_len = sizeof(struct iphdr) + sizeof(struct tcphdr);
    ip_hdr.id = htons(rand() % 65536);
    ip_hdr.frag_off = 0;
    ip_hdr.ttl = 64;
    ip_hdr.protocol = IPPROTO_TCP;
    ip_hdr.check = 0;
    ip_hdr.saddr = inet_addr("127.0.0.1");
    ip_hdr.daddr = inet_addr(ip_addr);

    // Construct the packet
    char packet[PACKET_SIZE];
    memcpy(&packet[0], &ip_hdr, IP_HEADER_LEN);
    memcpy(&packet[IP_HEADER_LEN], &tcp_hdr, TCP_HEADER_LEN);
    tcp_hdr.check = compute_checksum((unsigned short *)&packet, IP_HEADER_LEN + TCP_HEADER_LEN);
    memcpy(&packet[IP_HEADER_LEN], &tcp_hdr, TCP_HEADER_LEN);
    ip_hdr.check = compute_checksum((unsigned short *)&packet, IP_HEADER_LEN);
    memcpy(&packet[0], &ip_hdr, IP_HEADER_LEN);

    // Fill in the target socket address
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = ip_hdr.daddr;
    target.sin_port = tcp_hdr.dest;

    // Send the packet
    if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&target, sizeof(target)) == -1) {
        if (errno == EAGAIN) {
            printf("Port %d on %s closed.\n", port_num, ip_addr);
        } else {
            perror("sendto");
            exit(1);
        }
    } else {
        printf("Port %d on %s open.\n", port_num, ip_addr);
    }

    // Close the socket
    close(sockfd);
}

// Main function for scanning wireless network
int main() {
    printf("Enter the wireless network range (in CIDR format): ");
    char input[20];
    fgets(input, sizeof(input), stdin);

    // Parse IP range from the input string
    char *slash_pos = strchr(input, '/');
    if (slash_pos == NULL) {
        printf("Invalid input.\n");
        exit(1);
    }
    *slash_pos = '\0';
    char *ip_addr_prefix = input;
    int subnet_mask_length = atoi(slash_pos + 1);
    if (subnet_mask_length < 0 || subnet_mask_length > 32) {
        printf("Invalid input.\n");
        exit(1);
    }
    unsigned int subnet_mask = (subnet_mask_length == 0) ? 0 : ~0U << (32 - subnet_mask_length);
    unsigned int ip_range_start = ntohl(inet_addr(ip_addr_prefix)) & subnet_mask;
    unsigned int ip_range_end = ip_range_start + (~subnet_mask & 0xffffffff);

    // Start scanning the wireless network
    for (unsigned int i = ip_range_start; i <= ip_range_end; i++) {
        char ip_addr[20];
        snprintf(ip_addr, sizeof(ip_addr), "%d.%d.%d.%d", (i >> 24) & 0xff, (i >> 16) & 0xff, (i >> 8) & 0xff, i & 0xff);

        printf("Scanning %s...\n", ip_addr);
        for (unsigned short j = 1; j <= 1000; j++) {
            scan_ip_port(ip_addr, j);
        }
    }

    return 0;
}