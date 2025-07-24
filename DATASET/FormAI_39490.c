//FormAI DATASET v1.0 Category: Firewall ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <errno.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 65536
#define TCP_HEADER_LENGTH sizeof(struct tcphdr)
#define ICMP_HEADER_LENGTH 8

// Define the allowed IP addresses and TCP ports
char *allowed_ips[] = {"127.0.0.1", "192.168.0.1"};
int allowed_ports[] = {80, 8080, 443};

void handle_packet(char *packet, int length, char *source_ip)
{
    // Check for TCP packet
    struct iphdr *ip = (struct iphdr *) packet;
    if (ip->protocol != IPPROTO_TCP) return;

    // Check for packet size
    if (length < sizeof(struct iphdr) + TCP_HEADER_LENGTH) return;

    struct tcphdr *tcp = (struct tcphdr *) (packet + sizeof(struct iphdr));

    // Check for allowed IP addresses
    int i, is_ip_allowed = 0;
    for (i = 0; i < sizeof(allowed_ips) / sizeof(allowed_ips[0]); i++) {
        if (strcmp(source_ip, allowed_ips[i]) == 0) {
            is_ip_allowed = 1;
            break;      
        }
    }
    if (!is_ip_allowed) {
        printf("Access denied for IP address %s\n", source_ip);
        return;
    }

    // Check for allowed TCP ports
    int is_port_allowed = 0;
    for (i = 0; i < sizeof(allowed_ports) / sizeof(allowed_ports[0]); i++) {
        if (tcp->th_dport == htons(allowed_ports[i])) {
            is_port_allowed = 1;
            break;
        }
    }
    if (!is_port_allowed) {
        printf("Access denied for TCP port %d\n", ntohs(tcp->th_dport));
        return;
    }

    // Forward the packet
    int total_length = ntohs(ip->tot_len);
    int bytes_sent = send(STDOUT_FILENO, packet, total_length, 0);
    if (bytes_sent == -1) {
        perror("Failed to send packet");
        return;
    }
}

int main()
{
    char packet[MAX_PACKET_SIZE];

    while (1) {
        int length = read(STDIN_FILENO, packet, MAX_PACKET_SIZE);
        if (length == -1) {
            perror("Failed to read packet");
            break;
        }
        if (length == 0) break;

        char source_ip[INET_ADDRSTRLEN];
        struct iphdr *ip = (struct iphdr *) packet;
        inet_ntop(AF_INET, &(ip->saddr), source_ip, INET_ADDRSTRLEN);
        handle_packet(packet, length, source_ip);
    }

    return 0;
}