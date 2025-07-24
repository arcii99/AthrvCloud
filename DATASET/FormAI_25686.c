//FormAI DATASET v1.0 Category: Firewall ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IP_LEN 16    // Maximum length of IPv4 address
#define MAX_RULES 100    // Maximum number of rules in the firewall
#define ALLOW 1          // The rule allows access
#define BLOCK 0          // The rule blocks access

typedef struct {
    char ip[MAX_IP_LEN];
    bool status;
} Rule;

int num_rules = 0;
Rule rules[MAX_RULES];

// Function to check if an IP address matches a rule
bool match_rule(char* ip) {
    for(int i = 0; i < num_rules; i++) {
        if(strcmp(rules[i].ip, ip) == 0) {
            return rules[i].status;
        }
    }
    return ALLOW;
}

int main() {
    char input[MAX_IP_LEN];
    char command[MAX_IP_LEN];
    bool status;
    
    // Initialize the rules to allow all traffic
    for(int i = 0; i < MAX_RULES; i++) {
        strcpy(rules[i].ip, "");
        rules[i].status = ALLOW;
    }
    
    printf("Firewall Initialized. Enter commands:\n");
    
    while(true) {
        // Read command from user
        fgets(input, MAX_IP_LEN, stdin);
        sscanf(input, "%s %s", command, input);
        
        // Exit program
        if(strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        
        // Add or remove rule
        else if(strcmp(command, "allow") == 0 || strcmp(command, "block") == 0) {
            if(num_rules < MAX_RULES) {
                strcpy(rules[num_rules].ip, input);
                rules[num_rules].status = strcmp(command, "allow") == 0 ? ALLOW : BLOCK;
                num_rules++;
                printf("Rule added.\n");
            } else {
                printf("Max number of rules reached.\n");
            }
        }
        
        // Check status of IP address
        else {
            status = match_rule(input);
            printf("IP: %s Status: %s\n", input, status == ALLOW ? "Allowed" : "Blocked");
        }
    }
    
    return 0;
}