//FormAI DATASET v1.0 Category: Firewall ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ip_addr {
    int octet1;
    int octet2;
    int octet3;
    int octet4;
};

struct rule {
    char* action;
    struct ip_addr src_addr;
    struct ip_addr dest_addr;
    int src_port;
    int dest_port;
    char* protocol;
};

struct packet {
    struct ip_addr src_addr;
    struct ip_addr dest_addr;
    int src_port;
    int dest_port;
    char* protocol;
};

// Function to compare two IP addresses
int compare_ip(struct ip_addr ip1, struct ip_addr ip2) {
    if(ip1.octet1 == ip2.octet1 && ip1.octet2 == ip2.octet2 && ip1.octet3 == ip2.octet3 && ip1.octet4 == ip2.octet4)
        return 1;

    return 0;
}

// Function to check if a packet matches a rule
int packet_matches_rule(struct packet p, struct rule r) {
    if(compare_ip(p.src_addr, r.src_addr) && compare_ip(p.dest_addr, r.dest_addr) && p.src_port == r.src_port && p.dest_port == r.dest_port && strcmp(p.protocol, r.protocol) == 0)
        return 1;

    return 0;
}

// Function to apply all the rules on a packet
void apply_rules_to_packet(struct packet p, struct rule rules[], int num_rules) {
    int i;
    for(i=0; i<num_rules; i++) {
        if(packet_matches_rule(p, rules[i])) {
            printf("%s\n", rules[i].action);
            return;
        }
    }
}

int main() {
    struct rule rules[5];

    // Rule 1: Block all incoming traffic from IP 10.0.0.1 on port 8080
    rules[0].action = "Block";
    rules[0].src_addr.octet1 = 10;
    rules[0].src_addr.octet2 = 0;
    rules[0].src_addr.octet3 = 0;
    rules[0].src_addr.octet4 = 1;
    rules[0].dest_addr.octet1 = 0;
    rules[0].dest_addr.octet2 = 0;
    rules[0].dest_addr.octet3 = 0;
    rules[0].dest_addr.octet4 = 0;
    rules[0].src_port = -1;
    rules[0].dest_port = 8080;
    rules[0].protocol = "TCP";

    // Rule 2: Allow all incoming traffic from IP 192.168.1.1 on any port
    rules[1].action = "Allow";
    rules[1].src_addr.octet1 = 192;
    rules[1].src_addr.octet2 = 168;
    rules[1].src_addr.octet3 = 1;
    rules[1].src_addr.octet4 = 1;
    rules[1].dest_addr.octet1 = 0;
    rules[1].dest_addr.octet2 = 0;
    rules[1].dest_addr.octet3 = 0;
    rules[1].dest_addr.octet4 = 0;
    rules[1].src_port = -1;
    rules[1].dest_port = -1;
    rules[1].protocol = "TCP";

    // Rule 3: Block all incoming traffic on port 80 and 443
    rules[2].action = "Block";
    rules[2].src_addr.octet1 = 0;
    rules[2].src_addr.octet2 = 0;
    rules[2].src_addr.octet3 = 0;
    rules[2].src_addr.octet4 = 0;
    rules[2].dest_addr.octet1 = 0;
    rules[2].dest_addr.octet2 = 0;
    rules[2].dest_addr.octet3 = 0;
    rules[2].dest_addr.octet4 = 0;
    rules[2].src_port = -1;
    rules[2].dest_port = 80;
    rules[2].protocol = "TCP";
    
    rules[3].action = "Block";
    rules[3].src_addr.octet1 = 0;
    rules[3].src_addr.octet2 = 0;
    rules[3].src_addr.octet3 = 0;
    rules[3].src_addr.octet4 = 0;
    rules[3].dest_addr.octet1 = 0;
    rules[3].dest_addr.octet2 = 0;
    rules[3].dest_addr.octet3 = 0;
    rules[3].dest_addr.octet4 = 0;
    rules[3].src_port = -1;
    rules[3].dest_port = 443;
    rules[3].protocol = "TCP";

    // Rule 4: Allow all outgoing traffic
    rules[4].action = "Allow";
    rules[4].src_addr.octet1 = 0;
    rules[4].src_addr.octet2 = 0;
    rules[4].src_addr.octet3 = 0;
    rules[4].src_addr.octet4 = 0;
    rules[4].dest_addr.octet1 = 0;
    rules[4].dest_addr.octet2 = 0;
    rules[4].dest_addr.octet3 = 0;
    rules[4].dest_addr.octet4 = 0;
    rules[4].src_port = -1;
    rules[4].dest_port = -1;
    rules[4].protocol = "TCP";

    // Applying the rules on different packets
    struct packet p1 = { {192, 168, 1, 1}, {10, 0, 0, 1}, -1, 8080, "TCP" };
    apply_rules_to_packet(p1, rules, 5); // Should allow the packet

    struct packet p2 = { {192, 168, 1, 2}, {10, 0, 0, 1}, -1, 8080, "TCP" };
    apply_rules_to_packet(p2, rules, 5); // Should block the packet

    struct packet p3 = { {10, 0, 0, 2}, {192, 168, 1, 1}, -1, 3000, "UDP" };
    apply_rules_to_packet(p3, rules, 5); // Should allow the packet

    struct packet p4 = { {192, 168, 1, 1}, {10, 0, 0, 1}, -1, 443, "TCP" };
    apply_rules_to_packet(p4, rules, 5); // Should block the packet

    return 0;
}