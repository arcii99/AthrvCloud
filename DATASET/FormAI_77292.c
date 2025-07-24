//FormAI DATASET v1.0 Category: Firewall ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100

// Define the structure of firewall rule
typedef struct {
    char sourceIP[MAX_LENGTH];
    char destinationIP[MAX_LENGTH];
    int sourcePort;
    int destinationPort;
    char protocol[MAX_LENGTH];
    bool allow;
} FirewallRule;

// Define the array of firewall rules
FirewallRule firewallRules[MAX_LENGTH];
int numberOfRules = 0;

// Function to add a new firewall rule
void addFirewallRule(char *sourceIP, char *destinationIP, int sourcePort, int destinationPort, char *protocol, bool allow) {
    strcpy(firewallRules[numberOfRules].sourceIP, sourceIP);
    strcpy(firewallRules[numberOfRules].destinationIP, destinationIP);
    firewallRules[numberOfRules].sourcePort = sourcePort;
    firewallRules[numberOfRules].destinationPort = destinationPort;
    strcpy(firewallRules[numberOfRules].protocol, protocol);
    firewallRules[numberOfRules].allow = allow;
    numberOfRules++;
}

// Function to check if a given packet is allowed by the firewall or not
bool isPacketAllowed(char *sourceIP, char *destinationIP, int sourcePort, int destinationPort, char *protocol) {
    for (int i = 0; i < numberOfRules; i++) {
        if ((strcmp(firewallRules[i].sourceIP, "any") == 0 || strcmp(firewallRules[i].sourceIP, sourceIP) == 0) &&
            (strcmp(firewallRules[i].destinationIP, "any") == 0 || strcmp(firewallRules[i].destinationIP, destinationIP) == 0) &&
            (firewallRules[i].sourcePort == 0 || firewallRules[i].sourcePort == sourcePort) &&
            (firewallRules[i].destinationPort == 0 || firewallRules[i].destinationPort == destinationPort) &&
            (strcmp(firewallRules[i].protocol, "any") == 0 || strcmp(firewallRules[i].protocol, protocol) == 0)) {
            return firewallRules[i].allow;
        }
    }
    return true;
}

int main() {
    // Add some sample firewall rules
    addFirewallRule("any", "192.168.1.1", 0, 80, "tcp", true);
    addFirewallRule("192.168.1.2", "any", 0, 0, "tcp", false);
    addFirewallRule("192.168.1.3", "192.168.1.4", 80, 80, "udp", false);

    // Simulate some incoming packets and check if they are allowed by the firewall or not
    bool allowed = isPacketAllowed("192.168.1.5", "192.168.1.1", 0, 80, "tcp");
    if (allowed) {
        printf("Packet is allowed by the firewall\n");
    } else {
        printf("Packet is blocked by the firewall\n");
    }

    allowed = isPacketAllowed("192.168.1.2", "192.168.1.5", 0, 0, "tcp");
    if (allowed) {
        printf("Packet is allowed by the firewall\n");
    } else {
        printf("Packet is blocked by the firewall\n");
    }

    allowed = isPacketAllowed("192.168.1.3", "192.168.1.4", 80, 80, "udp");
    if (allowed) {
        printf("Packet is allowed by the firewall\n");
    } else {
        printf("Packet is blocked by the firewall\n");
    }

    return 0;
}