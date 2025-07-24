//FormAI DATASET v1.0 Category: Firewall ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IP_LENGTH 15

// Structure defining the Firewall rules
typedef struct Rule {
    char* ip_address;
    bool allow_access;
} Rule;

// Function to check if IP is in the blacklist
bool is_in_blacklist(char* ip_address, Rule* firewall_rules, int num_rules) {
    for(int i = 0; i < num_rules; i++) {
        if(strcmp(firewall_rules[i].ip_address, ip_address) == 0 && !firewall_rules[i].allow_access) {
            return true;
        }
    }
    return false;
}

// Function to add Firewall rule
void add_rule(Rule* firewall_rules, int* num_rules, char* ip_address, bool allow_access) {
    firewall_rules[*num_rules].ip_address = ip_address;
    firewall_rules[*num_rules].allow_access = allow_access;
    (*num_rules)++;
}

// Function to process incoming requests
void process_request(char* ip_address, Rule* firewall_rules, int num_rules) {
    if(is_in_blacklist(ip_address, firewall_rules, num_rules)) {
        printf("%s is not allowed to access the server.\n", ip_address);
    } else {
        printf("%s is allowed to access the server.\n", ip_address);
    }
}

// Main function
int main() {
    int num_rules = 0;
    Rule firewall_rules[10];

    // Add initial rules
    add_rule(firewall_rules, &num_rules, "192.168.1.1", false);
    add_rule(firewall_rules, &num_rules, "192.168.1.2", false);
    add_rule(firewall_rules, &num_rules, "192.168.1.3", true);

    // Process requests
    process_request("192.168.1.1", firewall_rules, num_rules);
    process_request("192.168.1.2", firewall_rules, num_rules);
    process_request("192.168.1.3", firewall_rules, num_rules);
    process_request("192.168.1.4", firewall_rules, num_rules);

    return 0;
}