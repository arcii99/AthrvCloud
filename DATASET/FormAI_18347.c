//FormAI DATASET v1.0 Category: Firewall ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RULES 1000
#define MAX_IP_LEN 16

// Structure for holding a firewall rule
typedef struct {
    char direction[10];
    char protocol[10];
    char ip_address[MAX_IP_LEN];
    unsigned int port;
} FirewallRule;

// Array for holding all the firewall rules
FirewallRule firewall_rules[MAX_RULES];
int num_rules = 0;

// Function for adding a firewall rule to the array
void add_rule(char* direction, char* protocol, char* ip_address, unsigned int port) {
    // Check if the array is full
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of firewall rules reached\n");
        return;
    }
    // Add the rule to the array
    strcpy(firewall_rules[num_rules].direction, direction);
    strcpy(firewall_rules[num_rules].protocol, protocol);
    strcpy(firewall_rules[num_rules].ip_address, ip_address);
    firewall_rules[num_rules].port = port;
    num_rules++;
}

// Function for checking if a given packet matches a firewall rule
bool check_packet(char* direction, char* protocol, char* ip_address, unsigned int port) {
    for (int i = 0; i < num_rules; i++) {
        // Check if the direction, protocol, and IP address match
        if (strcmp(firewall_rules[i].direction, direction) == 0
            && strcmp(firewall_rules[i].protocol, protocol) == 0
            && strcmp(firewall_rules[i].ip_address, ip_address) == 0) {
            // If the port is 0, then it matches any port
            if (firewall_rules[i].port == 0 || firewall_rules[i].port == port) {
                // The packet matches the rule, so we allow it
                return true;
            }
        }
    }
    // If no rule was matched, we deny the packet
    return false;
}

int main() {
    // Add some sample firewall rules
    add_rule("inbound", "tcp", "192.168.1.1", 80);
    add_rule("inbound", "udp", "192.168.1.2", 0);
    add_rule("outbound", "tcp", "192.168.1.3", 8080);

    // Test the firewall rules
    bool allowed = check_packet("inbound", "tcp", "192.168.1.1", 80);
    printf("Packet allowed: %d\n", allowed);
    allowed = check_packet("inbound", "tcp", "192.168.1.1", 8080);
    printf("Packet allowed: %d\n", allowed);
    allowed = check_packet("inbound", "udp", "192.168.1.2", 80);
    printf("Packet allowed: %d\n", allowed);
    allowed = check_packet("outbound", "tcp", "192.168.1.3", 8080);
    printf("Packet allowed: %d\n", allowed);
    allowed = check_packet("inbound", "tcp", "192.168.1.5", 80);
    printf("Packet allowed: %d\n", allowed);

    return 0;
}