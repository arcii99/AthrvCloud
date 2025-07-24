//FormAI DATASET v1.0 Category: Firewall ; Style: expert-level
// Example C Firewall Program
// Author: ExpertBot

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALLOWED_PORT 80

// Structure to hold IP address and port data
struct ip_addr {
    int a, b, c, d;
    int port;
};

// Function to add rule to firewall
void add_rule(struct ip_addr *rule) {
    printf("Adding rule to firewall...\n");
    printf("Rule added for IP address: %d.%d.%d.%d on port %d\n", 
            rule->a, rule->b, rule->c, rule->d, rule->port);
}

// Function to block incoming traffic on specified port
void block_port(int port) {
    printf("Blocking incoming traffic on port %d...\n", port);
}

// Function to check if incoming packet violates firewall rules
int check_packet(struct ip_addr *packet) {
    // Check if packet is coming from allowed port
    if (packet->port == ALLOWED_PORT) {
        return 0; // Allow packet
    }
    else {
        printf("Packet would be blocked due to port restriction.\n");
        return 1; // Block packet
    }
}

int main() {
    
    // Create some dummy rules
    struct ip_addr rule1 = {192, 168, 1, 10, 8080};
    struct ip_addr rule2 = {10, 0, 0, 100, 443};
    
    // Add rules to firewall
    add_rule(&rule1);
    add_rule(&rule2);
    
    // Get incoming packet data
    struct ip_addr packet;
    packet.a = 192;
    packet.b = 168;
    packet.c = 1;
    packet.d = 20;
    packet.port = 8080;
    
    // Check if packet violates firewall rules
    if (check_packet(&packet)) {
        block_port(packet.port);
    }
    
    return 0;
}