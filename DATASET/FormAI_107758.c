//FormAI DATASET v1.0 Category: Firewall ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAXRULES 10
#define MAXLEN 256

struct Rule {
    char protocol[MAXLEN];
    char source_ip[MAXLEN];
    char dest_ip[MAXLEN];
    int source_port;
    int dest_port;
    bool allow;
};

void print_rule(struct Rule r) {
    printf("Protocol: %s\n", r.protocol);
    printf("Source IP: %s\n", r.source_ip);
    printf("Destination IP: %s\n", r.dest_ip);
    printf("Source port: %d\n", r.source_port);
    printf("Destination port: %d\n", r.dest_port);
    printf("Allow? %s\n", r.allow ? "Yes" : "No");
    printf("\n");
}

void add_rule(struct Rule *rules, int *num_rules) {
    if (*num_rules == MAXRULES) {
        printf("Error: max number of rules reached.\n\n");
        return;
    }

    struct Rule new_rule;

    printf("Enter the details of the new rule.\n");

    printf("Protocol (TCP or UDP): ");
    scanf("%s", new_rule.protocol);

    printf("Source IP: ");
    scanf("%s", new_rule.source_ip);

    printf("Destination IP: ");
    scanf("%s", new_rule.dest_ip);

    printf("Source port: ");
    scanf("%d", &new_rule.source_port);

    printf("Destination port: ");
    scanf("%d", &new_rule.dest_port);

    printf("Allow (y/n)? ");
    char response[MAXLEN];
    scanf("%s", response);
    new_rule.allow = (strncmp(response, "y", MAXLEN) == 0);

    rules[*num_rules] = new_rule;
    *num_rules += 1;

    printf("New rule added.\n\n");
}

void delete_rule(struct Rule *rules, int *num_rules) {
    if (*num_rules == 0) {
        printf("Error: no rules to delete.\n\n");
        return;
    }

    printf("Which rule do you want to delete? Enter the number (1-%d): ", *num_rules);
    int rule_number;
    scanf("%d", &rule_number);

    if (rule_number < 1 || rule_number > *num_rules) {
        printf("Error: invalid rule number.\n\n");
        return;
    }

    for (int i = rule_number - 1; i < *num_rules - 1; i++) {
        rules[i] = rules[i + 1];
    }

    *num_rules -= 1;
    printf("Rule #%d deleted.\n\n", rule_number);
}

void list_rules(struct Rule *rules, int num_rules) {
    if (num_rules == 0) {
        printf("No rules to display.\n\n");
        return;
    }

    printf("Current rules:\n\n");

    for (int i = 0; i < num_rules; i++) {
        printf("Rule #%d:\n", i + 1);
        print_rule(rules[i]);
    }
}

bool firewall(struct Rule *rules, int num_rules, char *protocol, char *source_ip, char *dest_ip, int source_port, int dest_port) {
    for (int i = 0; i < num_rules; i++) {
        struct Rule r = rules[i];
        if (strncmp(r.protocol, protocol, MAXLEN) == 0 &&
            strncmp(r.source_ip, source_ip, MAXLEN) == 0 &&
            strncmp(r.dest_ip, dest_ip, MAXLEN) == 0 &&
            r.source_port == source_port &&
            r.dest_port == dest_port) {
            return r.allow;
        }
    }

    return false;
}

int main() {
    struct Rule rules[MAXRULES];
    int num_rules = 0;

    while (true) {
        printf("Please choose an option:\n");
        printf("1. Add rule\n");
        printf("2. Delete rule\n");
        printf("3. List rules\n");
        printf("4. Check firewall\n");
        printf("5. Exit\n\n");

        int option;
        printf("Enter your choice (1-5): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_rule(rules, &num_rules);
                break;
            case 2:
                delete_rule(rules, &num_rules);
                break;
            case 3:
                list_rules(rules, num_rules);
                break;
            case 4:
                char protocol[MAXLEN], source_ip[MAXLEN], dest_ip[MAXLEN];
                int source_port, dest_port;

                printf("Enter the details of the packet.\n");

                printf("Protocol (TCP or UDP): ");
                scanf("%s", protocol);

                printf("Source IP: ");
                scanf("%s", source_ip);

                printf("Destination IP: ");
                scanf("%s", dest_ip);

                printf("Source port: ");
                scanf("%d", &source_port);

                printf("Destination port: ");
                scanf("%d", &dest_port);

                if (firewall(rules, num_rules, protocol, source_ip, dest_ip, source_port, dest_port)) {
                    printf("Packet allowed.\n\n");
                } else {
                    printf("Packet blocked.\n\n");
                }

                break;
            case 5:
                printf("Exiting.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n\n");
        }
    }

    return 0;
}