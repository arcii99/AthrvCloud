//FormAI DATASET v1.0 Category: Firewall ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IP 50
#define MAX_RULES 1000
#define MAX_LINE 200

// structure to hold firewall rules
typedef struct rule {
    char protocol[10];
    char source_ip[MAX_IP];
    char destination_ip[MAX_IP];
    int source_port;
    int destination_port;
    bool allow;
} Rule;

// function prototypes
void print_rules(Rule rules[], int num_rules);
void add_rule(Rule rules[], int *num_rules);
void delete_rule(Rule rules[], int *num_rules);
void clear_rules(Rule rules[], int *num_rules);
bool check_packet(Rule rules[], int num_rules, char *protocol, char *source_ip,
                  char *destination_ip, int source_port, int destination_port);

int main() {

    char command[MAX_LINE];
    Rule rules[MAX_RULES];
    int num_rules = 0;

    printf("Welcome to the Firewall Program.\n");

    while (true) {
        printf("Enter a command (add, delete, print, clear, check, quit): ");
        fgets(command, MAX_LINE, stdin);
        command[strcspn(command, "\n")] = 0; // remove newline character

        if (strcmp(command, "add") == 0) {
            add_rule(rules, &num_rules);
        } else if (strcmp(command, "delete") == 0) {
            delete_rule(rules, &num_rules);
        } else if (strcmp(command, "print") == 0) {
            print_rules(rules, num_rules);
        } else if (strcmp(command, "clear") == 0) {
            clear_rules(rules, &num_rules);
        } else if (strcmp(command, "check") == 0) {
            char protocol[10];
            char source_ip[MAX_IP];
            char destination_ip[MAX_IP];
            int source_port;
            int destination_port;
            printf("Enter the protocol (tcp/udp/icmp): ");
            scanf("%s", protocol);
            printf("Enter the source IP address: ");
            scanf("%s", source_ip);
            printf("Enter the destination IP address: ");
            scanf("%s", destination_ip);
            printf("Enter the source port number: ");
            scanf("%d", &source_port);
            printf("Enter the destination port number: ");
            scanf("%d", &destination_port);
            if (check_packet(rules, num_rules, protocol, source_ip, destination_ip,
                             source_port, destination_port)) {
                printf("Packet is allowed.\n");
            } else {
                printf("Packet is blocked.\n");
            }
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    printf("Exiting Firewall Program.\n");

    return 0;
}

// function to print all the firewall rules
void print_rules(Rule rules[], int num_rules) {
    printf("Firewall rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("%s %s %s %d %d %s\n", rules[i].protocol, rules[i].source_ip,
               rules[i].destination_ip, rules[i].source_port,
               rules[i].destination_port, rules[i].allow ? "allow" : "deny");
    }
}

// function to add a new firewall rule
void add_rule(Rule rules[], int *num_rules) {
    if (*num_rules == MAX_RULES) {
        printf("Firewall rules limit reached.\n");
        return;
    }
    printf("Enter the protocol (tcp/udp/icmp): ");
    scanf("%s", rules[*num_rules].protocol);
    printf("Enter the source IP address: ");
    scanf("%s", rules[*num_rules].source_ip);
    printf("Enter the destination IP address: ");
    scanf("%s", rules[*num_rules].destination_ip);
    printf("Enter the source port number: ");
    scanf("%d", &rules[*num_rules].source_port);
    printf("Enter the destination port number: ");
    scanf("%d", &rules[*num_rules].destination_port);
    printf("Allow or block packet? (allow/deny): ");
    char allow[MAX_LINE];
    scanf("%s", allow);
    rules[*num_rules].allow = (strcmp(allow, "allow") == 0);
    (*num_rules)++;
    printf("Firewall rule added.\n");
}

// function to delete a firewall rule
void delete_rule(Rule rules[], int *num_rules) {
    if (*num_rules == 0) {
        printf("No firewall rules to delete.\n");
        return;
    }
    printf("Enter the number of the rule to delete: ");
    int rule_number;
    scanf("%d", &rule_number);
    if (rule_number < 1 || rule_number > *num_rules) {
        printf("Invalid rule number.\n");
        return;
    }
    for (int i = rule_number - 1; i < *num_rules - 1; i++) {
        rules[i] = rules[i + 1];
    }
    (*num_rules)--;
    printf("Firewall rule deleted.\n");
}

// function to clear all the firewall rules
void clear_rules(Rule rules[], int *num_rules) {
    *num_rules = 0;
    printf("All firewall rules cleared.\n");
}

// function to check if a packet is allowed or blocked
bool check_packet(Rule rules[], int num_rules, char *protocol, char *source_ip,
                  char *destination_ip, int source_port, int destination_port) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].protocol, protocol) == 0 &&
            strcmp(rules[i].source_ip, source_ip) == 0 &&
            strcmp(rules[i].destination_ip, destination_ip) == 0 &&
            (rules[i].source_port == source_port || rules[i].source_port == 0) &&
            (rules[i].destination_port == destination_port || rules[i].destination_port == 0)) {
            return rules[i].allow;
        }
    }
    return false; // default deny
}