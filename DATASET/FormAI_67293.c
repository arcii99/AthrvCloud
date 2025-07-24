//FormAI DATASET v1.0 Category: Firewall ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IP_ADDRESS_LEN 20
#define MAX_RULES 1000

typedef struct {
    char source_ip[MAX_IP_ADDRESS_LEN];
    char destination_ip[MAX_IP_ADDRESS_LEN];
    bool allow;
} FirewallRule;

FirewallRule firewall_rules[MAX_RULES];
int num_rules = 0;

bool is_allowed(char *source_ip, char *destination_ip) {
    for (int i = 0; i < num_rules; i++) {
        FirewallRule curr_rule = firewall_rules[i];
        if (strcmp(curr_rule.source_ip, source_ip) == 0 && strcmp(curr_rule.destination_ip, destination_ip) == 0) {
            return curr_rule.allow;
        }
    }
    return false;
}

void add_rule(char *source_ip, char *destination_ip, bool allow) {
    if (num_rules >= MAX_RULES) {
        printf("Firewall rule limit exceeded.\n");
        exit(1);
    }
    FirewallRule new_rule;
    strcpy(new_rule.source_ip, source_ip);
    strcpy(new_rule.destination_ip, destination_ip);
    new_rule.allow = allow;
    firewall_rules[num_rules] = new_rule;
    num_rules++;
}

int main() {
    add_rule("192.168.1.2", "10.0.0.5", true);
    add_rule("10.0.0.5", "192.168.1.2", false);
    add_rule("192.168.1.2", "10.0.0.6", false);
    add_rule("10.0.0.5", "8.8.8.8", true);
    
    // Test the firewall rules
    printf("Is source IP 192.168.1.2 and destination IP 10.0.0.5 allowed? ");
    if (is_allowed("192.168.1.2", "10.0.0.5")) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    printf("Is source IP 10.0.0.5 and destination IP 192.168.1.2 allowed? ");
    if (is_allowed("10.0.0.5", "192.168.1.2")) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    printf("Is source IP 192.168.1.2 and destination IP 10.0.0.6 allowed? ");
    if (is_allowed("192.168.1.2", "10.0.0.6")) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    printf("Is source IP 10.0.0.5 and destination IP 8.8.8.8 allowed? ");
    if (is_allowed("10.0.0.5", "8.8.8.8")) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    // Try to add too many rules
    for (int i = 0; i < 900; i++) {
        add_rule("192.168.1.2", "10.0.0.5", true);
    }
    add_rule("192.168.1.2", "10.0.0.5", true);
    
    return 0;
}