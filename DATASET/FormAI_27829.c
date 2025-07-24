//FormAI DATASET v1.0 Category: Firewall ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_IP_LENGTH 16

typedef struct {
    char source_ip[MAX_IP_LENGTH];
    char destination_ip[MAX_IP_LENGTH];
    int source_port;
    int destination_port;
    char protocol[4];
} FirewallRule;

typedef struct {
   FirewallRule rules[MAX_RULES];
   int num_rules;
} Firewall;

int match_rule(FirewallRule *rule, char *source_ip, char *destination_ip, int source_port, int destination_port, char *protocol) {
    if (strcmp(rule->source_ip, source_ip) != 0) {
        return 0;
    }
    if (strcmp(rule->destination_ip, destination_ip) != 0) {
        return 0;
    }
    if (rule->source_port != source_port) {
        return 0;
    }
    if (rule->destination_port != destination_port) {
        return 0;
    }
    if (strcmp(rule->protocol, protocol) != 0) {
        return 0;
    }
    return 1;
}

int check_firewall(Firewall *fw, char *source_ip, char *destination_ip, int source_port, int destination_port, char *protocol) {
    int i;
    for (i = 0; i < fw->num_rules; i++) {
        if (match_rule(&fw->rules[i], source_ip, destination_ip, source_port, destination_port, protocol)) {
            return 1;
        }
    }
    return 0;
}

void add_rule(Firewall *fw, char *source_ip, char *destination_ip, int source_port, int destination_port, char *protocol) {
    if (fw->num_rules < MAX_RULES) {
        strncpy(fw->rules[fw->num_rules].source_ip, source_ip, MAX_IP_LENGTH);
        strncpy(fw->rules[fw->num_rules].destination_ip, destination_ip, MAX_IP_LENGTH);
        fw->rules[fw->num_rules].source_port = source_port;
        fw->rules[fw->num_rules].destination_port = destination_port;
        strncpy(fw->rules[fw->num_rules].protocol, protocol, 4);
        fw->num_rules++;
    }
}

int main() {
    Firewall fw;
    fw.num_rules = 0;
    add_rule(&fw, "192.168.1.1", "192.168.1.2", 80, 443, "tcp");
    add_rule(&fw, "192.168.1.3", "192.168.1.4", 8080, 22, "udp");
    add_rule(&fw, "192.168.1.5", "192.168.1.6", 53, 443, "tcp");
    add_rule(&fw, "192.168.1.7", "192.168.1.8", 22, 80, "tcp");

    char *source = "192.168.1.1";
    char *destination = "192.168.1.2";
    int source_port = 80;
    int destination_port = 443;
    char *protocol = "tcp";
    int is_allowed = check_firewall(&fw, source, destination, source_port, destination_port, protocol);

    if (is_allowed) {
        printf("Allowed\n");
    } else {
        printf("Not Allowed\n");
    }

    return 0;
}