//FormAI DATASET v1.0 Category: Firewall ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Firewall structure declaration */
struct firewall_rule {
    char source_ip[16];
    char destination_ip[16];
    int port;
    char protocol[4];
    int action;
};

/* Function to add a new firewall rule */
void add_rule(struct firewall_rule **rules, int *num_rules);

/* Function to allow or block traffic based on firewall rules */
void filter_traffic(struct firewall_rule *rules, int num_rules, char *packet);

/* Main function */
int main() {
    int num_rules = 0;
    struct firewall_rule *rules = NULL;
    char packet[50];

    /* Add some sample rules */
    strcpy(packet, "10.0.0.2,10.0.0.5,80,tcp");
    add_rule(&rules, &num_rules);
    strcpy(packet, "10.0.0.3,10.0.0.5,22,tcp");
    add_rule(&rules, &num_rules);
    strcpy(packet, "10.0.0.4,10.0.0.5,53,udp");
    add_rule(&rules, &num_rules);

    /* Filter incoming traffic */
    strcpy(packet, "10.0.0.2,10.0.0.5,80,tcp");
    filter_traffic(rules, num_rules, packet);
    strcpy(packet, "10.0.0.3,10.0.0.5,22,tcp");
    filter_traffic(rules, num_rules, packet);
    strcpy(packet, "10.0.0.4,10.0.0.5,53,udp");
    filter_traffic(rules, num_rules, packet);

    /* Free resources */
    free(rules);

    return 0;
}

/* Function to add a new firewall rule */
void add_rule(struct firewall_rule **rules, int *num_rules) {
    struct firewall_rule *new_rule = realloc(*rules, (*num_rules + 1) * sizeof(struct firewall_rule));
    if (new_rule == NULL) {
        printf("Error: Failed to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    *rules = new_rule;
    printf("Enter source IP: ");
    scanf("%s", (*rules)[*num_rules].source_ip);
    printf("Enter destination IP: ");
    scanf("%s", (*rules)[*num_rules].destination_ip);
    printf("Enter port number: ");
    scanf("%d", &((*rules)[*num_rules].port));
    printf("Enter protocol (tcp/udp): ");
    scanf("%s", (*rules)[*num_rules].protocol);
    printf("Enter action (0=block/1=allow): ");
    scanf("%d", &((*rules)[*num_rules].action));
    (*num_rules)++;
}

/* Function to allow or block traffic based on firewall rules */
void filter_traffic(struct firewall_rule *rules, int num_rules, char *packet) {
    char *tok = strtok(packet, ",");
    char source_ip[16], destination_ip[16], protocol[4];
    int port, action;

    /* Parse incoming packet */
    strcpy(source_ip, tok);
    tok = strtok(NULL, ",");
    strcpy(destination_ip, tok);
    tok = strtok(NULL, ",");
    port = atoi(tok);
    tok = strtok(NULL, ",");
    strcpy(protocol, tok);

    /* Check if packet matches any firewall rules */
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].source_ip, source_ip) == 0 &&
            strcmp(rules[i].destination_ip, destination_ip) == 0 &&
            rules[i].port == port &&
            strcmp(rules[i].protocol, protocol) == 0) {
            action = rules[i].action;
            break;
        }
    }

    /* Take action based on firewall rule */
    if (action == 0) {
        printf("Packet blocked!\n");
    } else if (action == 1) {
        printf("Packet allowed!\n");
    } else {
        printf("Error: Invalid action!\n");
        exit(EXIT_FAILURE);
    }
}