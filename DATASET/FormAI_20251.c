//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Surprise! Welcome to the Wi-Fi Signal Strength Analyzer program!\n");

    char networkName[25];
    int signalStrength;

    printf("Please enter the name of your Wi-Fi network (up to 25 characters): ");
    scanf("%s", networkName);

    printf("Please enter the signal strength of your Wi-Fi (0-100): ");
    scanf("%d", &signalStrength);

    if (signalStrength >= 90) {
        printf("WOW! Your Wi-Fi signal strength for '%s' is amazing! You must be standing right next to the router!\n", networkName);
    } else if (signalStrength >= 70) {
        printf("Your Wi-Fi signal strength for '%s' is pretty good!\n", networkName);
    } else if (signalStrength >= 50) {
        printf("Your Wi-Fi signal strength for '%s' is decent, but could be better.\n", networkName);
    } else if (signalStrength >= 30) {
        printf("Your Wi-Fi signal strength for '%s' is weak. Time to move closer to the router!\n", networkName);
    } else {
        printf("Uh oh! Your Wi-Fi signal strength for '%s' is very weak. You might need a Wi-Fi range extender.\n", networkName);
    }

    printf("Thank you for using the Wi-Fi Signal Strength Analyzer program. Have a nice day!\n");

    return 0;
}