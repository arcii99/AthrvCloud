//FormAI DATASET v1.0 Category: Firewall ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom struct to hold firewall rules
struct rule {
    char source[50];
    char destination[50];
    char action[10];
};

// Prints a given rule
void printRule(struct rule r) {
    printf("%s \t\t %s \t\t %s\n", r.source, r.destination, r.action);
}

int main() {
    // Initialize list of rules
    struct rule rules[100];
    int numRules = 0;

    // Display menu options
    printf("Welcome to the Firewall!\n");
    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Add a new rule\n");
        printf("2. View all rules\n");
        printf("3. Check a packet\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        // Handle user's choice
        switch (choice) {
            case 1: // Add a new rule
                printf("\nEnter the source IP address for the new rule: ");
                scanf("%s", rules[numRules].source);
                printf("Enter the destination IP address for the new rule: ");
                scanf("%s", rules[numRules].destination);
                printf("Enter the action for the new rule (allow/deny): ");
                scanf("%s", rules[numRules].action);

                printf("\nThe following rule was added:\n");
                printRule(rules[numRules]);

                // Increment number of rules
                numRules++;
                break;
            case 2: // View all rules
                printf("\n%-20s %-20s %-10s\n", "Source", "Destination", "Action");
                for (int i = 0; i < numRules; i++) {
                    printRule(rules[i]);
                }
                break;
            case 3: // Check a packet
                char source[50];
                char destination[50];

                printf("\nEnter the source IP address of the packet: ");
                scanf("%s", source);
                printf("Enter the destination IP address of the packet: ");
                scanf("%s", destination);

                // Check if packet matches any rules
                int matched = 0;
                for (int i = 0; i < numRules; i++) {
                    if (strcmp(rules[i].source, source) == 0 && strcmp(rules[i].destination, destination) == 0) {
                        printf("\nThe packet matches the following rule:\n");
                        printRule(rules[i]);
                        matched = 1;
                        break;
                    }
                } 

                if (!matched) {
                    printf("\nThe packet does not match any rules.\n");
                }
                break;
            case 4: // Exit
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    } while(1);
    return 0;
}