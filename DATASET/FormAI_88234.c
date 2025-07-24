//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ada Lovelace
/*
    Title: C Wi-Fi Signal Strength Analyzer
    Author: Ada Lovelace
    Description: This program receives the Wi-Fi signal strength from a device and displays it to the user
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Define the maximum length of the signal strength string
#define MAX_LENGTH 15

int main() {
    // Define variables
    char strength[MAX_LENGTH];
    int signal_strength;

    // Continuously loop to receive signal strength and display it to the user
    while(1) {
        // Receive signal strength from device
        printf("\nPlease enter the Wi-Fi signal strength: ");
        scanf("%s", strength);

        // Check for valid input
        if(strlen(strength) > MAX_LENGTH) {
            printf("Signal strength value is too long. Please try again.\n");
            continue;
        }

        // Convert signal strength to integer
        signal_strength = atoi(strength);

        // Check for valid integer input
        if(signal_strength == 0 && strength[0] != '0') {
            printf("Invalid signal strength value. Please try again.\n");
            continue;
        }

        // Display signal strength to user
        printf("\nSignal strength is: %d dBm\n", signal_strength);
        
        // Wait for 1 second before prompting for next signal strength value
        sleep(1);
    }

    return 0;
}