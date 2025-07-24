//FormAI DATASET v1.0 Category: Firewall ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Firewall rules
#define ALLOW 1
#define BLOCK 0

// Define the maximum number of rules to be added
#define MAX_RULES 100

// Define the structure of the Firewall rule
typedef struct {
    char direction[10];
    char protocol[5];
    int port;
    char action[10];
} FirewallRule;

// Global variables
FirewallRule firewallRules[MAX_RULES];
int numberOfRules = 0;

// Function to add a new Firewall rule
void addFirewallRule(char* direction, char* protocol, int port, char* action) {
    if (numberOfRules >= MAX_RULES) {
        printf("Cannot add more Firewall rules.\n");
        return;
    }
    FirewallRule rule;
    strcpy(rule.direction, direction);
    strcpy(rule.protocol, protocol);
    rule.port = port;
    strcpy(rule.action, action);
    firewallRules[numberOfRules++] = rule;
    printf("Firewall rule added successfully.\n");
}

// Function to check if a packet can pass through the Firewall
int checkPacket(char* direction, char* protocol, int port) {
    for (int i = 0; i < numberOfRules; i++) {
        FirewallRule rule = firewallRules[i];
        if (strcmp(rule.direction, direction) == 0 &&
            strcmp(rule.protocol, protocol) == 0 &&
            (rule.port == port || rule.port == 0)) {
            if (strcmp(rule.action, "ALLOW") == 0) {
                return ALLOW;
            } else {
                return BLOCK;
            }
        }
    }
    return ALLOW;
}

// Main function
int main() {
    // Add some sample rules
    addFirewallRule("IN", "TCP", 80, "ALLOW");
    addFirewallRule("IN", "UDP", 0, "BLOCK");

    // Simulate some incoming packets
    int packetCounter = 0;
    int packetDirection[] = {1, 0, 1, 0};
    char packetProtocol[][5] = {"TCP", "UDP", "TCP", "UDP"};
    int packetPort[] = {80, 53, 8080, 443};
    for (int i = 0; i < 4; i++) {
        packetCounter++;
        int status = checkPacket(packetDirection[i] == 1 ? "IN" : "OUT", packetProtocol[i], packetPort[i]);
        if (status == ALLOW) {
            printf("Packet %d passed.\n", packetCounter);
        } else {
            printf("Packet %d blocked.\n", packetCounter);
        }
    }

    return 0;
}