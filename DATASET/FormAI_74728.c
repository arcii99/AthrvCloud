//FormAI DATASET v1.0 Category: Firewall ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define BUFFER_SIZE 1024
#define RULES_FILE "firewall.rules"

struct rule {
    in_addr_t src_ip;
    in_addr_t dst_ip;
    uint16_t src_port;
    uint16_t dst_port;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        exit(1);
    }

    char *interface = argv[1];

    // Load rules from file
    FILE *rules_file = fopen(RULES_FILE, "r");
    if (rules_file == NULL) {
        printf("Error: could not open rules file.\n");
        exit(1);
    }

    char line[BUFFER_SIZE];
    struct rule rules[BUFFER_SIZE];
    int num_rules = 0;

    while (fgets(line, BUFFER_SIZE, rules_file) != NULL) {
        char *src_ip_str = strtok(line, ",");
        char *dst_ip_str = strtok(NULL, ",");
        char *src_port_str = strtok(NULL, ",");
        char *dst_port_str = strtok(NULL, "\n");

        if (src_ip_str == NULL || dst_ip_str == NULL || src_port_str == NULL || dst_port_str == NULL) {
            printf("Error: invalid rule format.\n");
            continue;
        }

        struct rule rule = {
            .src_ip = inet_addr(src_ip_str),
            .dst_ip = inet_addr(dst_ip_str),
            .src_port = htons(atoi(src_port_str)),
            .dst_port = htons(atoi(dst_port_str)),
        };

        rules[num_rules++] = rule;
    }

    fclose(rules_file);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        printf("Error: could not create socket.\n");
        exit(1);
    }

    // Set socket options
    int optval = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &optval, sizeof(optval)) < 0) {
        printf("Error: could not set socket option.\n");
        exit(1);
    }

    // Bind socket to interface
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = 0;
    sin.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        printf("Error: could not bind socket to interface.\n");
        exit(1);
    }

    // Receive packets and apply rules
    char packet[BUFFER_SIZE];
    struct sockaddr_in sin_rcv;
    int sin_rcv_len = sizeof(sin_rcv);

    while (1) {
        int packet_len = recvfrom(sockfd, packet, BUFFER_SIZE, 0, (struct sockaddr *)&sin_rcv, &sin_rcv_len);
        if (packet_len < 0) {
            printf("Error: could not receive packet.\n");
            continue;
        }

        struct iphdr *iph = (struct iphdr *)packet;
        if (iph->protocol == IPPROTO_TCP) {
            struct tcphdr *tcph = (struct tcphdr *)(packet + sizeof(struct iphdr));
            in_addr_t src_ip = iph->saddr;
            in_addr_t dst_ip = iph->daddr;
            uint16_t src_port = ntohs(tcph->source);
            uint16_t dst_port = ntohs(tcph->dest);

            int allowed = 0;
            for (int i = 0; i < num_rules; i++) {
                struct rule rule = rules[i];
                if ((rule.src_ip == INADDR_ANY || src_ip == rule.src_ip) &&
                    (rule.dst_ip == INADDR_ANY || dst_ip == rule.dst_ip) &&
                    (rule.src_port == 0 || src_port == rule.src_port) &&
                    (rule.dst_port == 0 || dst_port == rule.dst_port)) {
                    allowed = 1;
                    break;
                }
            }

            printf("Packet from %s:%d to %s:%d is %s\n", inet_ntoa(*(struct in_addr *)&src_ip), src_port, inet_ntoa(*(struct in_addr *)&dst_ip), dst_port, allowed ? "allowed" : "blocked");
        }
    }

    close(sockfd);

    return 0;
}