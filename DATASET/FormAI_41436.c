//FormAI DATASET v1.0 Category: Firewall ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 50

struct Rule {
    char source_ip[16];
    char dest_ip[16];
    int source_port;
    int dest_port;
    char action[6];
};

void parse_rule(char* line, struct Rule* rule) {
    char* token;
    int i = 0;
    token = strtok(line, ",");
    while (token != NULL) {
        if (i == 0) {
            strcpy(rule->source_ip, token);
        }
        else if (i == 1) {
            strcpy(rule->dest_ip, token);
        }
        else if (i == 2) {
            rule->source_port = atoi(token);
        }
        else if (i == 3) {
            rule->dest_port = atoi(token);
        }
        else if (i == 4) {
            strcpy(rule->action, token);
        }
        i++;
        token = strtok(NULL, ",");
    }
}

int is_rule_applicable(char* source_ip, char* dest_ip, int source_port, int dest_port, struct Rule* rule) {
    if (strcmp(source_ip, rule->source_ip) == 0 || strcmp(rule->source_ip, "*") == 0) {
        if (strcmp(dest_ip, rule->dest_ip) == 0 || strcmp(rule->dest_ip, "*") == 0) {
            if (source_port == rule->source_port || rule->source_port == -1) {
                if (dest_port == rule->dest_port || rule->dest_port == -1) {
                    if (strcmp(rule->action, "block") == 0) {
                        return 0; // Block the traffic
                    }
                    else if (strcmp(rule->action, "allow") == 0) {
                        return 1; // Allow the traffic
                    }
                }
            }
        }
    }
    return -1; // No match found for the traffic
}

int main() {
    FILE *fp;
    char line[100];
    struct Rule rules[MAX_RULES];
    int num_rules = 0;

    fp = fopen("rules.csv", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, 100, fp) != NULL) {
        parse_rule(line, &rules[num_rules]);
        num_rules++;
    }

    fclose(fp);

    char source_ip[16], dest_ip[16];
    int source_port, dest_port;

    printf("Enter source IP: ");
    scanf("%s", source_ip);
    printf("Enter destination IP: ");
    scanf("%s", dest_ip);
    printf("Enter source port: ");
    scanf("%d", &source_port);
    printf("Enter destination port: ");
    scanf("%d", &dest_port);

    int i;
    for (i = 0; i < num_rules; i++) {
        int result = is_rule_applicable(source_ip, dest_ip, source_port, dest_port, &rules[i]);
        if (result == 0) {
            printf("Traffic blocked\n");
            return 0;
        }
        else if (result == 1) {
            printf("Traffic allowed\n");
            return 0;
        }
    }

    printf("No rule applicable, traffic blocked by default\n");
    return 0;
}