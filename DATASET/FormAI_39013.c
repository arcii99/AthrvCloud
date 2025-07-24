//FormAI DATASET v1.0 Category: Firewall ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_RULES 1000
#define MAX_IP_LENGTH 15

typedef struct {
    char src_ip[MAX_IP_LENGTH + 1];
    char dest_ip[MAX_IP_LENGTH + 1];
    int src_port;
    int dest_port;
    bool allow;
} Rule;

int num_rules = 0;
Rule firewall_rules[MAX_RULES];

void add_rule(char* src_ip, char* dest_ip, int src_port, int dest_port, bool allow) {
    if (num_rules < MAX_RULES) {
        strcpy(firewall_rules[num_rules].src_ip, src_ip);
        strcpy(firewall_rules[num_rules].dest_ip, dest_ip);
        firewall_rules[num_rules].src_port = src_port;
        firewall_rules[num_rules].dest_port = dest_port;
        firewall_rules[num_rules].allow = allow;
        num_rules++;
    } else {
        printf("Error: Maximum number of rules reached.\n");
    }
}

bool check_rule(char* src_ip, char* dest_ip, int src_port, int dest_port) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(firewall_rules[i].src_ip, "*") != 0 && strcmp(firewall_rules[i].src_ip, src_ip) != 0) {
            continue;
        }
        if (strcmp(firewall_rules[i].dest_ip, "*") != 0 && strcmp(firewall_rules[i].dest_ip, dest_ip) != 0) {
            continue;
        }
        if (firewall_rules[i].src_port != 0 && firewall_rules[i].src_port != src_port) {
            continue;
        }
        if (firewall_rules[i].dest_port != 0 && firewall_rules[i].dest_port != dest_port) {
            continue;
        }
        return firewall_rules[i].allow;
    }
    return false;
}

int main() {
    add_rule("192.168.1.2", "8.8.8.8", 0, 53, true);
    add_rule("192.168.1.3", "*", 0, 80, true);
    add_rule("*", "192.168.1.4", 0, 0, false);

    if (check_rule("192.168.1.2", "8.8.8.8", 0, 53)) {
        printf("Allow\n");
    } else {
        printf("Deny\n");
    }

    if (check_rule("192.168.1.3", "8.8.8.8", 0, 80)) {
        printf("Allow\n");
    } else {
        printf("Deny\n");
    }

    if (check_rule("192.168.1.4", "8.8.8.8", 0, 100)) {
        printf("Allow\n");
    } else {
        printf("Deny\n");
    }

    return 0;
}