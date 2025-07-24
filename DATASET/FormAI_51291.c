//FormAI DATASET v1.0 Category: Firewall ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_IPV4 16
#define MAX_RULES 4096

enum rule_action {
    RULE_ACCEPT,
    RULE_DROP
};

struct rule {
    uint32_t src_ip;
    uint32_t src_mask;
    uint32_t dst_ip;
    uint32_t dst_mask;
    uint16_t src_port;
    uint16_t dst_port;
    int action;
};

struct firewall {
    struct rule rules[MAX_RULES];
    int num_rules;
};

int parse_ip(const char* str, uint32_t* ip) {
    struct in_addr addr;
    if (inet_pton(AF_INET, str, &addr) != 1) {
        return -1;
    }
    *ip = ntohl(addr.s_addr);
    return 0;
}

int parse_cidr(const char* str, uint32_t* ip, uint32_t* mask) {
    char* slash = strchr(str, '/');
    if (slash == NULL) {
        return -1;
    }
    char ip_str[MAX_IPV4];
    strncpy(ip_str, str, slash-str);
    ip_str[slash-str] = '\0';
    if (parse_ip(ip_str, ip) != 0) {
        return -1;
    }
    int bits = atoi(slash+1);
    if (bits < 0 || bits > 32) {
        return -1;
    }
    *mask = htonl(0xffffffff << (32-bits));
    return 0;
}

int parse_port(const char* str, uint16_t* port) {
    int p = atoi(str);
    if (p < 0 || p > 65535) {
        return -1;
    }
    *port = htons(p);
    return 0;
}

int parse_rule(const char* str, struct rule* rule) {
    char src[MAX_IPV4+3];
    char dst[MAX_IPV4+3];
    char sport[6];
    char dport[6];
    char action[6];
    if (sscanf(str, "%16[^:]:%6[^:]:%16[^:]:%6[^:]:%5[^:]:%5[^:]", src, sport, dst, dport, action) != 6) {
        return -1;
    }
    if (strcmp(action, "accept") == 0) {
        rule->action = RULE_ACCEPT;
    } else if (strcmp(action, "drop") == 0) {
        rule->action = RULE_DROP;
    } else {
        return -1;
    }
    if (parse_cidr(src, &rule->src_ip, &rule->src_mask) != 0) {
        return -1;
    }
    if (parse_cidr(dst, &rule->dst_ip, &rule->dst_mask) != 0) {
        return -1;
    }
    if (parse_port(sport, &rule->src_port) != 0) {
        return -1;
    }
    if (parse_port(dport, &rule->dst_port) != 0) {
        return -1;
    }
    return 0;
}

int firewall_init(struct firewall* fw) {
    fw->num_rules = 0;
    return 0;
}

int firewall_add_rule(struct firewall* fw, const char* str) {
    if (fw->num_rules >= MAX_RULES) {
        return -1;
    }
    struct rule* rule = &fw->rules[fw->num_rules++];
    return parse_rule(str, rule);
}

int firewall_accept_packet(struct firewall* fw, const char* src_ip_str, const char* dst_ip_str, uint16_t src_port, uint16_t dst_port) {
    uint32_t src_ip;
    uint32_t dst_ip;
    if (parse_ip(src_ip_str, &src_ip) != 0 || parse_ip(dst_ip_str, &dst_ip) != 0) {
        return 0;
    }
    for (int i = 0; i < fw->num_rules; i++) {
        struct rule* rule = &fw->rules[i];
        if ((src_ip & rule->src_mask) == (rule->src_ip & rule->src_mask)
            && (dst_ip & rule->dst_mask) == (rule->dst_ip & rule->dst_mask)
            && src_port == rule->src_port
            && dst_port == rule->dst_port) {
            return rule->action == RULE_ACCEPT;
        }
    }
    return 0;
}

int main() {
    struct firewall fw;
    firewall_init(&fw);
    firewall_add_rule(&fw, "192.168.0.0/24:1024:10.0.0.1/32:80,443:accept");
    firewall_add_rule(&fw, "192.168.0.0/24::10.0.0.2/32::drop");
    printf("Accept packet: %d\n", firewall_accept_packet(&fw, "192.168.0.1", "10.0.0.1", 1024, 80));
    printf("Accept packet: %d\n", firewall_accept_packet(&fw, "192.168.0.1", "10.0.0.2", 1024, 80));
    printf("Accept packet: %d\n", firewall_accept_packet(&fw, "192.168.1.1", "10.0.0.1", 1024, 80));
    printf("Accept packet: %d\n", firewall_accept_packet(&fw, "192.168.0.1", "10.0.0.1", 1025, 80));
    return 0;
}