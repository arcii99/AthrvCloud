//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to Wi-Fi Signal Strength Analyzer! \n");

    // Ask user to enter signal strength in dBm
    printf("Please enter Wi-Fi signal strength in dBm: ");
    int signal_strength;
    scanf("%d", &signal_strength);

    // Analyze signal strength
    if (signal_strength > -30) {
        printf("Excellent signal strength! You are very close to the Wi-Fi router.\n");
    } else if (signal_strength > -50) {
        printf("Good signal strength. You can surf the internet without any interruption.\n");
    } else if (signal_strength > -70) {
        printf("Fair signal strength. You may experience some lag while browsing.\n");
    } else if (signal_strength > -90) {
        printf("Poor signal strength. You may experience frequent disconnections.\n");
    } else {
        printf("No signal. Please check if the Wi-Fi router is turned on and in range.\n");
    }

    printf("Thank you for using Wi-Fi Signal Strength Analyzer!\n");

    return 0;
}