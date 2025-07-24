//FormAI DATASET v1.0 Category: Firewall ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 15
#define MAX_RULES 100

struct rule {
    char src_ip[MAX_IP_LENGTH+1];
    char dest_ip[MAX_IP_LENGTH+1];
    int port;
    char protocol[4];
};

int check_rule_validity(char* rule_string, struct rule* r) {
    char* token;
    int count = 0;
    token = strtok(rule_string, " ");
    while (token != NULL) {
        if (count == 0) {
            strncpy(r->src_ip, token, MAX_IP_LENGTH);
            r->src_ip[MAX_IP_LENGTH] = '\0';
        } else if (count == 1) {
            strncpy(r->dest_ip, token, MAX_IP_LENGTH);
            r->dest_ip[MAX_IP_LENGTH] = '\0';
        } else if (count == 2) {
            r->port = atoi(token);
        } else if (count == 3) {
            strncpy(r->protocol, token, 4);
            r->protocol[3] = '\0';
        } else {
            return -1;
        }
        count++;
        token = strtok(NULL, " ");
    }
    if (count != 4) {
        return -1;
    }
    return 0;
}

int main() {
    char rule_string[MAX_IP_LENGTH*2+7+4+1]; // "xxx.xxx.xxx.xxx xxx.xxx.xxx.xxx #### xxx"
    struct rule rules[MAX_RULES];
    char* input_ip = (char*)malloc(sizeof(char)*MAX_IP_LENGTH);
    int input_port;
    char* input_protocol = (char*)malloc(sizeof(char)*4);
    int num_rules = 0;

    // initialize rules array
    for (int i = 0; i < MAX_RULES; i++) {
        memset(rules[i].src_ip, 0, MAX_IP_LENGTH+1);
        memset(rules[i].dest_ip, 0, MAX_IP_LENGTH+1);
        memset(rules[i].protocol, 0, 4);
    }

    // read in rules until user enters "done"
    printf("Enter rules in the format 'xxx.xxx.xxx.xxx xxx.xxx.xxx.xxx #### xxx'\n");
    printf("Enter 'done' to finish entering rules\n");
    fgets(rule_string, MAX_IP_LENGTH*2+7+4+1, stdin);
    while (strcmp(rule_string, "done\n") != 0 && num_rules < MAX_RULES) {
        if (check_rule_validity(rule_string, &rules[num_rules]) != 0) {
            printf("Invalid rule entered\n");
        } else {
            num_rules++;
        }
        fgets(rule_string, MAX_IP_LENGTH*2+7+4+1, stdin);
    }

    // prompt user for input and check if it matches any rules
    printf("Enter destination IP address (xxx.xxx.xxx.xxx format): ");
    fgets(input_ip, MAX_IP_LENGTH, stdin);
    input_ip[strlen(input_ip)-1] = '\0'; // remove newline character from string
    printf("Enter destination port: ");
    scanf("%d", &input_port);
    printf("Enter protocol (max 3 characters): ");
    scanf("%s", input_protocol);
    int rule_match = 0;
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].dest_ip, input_ip) == 0 && rules[i].port == input_port && strcmp(rules[i].protocol, input_protocol) == 0) {
            printf("Input matches rule %d\n", i+1);
            rule_match = 1;
        }
    }
    if (!rule_match) {
        printf("Input does not match any rules\n");
    }

    return 0;
}