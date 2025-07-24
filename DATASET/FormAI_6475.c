//FormAI DATASET v1.0 Category: Firewall ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
#define FIREWALL_SIZE 10

// Declare global variables
char firewall[FIREWALL_SIZE][MAX_SIZE];
int firewallIndex = 0;

// Declare helper functions
void printFirewall();
bool isIpAddress(char* address);

int main() {
    printf("Welcome to the medieval Firewall!\n");

    while(true) {
        char input[MAX_SIZE];
        printf("\nEnter an IP address to block: ");
        fgets(input, MAX_SIZE, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        // Check if input is a valid IP address
        if (isIpAddress(input)) {
            // Check if firewall is full
            if (firewallIndex < FIREWALL_SIZE) {
                // Add IP address to firewall
                strcpy(firewall[firewallIndex], input);
                firewallIndex++;
                printf("%s has been blocked by the Firewall.\n", input);
                printFirewall();
            }
            else {
                printf("The Firewall is full. Please remove an IP address before adding another.\n");
                printFirewall();
            }
        }
        else {
            printf("Invalid IP address. Please try again.\n");
        }
    }

    return 0;
}

void printFirewall() {
    printf("\n== CURRENT FIREWALL ==\n");
    for (int i = 0; i < firewallIndex; i++) {
        printf("%d. %s\n", i+1, firewall[i]);
    }
}

bool isIpAddress(char* address) {
    // Split address string into individual numbers and '.' characters
    char* token = strtok(address, ".");
    int i = 0;
    int nums[4];
    while (token != NULL) {
        nums[i] = atoi(token);
        if (nums[i] < 0 || nums[i] > 255) {
            return false;
        }
        token = strtok(NULL, ".");
        i++;
    }

    // Check if address has exactly 4 numbers
    if (i != 4) {
        return false;
    }
    return true;
}