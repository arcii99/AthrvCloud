//FormAI DATASET v1.0 Category: Firewall ; Style: Alan Touring
// Alan Turing-style C Firewall Example

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rules that can be added to the firewall
#define MAX_RULES 100

// Define the structure of a firewall rule
typedef struct {
    char protocol[10];
    char srcIP[20];
    char destIP[20];
} Rule;

// Define the structure of the firewall
typedef struct {
    Rule rules[MAX_RULES];
    int numRules;
} Firewall;

// Function to add a new rule to the firewall
void addRule(Firewall* firewall, Rule rule) {
    if (firewall->numRules < MAX_RULES) {
        firewall->rules[firewall->numRules++] = rule;
    }
}

// Function to check if a packet matches a rule in the firewall
int packetMatchesRule(Rule rule, char* protocol, char* srcIP, char* destIP) {
    if (strcmp(rule.protocol, protocol) == 0 || strcmp(rule.protocol, "ANY") == 0) {
        if (strcmp(rule.srcIP, srcIP) == 0 || strcmp(rule.srcIP, "ANY") == 0) {
            if (strcmp(rule.destIP, destIP) == 0 || strcmp(rule.destIP, "ANY") == 0) {
                return 1; // Packet matches the rule
            }
        }
    }

    return 0; // Packet does not match the rule
}

// Function to check if a packet is allowed by the firewall
int isPacketAllowed(Firewall firewall, char* protocol, char* srcIP, char* destIP) {
    for (int i = 0; i < firewall.numRules; i++) {
        if (packetMatchesRule(firewall.rules[i], protocol, srcIP, destIP)) {
            return 1; // Packet is allowed by the firewall
        }
    }

    return 0; // Packet is not allowed by the firewall
}

int main() {
    // Create a new empty firewall
    Firewall firewall = { .numRules = 0 };

    // Add some example rules to the firewall
    addRule(&firewall, (Rule) { .protocol = "TCP", .srcIP = "10.0.0.1", .destIP = "192.168.0.1" });
    addRule(&firewall, (Rule) { .protocol = "UDP", .srcIP = "10.0.0.2", .destIP = "192.168.0.2" });
    addRule(&firewall, (Rule) { .protocol = "ANY", .srcIP = "10.0.0.3", .destIP = "192.168.0.3" });

    // Check if some example packets are allowed by the firewall
    printf("Packet (TCP, 10.0.0.1, 192.168.0.1) %s allowed by firewall\n", isPacketAllowed(firewall, "TCP", "10.0.0.1", "192.168.0.1") ? "is" : "is not");
    printf("Packet (UDP, 10.0.0.1, 192.168.0.2) %s allowed by firewall\n", isPacketAllowed(firewall, "UDP", "10.0.0.1", "192.168.0.2") ? "is" : "is not");
    printf("Packet (TCP, 10.0.0.3, 192.168.0.4) %s allowed by firewall\n", isPacketAllowed(firewall, "TCP", "10.0.0.3", "192.168.0.4") ? "is" : "is not");

    return 0;
}