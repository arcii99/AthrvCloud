//FormAI DATASET v1.0 Category: Firewall ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define initial firewall rules
struct FirewallRule {
    char direction;
    char protocol[10];
    char source_address[20];
    char destination_address[20];
    int source_port;
    int destination_port;
};

struct FirewallRules {
    struct FirewallRule rules[100];
    int count;
};

// Helper function to process incoming packets
bool process_packet(int packet_id, char *packet_direction, char *packet_protocol, char *packet_source_address, char *packet_destination_address, int packet_source_port, int packet_destination_port, struct FirewallRules *rules) {

    bool allowed = false;
    struct FirewallRule rule;

    // Check all firewall rules to see if the current packet should be allowed or blocked
    for (int i = 0; i < rules->count; i++) {
        rule = rules->rules[i];

        // Check if the incoming packet's direction matches the rule's direction
        if (*packet_direction == rule.direction || rule.direction == 'B') {

            // Check if the incoming packet's protocol matches the rule's protocol
            if (strcmp(packet_protocol, rule.protocol) == 0 || strcmp(rule.protocol, "ALL") == 0) {

                // Check if the incoming packet's source address matches the rule's source address
                if (strcmp(packet_source_address, rule.source_address) == 0 || strcmp(rule.source_address, "ALL") == 0) {

                    // Check if the incoming packet's destination address matches the rule's destination address
                    if (strcmp(packet_destination_address, rule.destination_address) == 0 || strcmp(rule.destination_address, "ALL") == 0) {

                        // Check if the incoming packet's source port matches the rule's source port
                        if (packet_source_port == rule.source_port || rule.source_port == -1) {

                            // Check if the incoming packet's destination port matches the rule's destination port
                            if (packet_destination_port == rule.destination_port || rule.destination_port == -1) {

                                // If all checks pass, allow the packet
                                allowed = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    // Log the status of the packet based on whether it was allowed or blocked
    if (allowed) {
        printf("Packet %d allowed by firewall.\n", packet_id);
    } else {
        printf("Packet %d blocked by firewall.\n", packet_id);
    }

    return allowed;
}

int main() {
    // Define the initial firewall rules
    struct FirewallRules rules = {
        .rules = {
            {
                .direction = 'I',
                .protocol = "TCP",
                .source_address = "192.168.0.0/16",
                .destination_address = "ALL",
                .source_port = 80,
                .destination_port = -1
            },
            {
                .direction = 'O',
                .protocol = "UDP",
                .source_address = "ALL",
                .destination_address = "10.0.0.0/8",
                .source_port = -1,
                .destination_port = 53
            }
        },
        .count = 2
    };

    // Process some incoming packets with the firewall rules
    process_packet(1, "I", "TCP", "192.168.0.1", "8.8.8.8", 80, 80, &rules);
    process_packet(2, "O", "UDP", "192.168.1.1", "10.10.10.10", 100, 53, &rules);

    return 0;
}