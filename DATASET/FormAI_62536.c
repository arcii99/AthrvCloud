//FormAI DATASET v1.0 Category: Firewall ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX_RULES 1000
#define MAX_LINE_SIZE 100

struct Rule {
    char src_ip[16];
    char dest_ip[16];
    char protocol[10];
    int src_port;
    int dest_port;
    bool action;
};

struct Ruleset {
    struct Rule rules[MAX_RULES];
    int count;
};

/**
 * Reads the rules from the given file.
 */
bool read_rules(struct Ruleset* ruleset, const char* filename){
    FILE *file = fopen(filename, "r");
    if(file == NULL){
        printf("Error opening file\n");
        return false;
    }

    char line[MAX_LINE_SIZE];
    while(fgets(line, MAX_LINE_SIZE, file) != NULL){
        char *tokens[6];
        char *delimiters = " \t\n";
        int count = 0;
        tokens[count] = strtok(line, delimiters);
        while(tokens[count] && count < 5){
            count++;
            tokens[count] = strtok(NULL, delimiters);
        }

        if(count == 5 || count == 6){
            struct Rule rule;
            strcpy(rule.src_ip, tokens[0]);
            strcpy(rule.dest_ip, tokens[1]);
            strcpy(rule.protocol, tokens[2]);
            rule.src_port = atoi(tokens[3]);
            rule.dest_port = atoi(tokens[4]);
            rule.action = (count == 6) ? atoi(tokens[5]) : true;
            ruleset->rules[ruleset->count++] = rule;
        }
    }

    fclose(file);
    return true;
}

/**
 * Applies the rules to the given packet and returns true if it is allowed,
 * false if it is not allowed. 
 */
bool apply_rules(struct Ruleset ruleset, const char* packet){
    char src_ip[16], dest_ip[16], protocol[10];
    int src_port, dest_port;
    if(sscanf(packet, "%s %s %s %d %d",
              src_ip, dest_ip, protocol, &src_port, &dest_port) == 5){
        for(int i=0; i<ruleset.count; i++){
            struct Rule rule = ruleset.rules[i];
            if((strcmp(rule.src_ip, "*") == 0 || strcmp(rule.src_ip, src_ip) == 0) && 
               (strcmp(rule.dest_ip, "*") == 0 || strcmp(rule.dest_ip, dest_ip) == 0) && 
               (strcmp(rule.protocol, "*") == 0 || strcmp(rule.protocol, protocol) == 0) && 
               (rule.src_port == 0 || rule.src_port == src_port) && 
               (rule.dest_port == 0 || rule.dest_port == dest_port)){
                return rule.action;
            }
        }
    }

    return false;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Usage: %s <rules-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct Ruleset ruleset;
    ruleset.count = 0;

    if(!read_rules(&ruleset, argv[1])){
        return EXIT_FAILURE;
    }

    char packet[MAX_LINE_SIZE];
    while(fgets(packet, MAX_LINE_SIZE, stdin) != NULL){
        if(apply_rules(ruleset, packet)){
            printf("Packet allowed\n");
        } else {
            printf("Packet denied\n");
        }
    }

    return EXIT_SUCCESS;
}