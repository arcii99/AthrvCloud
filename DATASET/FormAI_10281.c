//FormAI DATASET v1.0 Category: Firewall ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INPUT_SIZE 100 // Maximum size of input string
#define RULES_SIZE 100 // Maximum number of firewall rules

// Structure for a single firewall rule
typedef struct {
    char action[10];
    char protocol[10];
    char source_ip[20];
    char dest_ip[20];
    char source_port[10];
    char dest_port[10];
} FirewallRule;

// Structure for the firewall rules list
typedef struct {
    FirewallRule rules[RULES_SIZE];
    int size;
} FirewallRulesList;

// Function to add a rule to the firewall rules list
void add_rule(FirewallRulesList* rules_list, char* action, char* protocol, char* source_ip, char* dest_ip, char* source_port, char* dest_port) {
    if (rules_list->size < RULES_SIZE) {
        FirewallRule new_rule;
        strcpy(new_rule.action, action);
        strcpy(new_rule.protocol, protocol);
        strcpy(new_rule.source_ip, source_ip);
        strcpy(new_rule.dest_ip, dest_ip);
        strcpy(new_rule.source_port, source_port);
        strcpy(new_rule.dest_port, dest_port);
        rules_list->rules[rules_list->size++] = new_rule;
    }
}

// Function to check if a given IP address matches a given IP mask
bool match_ip(char* ip, char* mask) {
    int i = 0;
    while (mask[i] != '\0') {
        if (mask[i] == '*') {
            // Wildcard match
            return true;
        } else if (mask[i] != ip[i]) {
            // Mismatch
            return false;
        }
        i++;
    }
    // Complete match
    return true;
}

// Function to check if a given port number matches a given port range
bool match_port(char* port, char* range) {
    if (range[0] == '*' && range[1] == '\0') {
        // Wildcard match
        return true;
    }
    // Extract start and end port from range
    char* dash_pos = strchr(range, '-');
    if (dash_pos == NULL) {
        // Malformed range
        return false;
    }
    *dash_pos = '\0';
    int start_port = atoi(range);
    int end_port = atoi(dash_pos+1);
    int test_port = atoi(port);
    if (test_port >= start_port && test_port <= end_port) {
        // Match
        return true;
    } else {
        // Mismatch
        return false;
    }
}

// Function to parse and evaluate a single firewall rule against a network packet
bool evaluate_rule(FirewallRule* rule, char* protocol, char* source_ip, char* dest_ip, char* source_port, char* dest_port) {
    if (strcmp(rule->protocol, protocol) != 0 && strcmp(rule->protocol, "*") != 0) {
        // Protocol mismatch
        return false;
    }
    if (!match_ip(source_ip, rule->source_ip) || !match_ip(dest_ip, rule->dest_ip)) {
        // IP address mismatch
        return false;
    }
    if (!match_port(source_port, rule->source_port) || !match_port(dest_port, rule->dest_port)) {
        // Port number mismatch
        return false;
    }
    // Match found
    return true;
}

// Function to evaluate all rules in the firewall rules list against a network packet
void evaluate_all_rules(FirewallRulesList* rules_list, char* protocol, char* source_ip, char* dest_ip, char* source_port, char* dest_port) {
    bool permitted = false;
    for (int i = 0; i < rules_list->size; i++) {
        FirewallRule* rule = &rules_list->rules[i];
        if (evaluate_rule(rule, protocol, source_ip, dest_ip, source_port, dest_port)) {
            // Match found, determine action and exit loop
            if (strcmp(rule->action, "allow") == 0) {
                permitted = true;
                break;
            } else {
                permitted = false;
                break;
            }
        }
    }
    // Print result
    if (permitted) {
        printf("Packet is permitted.\n");
    } else {
        printf("Packet is NOT permitted.\n");
    }
}

int main() {
    // Initialize firewall rules list
    FirewallRulesList rules_list = {0};
    // Add some example rules
    add_rule(&rules_list, "allow", "tcp", "192.168.0.1", "192.168.0.2", "*", "80-90");
    add_rule(&rules_list, "block", "*", "192.168.0.3", "*", "*", "*");
    // Ask user to input a network packet for testing
    printf("Enter a network packet to evaluate: ");
    char input[INPUT_SIZE];
    fgets(input, INPUT_SIZE, stdin);
    // Parse input into protocol, IP addresses, and port numbers
    char* token = strtok(input, " ");
    char* protocol = token;
    token = strtok(NULL, " ");
    char* source_ip = token;
    token = strtok(NULL, " ");
    char* dest_ip = token;
    token = strtok(NULL, " ");
    char* source_port = token;
    token = strtok(NULL, " ");
    char* dest_port = token;
    // Evaluate the network packet against all rules
    evaluate_all_rules(&rules_list, protocol, source_ip, dest_ip, source_port, dest_port);
    return 0;
}