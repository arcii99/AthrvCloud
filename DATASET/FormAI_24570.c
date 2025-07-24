//FormAI DATASET v1.0 Category: Firewall ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256
#define MAX_IPS 1000

typedef struct {
    char* ip;
    char* rules[10];
    int num_rules;
} Firewall;

int num_ips = 0;
Firewall* firewall_rules[MAX_IPS];

void add_rule(char* ip, char* rule) {
    // Search for IP in existing rules
    int ip_index = -1;
    for (int i = 0; i < num_ips; i++) {
        if (strcmp(firewall_rules[i]->ip, ip) == 0) {
            ip_index = i;
            break;
        }
    }

    if (ip_index == -1) { // IP not found, create new entry
        Firewall* new_rule = malloc(sizeof(Firewall));
        new_rule->ip = strdup(ip);
        new_rule->num_rules = 0;
        firewall_rules[num_ips++] = new_rule;
        ip_index = num_ips - 1;
    }

    firewall_rules[ip_index]->rules[firewall_rules[ip_index]->num_rules++] = strdup(rule);
}

int check_rule(char* ip, char* action) {
    for (int i = 0; i < num_ips; i++) {
        if (strcmp(firewall_rules[i]->ip, ip) == 0) {
            for (int j = 0; j < firewall_rules[i]->num_rules; j++) {
                if (strcmp(firewall_rules[i]->rules[j], action) == 0) {
                    return 1; // Rule found
                }
            }
            break;
        }
    }
    return 0; // Rule not found
}

void print_rules() {
    printf("\nFirewall rules:\n\n");
    for (int i = 0; i < num_ips; i++) {
        printf("IP: %s\n", firewall_rules[i]->ip);
        for (int j = 0; j < firewall_rules[i]->num_rules; j++) {
            printf("- %s\n", firewall_rules[i]->rules[j]);
        }
        printf("\n");
    }
}

int main() {
    char input[MAX_LENGTH];

    printf("C Firewall Example Program\n");
    printf("Type 'exit' to quit, 'add' to add a rule and 'check' to check a rule.\n");

    while (1) {
        printf("\nEnter command: ");
        fgets(input, MAX_LENGTH, stdin);

        if (strncmp(input, "exit", 4) == 0) {
            break;
        } else if (strncmp(input, "add", 3) == 0) {
            char ip[MAX_LENGTH], rule[MAX_LENGTH];
            printf("Enter IP: ");
            fgets(ip, MAX_LENGTH, stdin);
            ip[strcspn(ip, "\n")] = 0;
            printf("Enter rule: ");
            fgets(rule, MAX_LENGTH, stdin);
            rule[strcspn(rule, "\n")] = 0;
            add_rule(ip, rule);

        } else if (strncmp(input, "check", 5) == 0) {
            char ip[MAX_LENGTH], rule[MAX_LENGTH];
            printf("Enter IP: ");
            fgets(ip, MAX_LENGTH, stdin);
            ip[strcspn(ip, "\n")] = 0;
            printf("Enter rule: ");
            fgets(rule, MAX_LENGTH, stdin);
            rule[strcspn(rule, "\n")] = 0;
            if (check_rule(ip, rule)) {
                printf("Rule found\n");
            } else {
                printf("Rule not found\n");
            }

        } else if (strncmp(input, "print", 5) == 0) {
            print_rules();

        } else {
            printf("Invalid command\n");
        }
    }

    // Free memory
    for (int i = 0; i < num_ips; i++) {
        for (int j = 0; j < firewall_rules[i]->num_rules; j++) {
            free(firewall_rules[i]->rules[j]);
        }
        free(firewall_rules[i]->ip);
        free(firewall_rules[i]);
    }

    return 0;
}