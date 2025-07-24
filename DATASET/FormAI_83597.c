//FormAI DATASET v1.0 Category: Firewall ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define MAX_PACKET_LEN 4096
#define MAX_RULES 10

struct rule {
    char src_ip[16];
    char dst_ip[16];
    int src_port;
    int dst_port;
    int action;
};

struct packet {
    char src_ip[16];
    char dst_ip[16];
    int src_port;
    int dst_port;
};

struct rule rules[MAX_RULES];
int rule_count = 0;

void add_rule(char* src_ip, char* dst_ip, int src_port, int dst_port, int action) {
    if (rule_count >= MAX_RULES) {
        printf("Error: too many rules\n");
        return;
    }
    strncpy(rules[rule_count].src_ip, src_ip, sizeof(rules[rule_count].src_ip));
    strncpy(rules[rule_count].dst_ip, dst_ip, sizeof(rules[rule_count].dst_ip));
    rules[rule_count].src_port = src_port;
    rules[rule_count].dst_port = dst_port;
    rules[rule_count].action = action;
    rule_count++;
}

void print_rules() {
    printf("Rules:\n");
    for (int i = 0; i < rule_count; i++) {
        printf("%s:%d -> %s:%d -> %s\n", rules[i].src_ip, rules[i].src_port, rules[i].dst_ip, rules[i].dst_port, rules[i].action == 1 ? "ALLOW" : "BLOCK");
    }
}

int check_packet(struct packet* pkt) {
    for (int i = 0; i < rule_count; i++) {
        if (strcmp(pkt->src_ip, rules[i].src_ip) == 0 && strcmp(pkt->dst_ip, rules[i].dst_ip) == 0 &&
            pkt->src_port == rules[i].src_port && pkt->dst_port == rules[i].dst_port) {
            return rules[i].action;
        }
    }
    return 0;
}

int main() {
    char buffer[MAX_PACKET_LEN];
    struct sockaddr_in sin;
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    while (1) {
        int len = sizeof(sin);
        int bytes = recvfrom(sock, buffer, MAX_PACKET_LEN, 0, (struct sockaddr *)&sin, (socklen_t*)&len);
        if (bytes < 0) {
            perror("recvfrom failed");
            exit(1);
        }
        if (bytes < sizeof(struct iphdr) + sizeof(struct tcphdr)) {
            continue;
        }
        struct iphdr *ip_header = (struct iphdr *)buffer;
        if (ip_header->protocol != IPPROTO_TCP) {
            continue;
        }
        struct tcphdr *tcp_header = (struct tcphdr *)(buffer + sizeof(struct iphdr));
        struct packet pkt;
        snprintf(pkt.src_ip, sizeof(pkt.src_ip), "%d.%d.%d.%d", (ip_header->saddr & 0xff), ((ip_header->saddr >> 8) & 0xff), ((ip_header->saddr >> 16) & 0xff), ((ip_header->saddr >> 24) & 0xff));
        snprintf(pkt.dst_ip, sizeof(pkt.dst_ip), "%d.%d.%d.%d", (ip_header->daddr & 0xff), ((ip_header->daddr >> 8) & 0xff), ((ip_header->daddr >> 16) & 0xff), ((ip_header->daddr >> 24) & 0xff));
        pkt.src_port = ntohs(tcp_header->source);
        pkt.dst_port = ntohs(tcp_header->dest);
        int action = check_packet(&pkt);
        if (action == 0) {
            printf("BLOCKED %s:%d -> %s:%d\n", pkt.src_ip, pkt.src_port, pkt.dst_ip, pkt.dst_port);
        } else {
            printf("ALLOWED %s:%d -> %s:%d\n", pkt.src_ip, pkt.src_port, pkt.dst_ip, pkt.dst_port);
        }
    }

    return 0;
}