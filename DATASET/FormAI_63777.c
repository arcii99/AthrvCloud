//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char networkName[50]; // declaring network name variable
    int signalStrength; // declaring signal strength variable

    printf("Enter your Wi-Fi network name: ");
    scanf("%s", networkName);

    printf("Enter signal strength (in percentage): ");
    scanf("%d", &signalStrength);

    /* Checking for invalid input */
    if (signalStrength < 0 || signalStrength > 100) {
        printf("Invalid signal strength. Please enter a value between 0-100.\n");
        return 1;
    }

    /* Displaying the Wi-Fi signal strength */
    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("Network Name: %s\n", networkName);

    if (signalStrength <= 30) {
        printf("Signal Strength: Weak\n");
    } else if (signalStrength <= 70) {
        printf("Signal Strength: Moderate\n");
    } else {
        printf("Signal Strength: Strong\n");
    }

    return 0; // Indicating successful termination of the program
}