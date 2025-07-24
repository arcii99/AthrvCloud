//FormAI DATASET v1.0 Category: Firewall ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

/**
 * A firewall program that blocks incoming and outgoing connections based 
 * on a set of predefined rules. The program operates on the TCP layer of the 
 * network protocol stack.
 */

#define ALLOW 1
#define DENY 0

typedef struct firewall_rule_t {
    struct in_addr src_ip;      // Source IP address
    struct in_addr dst_ip;      // Destination IP address
    u_short src_port_min;       // Minimum source port number
    u_short src_port_max;       // Maximum source port number
    u_short dst_port_min;       // Minimum destination port number
    u_short dst_port_max;       // Maximum destination port number
    int action;                 // Action to be taken (ALLOW or DENY)
} firewall_rule_t;

firewall_rule_t rules[] = {
    { {0x0a000001}, {0xffffffff}, 0, 65535, 0, 65535, ALLOW },    // Allow all outgoing traffic
    { {0x00000000}, {0xffffffff}, 0, 65535, 80, 80, DENY },       // Block incoming traffic to port 80
    { {0x0a000001}, {0xffffffff}, 1024, 65535, 0, 65535, ALLOW }  // Allow all incoming traffic to ports 1024-65535
};

#define NUM_RULES sizeof(rules)/sizeof(firewall_rule_t)

int main(int argc, char **argv) {

    // Create a raw socket to capture all incoming packets
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    while (1) {

        // Read the next packet from the socket
        u_char packet[65536];
        ssize_t packet_len = recvfrom(sock, packet, sizeof(packet), 0, NULL, NULL);
        if (packet_len < 0) {
            perror("recvfrom");
            exit(1);
        }

        // Parse the packet header
        struct ip *ip_header = (struct ip *) packet;
        if (ip_header->ip_p != IPPROTO_TCP) {
            // Ignore non-TCP packets
            continue;
        }

        struct tcphdr *tcp_header = (struct tcphdr *) (packet + ip_header->ip_hl * 4);
        u_short src_port = ntohs(tcp_header->th_sport);
        u_short dst_port = ntohs(tcp_header->th_dport);

        // Search through the firewall rules for a matching rule
        int match = DENY;
        for (int i = 0; i < NUM_RULES; i++) {
            if ((rules[i].src_ip.s_addr == ip_header->ip_src.s_addr || rules[i].src_ip.s_addr == htonl(INADDR_ANY)) &&
                (rules[i].dst_ip.s_addr == ip_header->ip_dst.s_addr || rules[i].dst_ip.s_addr == htonl(INADDR_ANY)) &&
                (src_port >= rules[i].src_port_min && src_port <= rules[i].src_port_max) &&
                (dst_port >= rules[i].dst_port_min && dst_port <= rules[i].dst_port_max)) {
                match = rules[i].action;
                break;
            }
        }

        if (match == DENY) {
            printf("Packet denied: src=%s dst=%s sport=%d dport=%d\n",
                inet_ntoa(ip_header->ip_src), inet_ntoa(ip_header->ip_dst),
                src_port, dst_port);
        } else {
            printf("Packet allowed: src=%s dst=%s sport=%d dport=%d\n",
                inet_ntoa(ip_header->ip_src), inet_ntoa(ip_header->ip_dst),
                src_port, dst_port);
        }

        // TODO: Implement firewall rule actions (e.g. drop packet, send RST)

    }

    return 0;
}