//FormAI DATASET v1.0 Category: Firewall ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024
#define MAX_RULES 1000

typedef struct {
    int protocol;
    int in_port;
    int out_port;
    char* source_ip;
    char* dest_ip;
} FirewallRule;

typedef struct {
    int packet_length;
    int protocol;
    int in_port;
    int out_port;
    char* source_ip;
    char* dest_ip;
} Packet;

FirewallRule firewall_rules[MAX_RULES];
int num_rules = 0;

void add_rule(FirewallRule rule) {
    if (num_rules >= MAX_RULES) {
        printf("Error: Maximum number of firewall rules has been reached.\n");
        return;
    }
    
    firewall_rules[num_rules++] = rule;
    printf("Rule added successfully.\n");
}

int check_packet(Packet packet) {
    for (int i = 0; i < num_rules; i++) {
        FirewallRule rule = firewall_rules[i];
        
        if (rule.protocol != packet.protocol) {
            continue;
        }
        if (rule.in_port != packet.in_port) {
            continue;
        }
        if (rule.out_port != packet.out_port) {
            continue;
        }
        if (strcmp(rule.source_ip, packet.source_ip) != 0) {
            continue;
        }
        if (strcmp(rule.dest_ip, packet.dest_ip) != 0) {
            continue;
        }
        
        return 1;
    }
    
    return 0;
}

int main() {
    srand(time(NULL));
    
    FirewallRule rule1 = {1, 80, -1, "192.168.0.1", ""};
    FirewallRule rule2 = {2, -1, 443, "192.168.0.1", ""};
    FirewallRule rule3 = {1, 22, -1, "192.168.0.2", ""};
    FirewallRule rule4 = {2, -1, 80, "192.168.0.2", ""};
    
    add_rule(rule1);
    add_rule(rule2);
    add_rule(rule3);
    add_rule(rule4);
    
    Packet packet1 = {56, 1, 80, -1, "192.168.0.1", "192.168.0.2"};
    Packet packet2 = {1024, 2, -1, 443, "192.168.0.1", "192.168.0.2"};
    Packet packet3 = {128, 1, 22, -1, "192.168.0.3", "192.168.0.2"};
    Packet packet4 = {512, 2, -1, 80, "192.168.0.2", "192.168.0.1"};
    
    printf("Checking packet1...\n");
    if (check_packet(packet1)) {
        printf("Packet1 allowed.\n");
    } else {
        printf("Packet1 blocked.\n");
    }
    
    printf("Checking packet2...\n");
    if (check_packet(packet2)) {
        printf("Packet2 allowed.\n");
    } else {
        printf("Packet2 blocked.\n");
    }
    
    printf("Checking packet3...\n");
    if (check_packet(packet3)) {
        printf("Packet3 allowed.\n");
    } else {
        printf("Packet3 blocked.\n");
    }
    
    printf("Checking packet4...\n");
    if (check_packet(packet4)) {
        printf("Packet4 allowed.\n");
    } else {
        printf("Packet4 blocked.\n");
    }
    
    return 0;
}