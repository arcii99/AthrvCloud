//FormAI DATASET v1.0 Category: Firewall ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *address;
    char *protocol;
    int port;
    bool accepted;
} FirewallRule;

FirewallRule rules[10]; // Initializing an array of rules

int ruleCount = 0; // Count of rules added

void addRule(char *address, char *protocol, int port, bool accepted) {
    FirewallRule rule;
    rule.address = address;
    rule.protocol = protocol;
    rule.port = port;
    rule.accepted = accepted;

    rules[ruleCount] = rule; // Adding rule to the array
    ruleCount++; // Incrementing the count of rules
}

bool isAllowed(char *address, char *protocol, int port) {
    for (int i = 0; i < ruleCount; i++) {
        FirewallRule rule = rules[i];
        if (strcmp(rule.address, address) == 0 && strcmp(rule.protocol, protocol) == 0 && rule.port == port) {
            return rule.accepted;
        }
    }

    // If no matching rule is found, return false by default
    return false;
}

int main() {
    addRule("10.0.0.1", "TCP", 80, true);
    addRule("10.0.0.2", "UDP", 5000, false);

    // Testing the rules
    printf("%s\n", isAllowed("10.0.0.1", "TCP", 80) ? "Allowed" : "Blocked"); // Allowed
    printf("%s\n", isAllowed("10.0.0.2", "UDP", 5000) ? "Allowed" : "Blocked"); // Blocked
    printf("%s\n", isAllowed("10.0.0.3", "TCP", 80) ? "Allowed" : "Blocked"); // Blocked

    return 0;
}