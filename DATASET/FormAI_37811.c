//FormAI DATASET v1.0 Category: Firewall ; Style: Donald Knuth
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>

// Define constants
#define MAX_IP_LENGTH 16    // Maximum length of an IP address string
#define MAX_RULES 10        // Maximum number of firewall rules
#define ALLOW 1
#define BLOCK 0

// Define a struct for the firewall rule
struct FirewallRule {
    uint32_t ip_address;
    uint32_t subnet_mask;
    bool action;
};

// Define a struct for the IP packet header
struct IpHeader {
    uint8_t version_and_header_length;
    uint8_t differentiated_services_field;
    uint16_t total_length;
    uint16_t identification;
    uint16_t flags_and_fragment_offset;
    uint8_t time_to_live;
    uint8_t protocol;
    uint16_t header_checksum;
    uint32_t source_address;
    uint32_t destination_address;
};

// Function to convert IP address string to uint32_t
uint32_t ip_string_to_uint(char* ip_address) {
    struct in_addr addr;
    inet_aton(ip_address, &addr);
    return (uint32_t)addr.s_addr;
}

// Function to determine if a given IP address matches a given rule
bool does_ip_match_rule(uint32_t ip_address, uint32_t subnet_mask, uint32_t rule_ip_address) {
    return ((ip_address & subnet_mask) == (rule_ip_address & subnet_mask));
}

// Function to apply the firewall rules to a given IP packet
bool apply_firewall_rules(struct IpHeader* ip_header, struct FirewallRule* firewall_rules, int num_rules) {
    for (int i = 0; i < num_rules; i++) {
        if (does_ip_match_rule(ip_header->source_address, firewall_rules[i].subnet_mask, firewall_rules[i].ip_address)) {
            if (firewall_rules[i].action == ALLOW) {
                return true;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // Define the firewall rules
    int num_rules = 4;
    struct FirewallRule firewall_rules[MAX_RULES] = {
        {ip_string_to_uint("10.0.0.0"), ip_string_to_uint("255.0.0.0"), BLOCK},
        {ip_string_to_uint("192.168.0.0"), ip_string_to_uint("255.255.0.0"), BLOCK},
        {ip_string_to_uint("172.16.0.0"), ip_string_to_uint("255.240.0.0"), BLOCK},
        {ip_string_to_uint("192.168.1.100"), ip_string_to_uint("255.255.255.255"), ALLOW}
    };
    
    // Define an example IP packet
    struct IpHeader ip_header;
    ip_header.version_and_header_length = 0x45;
    ip_header.differentiated_services_field = 0x00;
    ip_header.total_length = htons(0x0030);
    ip_header.identification = htons(0x0001);
    ip_header.flags_and_fragment_offset = htons(0x4000);
    ip_header.time_to_live = 0x80;
    ip_header.protocol = 0x06;  // TCP
    ip_header.header_checksum = htons(0x1234);
    ip_header.source_address = ip_string_to_uint("192.168.0.10");
    ip_header.destination_address = ip_string_to_uint("8.8.8.8");
    
    // Apply the firewall rules to the IP packet
    bool is_allowed = apply_firewall_rules(&ip_header, firewall_rules, num_rules);
    
    // Print the result
    if (is_allowed) {
        printf("The packet is allowed!\n");
    } else {
        printf("The packet is blocked!\n");
    }
    
    return 0;
}