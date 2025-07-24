//FormAI DATASET v1.0 Category: Firewall ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 1000
#define MAX_IP_LEN 16
#define MAX_PROTOCOL_LEN 10

typedef struct {
    char source_ip[MAX_IP_LEN];
    char dest_ip[MAX_IP_LEN];
    char protocol[MAX_PROTOCOL_LEN];
    int allowed;
} FirewallRule;

FirewallRule rules[MAX_RULES];
int num_rules = 0;

int add_rule(char* source_ip, char* dest_ip, char* protocol, int allowed) {
    if (num_rules >= MAX_RULES) {
        return -1; // Rule limit exceeded
    }

    FirewallRule* rule = &rules[num_rules++];
    strncpy(rule->source_ip, source_ip, MAX_IP_LEN);
    strncpy(rule->dest_ip, dest_ip, MAX_IP_LEN);
    strncpy(rule->protocol, protocol, MAX_PROTOCOL_LEN);
    rule->allowed = allowed;

    return 0;
}

int is_allowed(char* source_ip, char* dest_ip, char* protocol) {
    for (int i = 0; i < num_rules; i++) {
        FirewallRule* rule = &rules[i];
        if (strcmp(rule->source_ip, source_ip) == 0 &&
            strcmp(rule->dest_ip, dest_ip) == 0 &&
            strcmp(rule->protocol, protocol) == 0) {
            return rule->allowed;
        }
    }

    return 0; // Default deny policy
}

int main() {
    // Add firewall rules
    add_rule("192.168.1.100", "8.8.8.8", "TCP", 1);
    add_rule("192.168.1.100", "8.8.8.8", "UDP", 1);
    add_rule("192.168.1.101", "8.8.8.8", "TCP", 0);
    add_rule("192.168.1.101", "8.8.8.8", "UDP", 0);

    // Test firewall
    printf("%d\n", is_allowed("192.168.1.100", "8.8.8.8", "TCP")); // Should print 1
    printf("%d\n", is_allowed("192.168.1.100", "8.8.8.8", "UDP")); // Should print 1
    printf("%d\n", is_allowed("192.168.1.101", "8.8.8.8", "TCP")); // Should print 0
    printf("%d\n", is_allowed("192.168.1.101", "8.8.8.8", "UDP")); // Should print 0

    return 0;
}