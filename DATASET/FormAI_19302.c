//FormAI DATASET v1.0 Category: Firewall ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFSIZE 1024

// Struct for storing rules
struct firewall_rule {
    char protocol[10];
    char source_ip[20];
    int source_port;
    char dest_ip[20];
    int dest_port;
};

// Check if a packet matches a firewall rule
int packet_match_rule(struct firewall_rule *rule, char *protocol, char *source_ip, int source_port, char *dest_ip, int dest_port) {
    // Check protocol
    if (strcmp(rule->protocol, protocol) != 0) return 0;

    // Check source IP
    if (strcmp(rule->source_ip, source_ip) != 0 && strcmp(rule->source_ip, "*") != 0) return 0;

    // Check source port
    if (rule->source_port != source_port && rule->source_port != 0) return 0;

    // Check destination IP
    if (strcmp(rule->dest_ip, dest_ip) != 0 && strcmp(rule->dest_ip, "*") != 0) return 0;

    // Check destination port
    if (rule->dest_port != dest_port && rule->dest_port != 0) return 0;

    return 1;
}

int main() {
    // Create socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind socket
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Initialize firewall rules
    struct firewall_rule rules[3];
    strcpy(rules[0].protocol, "TCP");
    strcpy(rules[0].source_ip, "*");
    rules[0].source_port = 0;
    strcpy(rules[0].dest_ip, "192.168.0.2");
    rules[0].dest_port = 80;

    strcpy(rules[1].protocol, "UDP");
    strcpy(rules[1].source_ip, "192.168.0.3");
    rules[1].source_port = 0;
    strcpy(rules[1].dest_ip, "*");
    rules[1].dest_port = 53;

    strcpy(rules[2].protocol, "TCP");
    strcpy(rules[2].source_ip, "*");
    rules[2].source_port = 8080;
    strcpy(rules[2].dest_ip, "*");
    rules[2].dest_port = 0;

    // Handle incoming packets
    char buf[BUFSIZE];
    struct sockaddr_in src_addr;
    socklen_t src_addr_len = sizeof(src_addr);
    while (1) {
        // Receive packet
        int n = recvfrom(sockfd, buf, BUFSIZE, 0, (struct sockaddr *)&src_addr, &src_addr_len);
        if (n < 0) {
            perror("Error receiving packet");
            exit(1);
        }

        // Parse packet data
        char protocol[10];
        inet_ntop(AF_INET, &src_addr.sin_addr, buf, BUFSIZE);
        unsigned short int src_port = ntohs(src_addr.sin_port);
        inet_ntop(AF_INET, &addr.sin_addr, buf, BUFSIZE);
        unsigned short int dest_port = ntohs(addr.sin_port);

        if (memcmp(buf, "TCP", 3) == 0) {
            strcpy(protocol, "TCP");
        } else if (memcmp(buf, "UDP", 3) == 0) {
            strcpy(protocol, "UDP");
        } else {
            perror("Unknown protocol");
            continue;
        }

        // Check if packet matches any firewall rules
        int allowed = 0;
        for (int i = 0; i < 3; i++) {
            if (packet_match_rule(&rules[i], protocol, buf, src_port, buf, dest_port)) {
                allowed = 1;
                break;
            }
        }

        // If packet is not allowed, drop it
        if (!allowed) {
            printf("Packet dropped: %s %d -> %s %d\n", protocol, src_port, buf, dest_port);
            continue;
        }

        // If packet is allowed, print header info and forward it
        printf("Forwarding packet: %s %d -> %s %d\n", protocol, src_port, buf, dest_port);
        sendto(sockfd, buf, n, 0, (struct sockaddr *)&addr, sizeof(addr));
    }

    return 0;
}