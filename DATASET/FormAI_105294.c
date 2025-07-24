//FormAI DATASET v1.0 Category: Firewall ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_LENGTH 1000

typedef struct rule {
    char source_address[16];
    char destination_address[16];
    int source_port;
    int destination_port;
    char protocol[4];
    char action[10];
} Rule;

Rule rules[MAX_RULES];

void parse_rule(char* rule_string, Rule* rule);
void add_rule(char* rule_string, int index);
int match_rule(char* source_address, char* destination_address, int source_port, int destination_port, char* protocol);

int main() {
    char input[MAX_LENGTH];
    int i;
    for(i=0; i<MAX_RULES; i++) {
        rules[i].source_port = -1;
        rules[i].destination_port = -1;
    }
    printf("Enter rules for firewall. Enter 'done' to stop adding rules.\n");
    i=0;
    while(1) {
        printf("Rule %d: ", i+1);
        fgets(input, MAX_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // remove newline
        if(strcmp(input, "done") == 0) {
            break;
        }
        add_rule(input, i);
        i++;
    }
    printf("All rules added. Firewall started.\n");

    char packet[MAX_LENGTH];
    printf("Enter packet to evaluate. Enter 'quit' to stop.\n");
    while(1) {
        printf("Packet: ");
        fgets(packet, MAX_LENGTH, stdin);
        packet[strcspn(packet, "\n")] = 0; // remove newline
        if(strcmp(packet, "quit") == 0) {
            break;
        }
        char* tok = strtok(packet, " ");
        char source_address[16];
        strcpy(source_address, tok);
        tok = strtok(NULL, " ");
        char destination_address[16];
        strcpy(destination_address, tok);
        tok = strtok(NULL, " ");
        int source_port = atoi(tok);
        tok = strtok(NULL, " ");
        int destination_port = atoi(tok);
        tok = strtok(NULL, " ");
        char protocol[4];
        strcpy(protocol, tok);
        int matched_rule = match_rule(source_address, destination_address, source_port, destination_port, protocol);
        if(matched_rule == -1) {
            printf("Packet dropped.\n");
        }
        else if(strcmp(rules[matched_rule].action, "allow") == 0) {
            printf("Packet allowed.\n");
        }
        else if(strcmp(rules[matched_rule].action, "deny") == 0) {
            printf("Packet denied.\n");
        }
    }
}

void parse_rule(char* rule_string, Rule* rule) {
    char* tok = strtok(rule_string, " ");
    strcpy(rule->source_address, tok);
    tok = strtok(NULL, " ");
    strcpy(rule->destination_address, tok);
    tok = strtok(NULL, " ");
    if(strcmp(tok, "any") != 0) {
        rule->source_port = atoi(tok);
    }
    tok = strtok(NULL, " ");
    if(strcmp(tok, "any") != 0) {
        rule->destination_port = atoi(tok);
    }
    tok = strtok(NULL, " ");
    strcpy(rule->protocol, tok);
    tok = strtok(NULL, " ");
    strcpy(rule->action, tok);
}

void add_rule(char* rule_string, int index) {
    parse_rule(rule_string, &rules[index]);
}

int match_rule(char* source_address, char* destination_address, int source_port, int destination_port, char* protocol) {
    int i;
    for(i=0; i<MAX_RULES; i++) {
        if(rules[i].source_port == -1 && rules[i].destination_port == -1) {
            // rule is for any port
            if(strcmp(rules[i].protocol, "any") == 0 || strcmp(rules[i].protocol, protocol) == 0) {
                if(strcmp(rules[i].source_address, "any") == 0 || strcmp(rules[i].source_address, source_address) == 0) {
                    if(strcmp(rules[i].destination_address, "any") == 0 || strcmp(rules[i].destination_address, destination_address) == 0) {
                        return i;
                    }
                }
            }
        }
        else {
            // rule is for specific ports
            if(rules[i].source_port == source_port && rules[i].destination_port == destination_port) {
                if(strcmp(rules[i].protocol, protocol) == 0) {
                    if(strcmp(rules[i].source_address, "any") == 0 || strcmp(rules[i].source_address, source_address) == 0) {
                        if(strcmp(rules[i].destination_address, "any") == 0 || strcmp(rules[i].destination_address, destination_address) == 0) {
                            return i;
                        }
                    }
                }
            }
        }
    }
    return -1;
}