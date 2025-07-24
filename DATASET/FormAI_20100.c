//FormAI DATASET v1.0 Category: Firewall ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BLOCKED_IPS 20 // Maximum number of blocked IP addresses
#define MAX_IP_LENGTH 16 // Maximum length of IP address string

int main() {
    char blocked_ips[BLOCKED_IPS][MAX_IP_LENGTH]; // Array of blocked IP addresses
    int num_blocked_ips = 0; // Number of currently blocked IP addresses

    printf("Welcome to My Firewall!\n");

    while (1) { // Loop to keep firewall program running
        char input[MAX_IP_LENGTH+1]; // Input buffer for IP addresses
        printf("\nEnter an IP address to block or type 'exit' to quit: ");
        scanf("%16s", input); // Read in IP address input

        if (strcmp(input, "exit") == 0) { // User wants to exit
            break; // Exit loop and program
        }
        
        if (num_blocked_ips == BLOCKED_IPS) { // Maximum number of blocked IPs reached
            printf("Sorry, you cannot block any more IP addresses.\n");
            continue; // Start next iteration of loop to retry input
        }

        strcpy(blocked_ips[num_blocked_ips], input); // Add input IP address to array of blocked IPs
        num_blocked_ips++; // Increment count of blocked IPs

        printf("Successfully blocked IP address %s.\n", input);
    }

    printf("Blocked IP addresses:\n");
    for (int i = 0; i < num_blocked_ips; i++) { // Loop through all blocked IP addresses
        printf("%s\n", blocked_ips[i]); // Print each blocked IP address
    }

    return 0;
}