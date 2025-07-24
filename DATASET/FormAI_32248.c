//FormAI DATASET v1.0 Category: Firewall ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Function to check if a given string is a valid IP address
int is_valid_ip(char* ip) {
    int seg1, seg2, seg3, seg4;
    if(sscanf(ip, "%d.%d.%d.%d", &seg1, &seg2, &seg3, &seg4) != 4) {
        return 0; // Not a valid IP address
    }
    if(seg1 < 0 || seg1 > 255 || seg2 < 0 || seg2 > 255 || seg3 < 0 || seg3 > 255 || seg4 < 0 || seg4 > 255) {
        return 0; // Out of range IP address
    }
    return 1;
}

// Function to check if a given string is a valid port number
int is_valid_port(char* port) {
    for(int i=0; i<strlen(port); i++) {
        if(!isdigit(port[i])) {
            return 0; // Invalid port number
        }
    }
    int p = atoi(port);
    if(p < 0 || p > 65535) {
        return 0; // Out of range port number
    }
    return 1;
}

// Function to check if a given line of input is a valid firewall rule
int is_valid_rule(char* rule) {
    char* token = strtok(rule, " ");
    if(token == NULL || strcmp(token, "allow") != 0 && strcmp(token, "deny") != 0) {
        return 0; // Invalid action
    }
    token = strtok(NULL, " ");
    if(token == NULL || strcmp(token, "in") != 0 && strcmp(token, "out") != 0) {
        return 0; // Invalid direction
    }
    token = strtok(NULL, " ");
    if(token == NULL || !is_valid_ip(token) && strcmp(token, "any") != 0) {
        return 0; // Invalid source IP address
    }
    token = strtok(NULL, " ");
    if(token == NULL || !is_valid_port(token) && strcmp(token, "any") != 0) {
        return 0; // Invalid source port number
    }
    token = strtok(NULL, " ");
    if(token == NULL || !is_valid_ip(token) && strcmp(token, "any") != 0) {
        return 0; // Invalid destination IP address
    }
    token = strtok(NULL, " ");
    if(token == NULL || !is_valid_port(token) && strcmp(token, "any") != 0) {
        return 0; // Invalid destination port number
    }
    return 1; // Valid firewall rule
}

// Recursive function to process firewall rules
void process_rules(char* rules[], int n) {
    if(n == 0) {
        printf("All rules processed.\n");
        return; // Base case
    }
    char* rule = rules[n-1]; // Process the last rule first
    if(!is_valid_rule(rule)) {
        printf("Invalid rule: %s\n", rule);
    } else {
        printf("Processing rule: %s\n", rule);
        // Process the rule here
    }
    process_rules(rules, n-1); // Recurse on the remaining rules
}

int main() {
    char* rules[] = {
        "allow in any any any", 
        "deny out 192.168.1.1 80 any", 
        "allow in 192.168.1.2 22 192.168.1.1 22", 
        "deny in 192.168.1.3 any 192.168.1.1 any", 
        "allow out any any any"
    };
    int n = sizeof(rules) / sizeof(rules[0]);
    process_rules(rules, n);
    return 0;
}