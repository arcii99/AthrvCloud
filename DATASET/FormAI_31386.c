//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate random Wi-Fi signal strength values
int generateRandomSignalStrength() {
    int min = -100;
    int max = -30;
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize variables
    int signalStrength;
    char ssid[50];
    
    // Get the SSID from the user
    printf("Enter the SSID you want to analyze: ");
    scanf("%s", ssid);
    
    // Loop to generate signal strength values and display them
    for (int i = 0; i < 10; i++) {
        signalStrength = generateRandomSignalStrength();
        
        // Display the signal strength along with a message based on its value
        printf("Signal strength for %s: %d dBm - ", ssid, signalStrength);
        
        if (signalStrength >= -30) {
            printf("Excellent signal!\n");
        } else if (signalStrength >= -50) {
            printf("Good signal.\n");
        } else if (signalStrength >= -70) {
            printf("Fair signal.\n");
        } else {
            printf("Poor signal.\n");
        }
    }
    
    return 0;
}