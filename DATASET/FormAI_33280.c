//FormAI DATASET v1.0 Category: Firewall ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100

typedef struct firewall_rule {
    char protocol[5];
    char source_address[20];
    char dest_address[20];
    int source_port_start;
    int source_port_end;
    int dest_port_start;
    int dest_port_end;
    int action;
} firewall_rule_t;

firewall_rule_t firewall_rules[MAX_RULES];

void add_firewall_rule(char* protocol, char* source_address, char* dest_address, 
                       int source_port_start, int source_port_end, 
                       int dest_port_start, int dest_port_end, int action) {
    static int num_rules = 0;
    
    if (num_rules > MAX_RULES) {
        printf("Error: Maximum number of rules reached.\n");
        return;
    }
    
    strcpy(firewall_rules[num_rules].protocol, protocol);
    strcpy(firewall_rules[num_rules].source_address, source_address);
    strcpy(firewall_rules[num_rules].dest_address, dest_address);
    firewall_rules[num_rules].source_port_start = source_port_start;
    firewall_rules[num_rules].source_port_end = source_port_end;
    firewall_rules[num_rules].dest_port_start = dest_port_start;
    firewall_rules[num_rules].dest_port_end = dest_port_end;
    firewall_rules[num_rules].action = action;
    
    num_rules++;
}

int is_firewall_rule_matched(char* protocol, char* source_address, char* dest_address,
                             int source_port, int dest_port) {
    for (int i = 0; i < MAX_RULES; i++) {
        if (strcmp(firewall_rules[i].protocol, protocol) == 0 &&
            strcmp(firewall_rules[i].source_address, source_address) == 0 &&
            strcmp(firewall_rules[i].dest_address, dest_address) == 0 &&
            source_port >= firewall_rules[i].source_port_start &&
            source_port <= firewall_rules[i].source_port_end &&
            dest_port >= firewall_rules[i].dest_port_start &&
            dest_port <= firewall_rules[i].dest_port_end) {
                return firewall_rules[i].action;
        }
    }
    
    return 0;
}

int main() {
    add_firewall_rule("tcp", "192.168.1.1", "192.168.2.2", 1024, 65535, 80, 80, 1);
    add_firewall_rule("udp", "192.168.1.1", "192.168.2.2", 1024, 65535, 53, 53, 0);
    
    int action = is_firewall_rule_matched("tcp", "192.168.1.1", "192.168.2.2", 8080, 80);
    printf("%s\n", action ? "Allow" : "Deny");
    
    return 0;
}