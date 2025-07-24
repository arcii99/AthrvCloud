//FormAI DATASET v1.0 Category: Firewall ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_LEN 100

typedef struct {
    char saddr[MAX_LEN];
    char daddr[MAX_LEN];
    int sport;
    int dport;
} Rule;

Rule rules[MAX_RULES];
int num_rules = 0;

int packet_filter(char *packet) {
    char saddr[MAX_LEN], daddr[MAX_LEN];
    int sport = 0, dport = 0;

    // extract source and destination ip addresses
    sscanf(packet, "%s %s %d %d", saddr, daddr, &sport, &dport);

    // check if packet matches any of the rules
    for (int i = 0; i < num_rules; i++) {
        if ((strcmp(rules[i].saddr, saddr) == 0 || strcmp(rules[i].saddr, "*") == 0) &&
            (strcmp(rules[i].daddr, daddr) == 0 || strcmp(rules[i].daddr, "*") == 0) &&
            (rules[i].sport == sport || rules[i].sport == 0) &&
            (rules[i].dport == dport || rules[i].dport == 0)) {
            // packet matches a rule, allow it
            return 1;
        }
    }

    // packet doesn't match any rule, drop it
    return 0;
}

void add_rule(char *rule_str) {
    if (num_rules >= MAX_RULES) {
        printf("Max rules reached!\n");
        return;
    }

    // parse the rule
    char saddr[MAX_LEN], daddr[MAX_LEN], sport_str[MAX_LEN], dport_str[MAX_LEN];
    int sport, dport;
    sscanf(rule_str, "%s %s %s %s", saddr, daddr, sport_str, dport_str);

    if (strcmp(saddr, "*") != 0 && strcmp(daddr, "*") != 0) {
        // at least one address must be wildcard
        printf("Invalid rule!\n");
        return;
    }

    if (strcmp(sport_str, "*") == 0) {
        sport = 0;
    } else {
        sport = atoi(sport_str);
    }

    if (strcmp(dport_str, "*") == 0) {
        dport = 0;
    } else {
        dport = atoi(dport_str);
    }

    // add the rule
    strcpy(rules[num_rules].saddr, saddr);
    strcpy(rules[num_rules].daddr, daddr);
    rules[num_rules].sport = sport;
    rules[num_rules].dport = dport;
    num_rules++;

    printf("Rule added: %s\n", rule_str);
}

void print_rules() {
    printf("Rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("%s %s ", rules[i].saddr, rules[i].daddr);
        if (rules[i].sport == 0) {
            printf("* ");
        } else {
            printf("%d ", rules[i].sport);
        }
        if (rules[i].dport == 0) {
            printf("*\n");
        } else {
            printf("%d\n", rules[i].dport);
        }
    }
}

int main() {
    while (1) {
        printf("Enter a command (add, print, filter): ");

        char cmd[MAX_LEN];
        fgets(cmd, MAX_LEN, stdin);
        cmd[strcspn(cmd, "\n")] = 0;

        if (strcmp(cmd, "add") == 0) {
            printf("Enter a rule (src_ip dst_ip src_port dst_port): ");

            char rule_str[MAX_LEN];
            fgets(rule_str, MAX_LEN, stdin);
            rule_str[strcspn(rule_str, "\n")] = 0;

            add_rule(rule_str);
        } else if (strcmp(cmd, "print") == 0) {
            print_rules();
        } else if (strcmp(cmd, "filter") == 0) {
            printf("Enter a packet (src_ip dst_ip src_port dst_port): ");

            char packet[MAX_LEN];
            fgets(packet, MAX_LEN, stdin);
            packet[strcspn(packet, "\n")] = 0;

            if (packet_filter(packet)) {
                printf("Packet allowed\n");
            } else {
                printf("Packet dropped\n");
            }
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}