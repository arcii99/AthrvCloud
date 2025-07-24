//FormAI DATASET v1.0 Category: Firewall ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100

// Structure for holding a firewall rule
typedef struct {
    char protocol[10];
    char sourceIP[20];
    char destinationIP[20];
} FirewallRule;

int main() {
    FirewallRule rules[MAX_RULES];
    int numRules = 0;

    // Add some example rules
    strcpy(rules[numRules].protocol, "TCP");
    strcpy(rules[numRules].sourceIP, "192.168.1.1");
    strcpy(rules[numRules].destinationIP, "192.168.1.2");
    numRules++;

    strcpy(rules[numRules].protocol, "UDP");
    strcpy(rules[numRules].sourceIP, "192.168.1.3");
    strcpy(rules[numRules].destinationIP, "192.168.1.4");
    numRules++;

    // Prompt the user for input
    printf("Enter a rule in the format [protocol] [sourceIP] [destinationIP]:\n");
    char input[50];
    fgets(input, sizeof(input), stdin);

    // Parse the input and add it as a rule
    char* protocol = strtok(input, " ");
    char* sourceIP = strtok(NULL, " ");
    char* destinationIP = strtok(NULL, " ");
    if (protocol != NULL && sourceIP != NULL && destinationIP != NULL) {
        if (numRules < MAX_RULES) {
            strcpy(rules[numRules].protocol, protocol);
            strcpy(rules[numRules].sourceIP, sourceIP);
            strcpy(rules[numRules].destinationIP, destinationIP);
            numRules++;
            printf("Rule added.\n");
        } else {
            printf("Error: Maximum number of rules exceeded.\n");
        }
    } else {
        printf("Invalid input.\n");
    }

    // Check if incoming traffic matches any of the rules
    printf("Enter the incoming traffic details:\n");
    printf("Protocol: ");
    char incomingProtocol[10];
    scanf("%s", incomingProtocol);

    printf("Source IP: ");
    char incomingSourceIP[20];
    scanf("%s", incomingSourceIP);

    printf("Destination IP: ");
    char incomingDestinationIP[20];
    scanf("%s", incomingDestinationIP);

    int match = 0;
    for (int i = 0; i < numRules; i++) {
        if (strcmp(incomingProtocol, rules[i].protocol) == 0 &&
            strcmp(incomingSourceIP, rules[i].sourceIP) == 0 &&
            strcmp(incomingDestinationIP, rules[i].destinationIP) == 0) {
            printf("Incoming traffic matches rule %d.\n", i+1);
            match = 1;
            break;
        }
    }
    if (!match) {
        printf("Incoming traffic does not match any rules.\n");
    }

    return 0;
}