//FormAI DATASET v1.0 Category: Firewall ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FirewallRule {
    char source_address[16];
    char destination_address[16];
    int source_port;
    int destination_port;
};

struct Packet {
    char source_address[16];
    char destination_address[16];
    int source_port;
    int destination_port;
    char payload[256];
};

bool check_firewall_rule(struct FirewallRule rule, struct Packet packet) {

    if(strcmp(rule.source_address, packet.source_address) != 0) {
        return false;
    }

    if(strcmp(rule.destination_address, packet.destination_address) != 0) {
        return false;
    }

    if(rule.source_port != packet.source_port) {
        return false;
    }

    if(rule.destination_port != packet.destination_port) {
        return false;
    }

    return true;
}

int main() {

    struct FirewallRule rules[5] = {
        {"192.168.1.1", "192.168.2.1", 80, 8080},
        {"192.168.1.1", "192.168.2.2", 22, 22},
        {"192.168.1.2", "192.168.2.1", 1000, 2000},
        {"192.168.1.2", "192.168.2.2", 443, 443},
        {"192.168.1.3", "192.168.2.3", 21, 21}
    };

    struct Packet packets[7] = {
        {"192.168.1.1", "192.168.2.1", 80, 8080, "HTTP REQUEST"},
        {"192.168.1.1", "192.168.2.2", 22, 22, "SSH REQUEST"},
        {"192.168.1.1", "192.168.2.2", 443, 443, "SSL REQUEST"},
        {"192.168.1.2", "192.168.2.1", 1000, 2000, "CUSTOM REQUEST"},
        {"192.168.1.2", "192.168.2.2", 443, 80, "INVALID REQUEST"},
        {"192.168.1.3", "192.168.2.3", 21, 21, "FTP REQUEST"},
        {"192.168.1.4", "192.168.2.4", 5000, 5000, "TEST REQUEST"}
    };

    int num_rules = sizeof(rules) / sizeof(struct FirewallRule);
    int num_packets = sizeof(packets) / sizeof(struct Packet);

    for(int i=0; i<num_packets; i++) {
        bool allowed = false;
        for(int j=0; j<num_rules; j++) {
            if(check_firewall_rule(rules[j], packets[i])) {
                printf("ALLOWED: %s -> %s : %d -> %d (%s)\n", 
                       packets[i].source_address, 
                       packets[i].destination_address, 
                       packets[i].source_port,
                       packets[i].destination_port,
                       packets[i].payload);
                allowed = true;
                break;
            }
        }
        if(!allowed) {
            printf("DENIED: %s -> %s : %d -> %d (%s)\n", 
                   packets[i].source_address, 
                   packets[i].destination_address, 
                   packets[i].source_port,
                   packets[i].destination_port,
                   packets[i].payload);
        }
    }

    return 0;
}