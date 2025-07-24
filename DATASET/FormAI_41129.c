//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to get Wi-Fi signal strength
int getWifiSignalStrength() {
    // code to get signal strength from Wi-Fi chip
    int signalStrength = rand() % 101; // randomly generate strength between 0 to 100
    return signalStrength;
}

int main() {
    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n\n");
    char input[20];
    int currentSignalStrength = 0;
    
    while (1) {
        printf("Do you want to check signal strength? (Y/N): ");
        scanf("%s", input);
        if (strcmp(input, "Y") == 0) {
            printf("Checking signal strength...\n");
            currentSignalStrength = getWifiSignalStrength();
            printf("Current signal strength is %d%%.\n", currentSignalStrength);
        } else if (strcmp(input, "N") == 0) {
            printf("Exiting program. Thank you!\n");
            break;
        } else {
            printf("Invalid input. Please enter Y or N.\n");
        }
    }
    
    return 0;
}