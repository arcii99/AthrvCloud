//FormAI DATASET v1.0 Category: Firewall ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIP 20
#define MAXRULES 50

// a structure to hold a firewall rule
struct rule {
    char protocol[10];
    char source_ip[MAXIP];
    char destination_ip[MAXIP];
    int source_port;
    int destination_port;
};

// an array to hold our rules
struct rule firewall_rules[MAXRULES];

// a function to add a new rule to the firewall
void add_rule(char *protocol, char *source_ip, char *destination_ip, int source_port, int destination_port) {
    // check if we have reached the maximum limit of rules
    if (sizeof(firewall_rules) == MAXRULES * sizeof(struct rule)) {
        printf("Firewall rule limit reached!\n");
        return;
    }

    // create a new rule and add it to the array
    struct rule new_rule;
    strcpy(new_rule.protocol, protocol);
    strcpy(new_rule.source_ip, source_ip);
    strcpy(new_rule.destination_ip, destination_ip);
    new_rule.source_port = source_port;
    new_rule.destination_port = destination_port;

    firewall_rules[sizeof(firewall_rules) / sizeof(struct rule)] = new_rule;
    printf("New firewall rule added.\n");
}

// a function to check if a connection is allowed
int is_allowed(char *protocol, char *source_ip, char *destination_ip, int source_port, int destination_port) {
    // loop through all the rules in the array and check each one
    for (int i = 0; i < sizeof(firewall_rules) / sizeof(struct rule); i++) {
        if (strcmp(firewall_rules[i].protocol, protocol) == 0 || strcmp(firewall_rules[i].protocol, "*") == 0) {
            if (strcmp(firewall_rules[i].source_ip, source_ip) == 0 || strcmp(firewall_rules[i].source_ip, "*") == 0) {
                if (strcmp(firewall_rules[i].destination_ip, destination_ip) == 0 || strcmp(firewall_rules[i].destination_ip, "*") == 0) {
                    if (firewall_rules[i].source_port == source_port || firewall_rules[i].source_port == 0) {
                        if (firewall_rules[i].destination_port == destination_port || firewall_rules[i].destination_port == 0) {
                            printf("Connection allowed by firewall rule.\n");
                            return 1;
                        }
                    }
                }
            }
        }
    }

    printf("Connection blocked by firewall.\n");
    return 0;
}

int main() {
    // add some rules to the firewall
    add_rule("TCP", "192.168.1.100", "*", 0, 80);
    add_rule("UDP", "*", "192.168.1.101", 0, 53);
    add_rule("*", "*", "*", 0, 0);

    // test some connections
    is_allowed("TCP", "192.168.1.100", "192.168.1.200", 1234, 80);
    is_allowed("UDP", "192.168.1.150", "192.168.1.101", 53, 0);
    is_allowed("UDP", "192.168.1.200", "192.168.1.250", 1234, 80);

    return 0;
}