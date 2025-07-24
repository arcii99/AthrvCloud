//FormAI DATASET v1.0 Category: Firewall ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 15
#define MAX_RULES 10

typedef struct {
    char ip[MAX_IP_LENGTH];
    int port;
} Rule;

typedef struct {
    Rule rules[MAX_RULES];
    int count;
} Firewall;

void add_rule(Firewall* firewall, char* ip, int port) {
    if (firewall->count < MAX_RULES) {
        Rule rule;
        strcpy(rule.ip, ip);
        rule.port = port;
        
        firewall->rules[firewall->count++] = rule;
        printf("Rule added: %s, %d\n", ip, port);
    } else {
        printf("Cannot add more than %d rules\n", MAX_RULES);
    }
}

int is_allowed(Firewall* firewall, char* ip, int port) {
    for (int i = 0; i < firewall->count; i++) {
        Rule rule = firewall->rules[i];
        if (strcmp(rule.ip, ip) == 0 && rule.port == port) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    Firewall firewall;
    firewall.count = 0;
    
    add_rule(&firewall, "192.168.0.1", 80);
    add_rule(&firewall, "10.0.0.1", 22);
    add_rule(&firewall, "172.16.1.1", 443);
    
    printf("Allowed IP: 192.168.0.1, Port: 80: %s\n", is_allowed(&firewall, "192.168.0.1", 80) ? "Yes" : "No");
    printf("Allowed IP: 10.0.0.1, Port: 22: %s\n", is_allowed(&firewall, "10.0.0.1", 22) ? "Yes" : "No");
    printf("Allowed IP: 172.16.1.1, Port: 443: %s\n", is_allowed(&firewall, "172.16.1.1", 443) ? "Yes" : "No");
    printf("Allowed IP: 192.168.0.2, Port: 80: %s\n", is_allowed(&firewall, "192.168.0.2", 80) ? "Yes" : "No");
    
    return 0;
}