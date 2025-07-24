//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");
    printf("Please enter the signal strength in decibels (dBm): ");

    int signal_strength;
    scanf("%d", &signal_strength);

    if (signal_strength >= -30) {
        printf("\nWow, that's some strong Wi-Fi! You must be right next to the router.\n");
    } else if (signal_strength >= -67) {
        printf("\nYour Wi-Fi is looking good! You're probably in the same room as the router.\n");
    } else if (signal_strength >= -70) {
        printf("\nYour Wi-Fi is okay but it could be better. Maybe try moving closer to the router?\n");
    } else if (signal_strength >= -80) {
        printf("\nYour Wi-Fi is pretty weak. You might want to switch to a different network or move closer to the router.\n");
    } else {
        printf("\nOh no, your Wi-Fi signal is almost non-existent! You're better off using carrier pigeon.\n");
    }

    printf("\nThank you for using the Wi-Fi Signal Strength Analyzer! Have a great day!\n");
    
    return 0;
}