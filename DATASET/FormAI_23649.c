//FormAI DATASET v1.0 Category: Firewall ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 15
#define MAX_RULES 10

// Firewall rule
struct Rule {
    char ip[MAX_IP_LENGTH+1];
    int port;
    int action; // 0 for block, 1 for allow
};

// Firewall implementation
void firewall(int index, char* ip, int port, struct Rule *rules, int num_rules) {
    // Base case
    if (index == num_rules) {
        printf("Blocked traffic from %s:%d\n", ip, port);
        return;
    }
    
    // Check if IP and port match the current rule
    if (strcmp(ip, rules[index].ip) == 0 && port == rules[index].port) {
        if (rules[index].action == 0) {
            printf("Blocked traffic from %s:%d\n", ip, port);
            return;
        } else {
            printf("Allowed traffic from %s:%d\n", ip, port);
            return;
        }
    }
    
    // Move to the next rule
    firewall(index+1, ip, port, rules, num_rules);
}

int main() {
    // Initialize firewall rules
    struct Rule rules[MAX_RULES];
    strcpy(rules[0].ip, "192.168.1.1");
    rules[0].port = 80;
    rules[0].action = 0;
    strcpy(rules[1].ip, "192.168.1.2");
    rules[1].port = 22;
    rules[1].action = 1;
    strcpy(rules[2].ip, "192.168.1.3");
    rules[2].port = 443;
    rules[2].action = 1;
    int num_rules = 3;
    
    // Test the firewall with some traffic
    firewall(0, "192.168.1.1", 80, rules, num_rules);
    firewall(0, "192.168.1.2", 22, rules, num_rules);
    firewall(0, "192.168.1.4", 8080, rules, num_rules);
    
    return 0;
}