//FormAI DATASET v1.0 Category: Firewall ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 1000
#define MAX_IP_LEN 16

struct Rule {
    char source_ip[MAX_IP_LEN];
    char dest_ip[MAX_IP_LEN];
    int source_port;
    int dest_port;
    char protocol[5];
};

struct Firewall {
    struct Rule rules[MAX_RULES];
    int num_rules;
};

void add_rule(struct Firewall* firewall, char* source_ip, char* dest_ip, int source_port, int dest_port, char* protocol) {
    struct Rule new_rule;
    strncpy(new_rule.source_ip, source_ip, MAX_IP_LEN);
    strncpy(new_rule.dest_ip, dest_ip, MAX_IP_LEN);
    new_rule.source_port = source_port;
    new_rule.dest_port = dest_port;
    strncpy(new_rule.protocol, protocol, 5);
    firewall->rules[firewall->num_rules] = new_rule;
    firewall->num_rules++;
}

int check_rule(struct Rule* rule, char* source_ip, char* dest_ip, int source_port, int dest_port, char* protocol) {
    if (strcmp(rule->protocol, protocol) != 0) {
        return 0;
    }
    if (strcmp(rule->source_ip, source_ip) == 0 
        && strcmp(rule->dest_ip, dest_ip) == 0 
        && rule->source_port == source_port
        && rule->dest_port == dest_port) {
        return 1;
    }
    return 0;
}

int check_firewall(struct Firewall* firewall, char* source_ip, char* dest_ip, int source_port, int dest_port, char* protocol) {
    for (int i = 0; i < firewall->num_rules; i++) {
        if (check_rule(&firewall->rules[i], source_ip, dest_ip, source_port, dest_port, protocol)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    struct Firewall my_firewall;
    my_firewall.num_rules = 0;
    add_rule(&my_firewall, "192.168.0.1", "10.0.0.1", 80, 8080, "tcp");
    add_rule(&my_firewall, "10.0.0.1", "192.168.0.1", 8080, 80, "tcp");
    add_rule(&my_firewall, "192.168.0.1", "10.0.0.1", 443, 8443, "https");
    add_rule(&my_firewall, "10.0.0.1", "192.168.0.1", 8443, 443, "https");

    char source_ip[MAX_IP_LEN];
    char dest_ip[MAX_IP_LEN];
    int source_port;
    int dest_port;
    char protocol[5];

    printf("Enter the source IP address:\n");
    scanf("%s", source_ip);
    printf("Enter the destination IP address:\n");
    scanf("%s", dest_ip);
    printf("Enter the source port:\n");
    scanf("%d", &source_port);
    printf("Enter the destination port:\n");
    scanf("%d", &dest_port);
    printf("Enter the protocol:\n");
    scanf("%s", protocol);

    if (check_firewall(&my_firewall, source_ip, dest_ip, source_port, dest_port, protocol)) {
        printf("Access granted\n");
    } else {
        printf("Access denied\n");
    }

    return 0;
}