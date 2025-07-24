//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: enthusiastic
#include <stdio.h>

int main() {
    printf("Welcome to the Wi-Fi Signal Strength Analyzer program.\n");

    // Ask user for input
    printf("Please enter the strength of the Wi-Fi signal (in dBm): ");
    int signal_strength;
    scanf("%d", &signal_strength);

    // Analyze the signal strength
    if (signal_strength >= -30) {
        printf("Wow, you have an excellent signal strength!\n");
    } else if (signal_strength >= -60) {
        printf("Your signal strength is good enough for most applications.\n");
    } else if (signal_strength >= -80) {
        printf("Your signal strength is not great, but should still work.\n");
    } else if (signal_strength >= -100) {
        printf("Your signal strength is too weak to use.\n");
    } else {
        printf("Your signal strength is extremely weak. Please move closer to a Wi-Fi access point.\n");
    }

    // Ask user if they want to analyze another signal
    printf("Do you want to analyze another Wi-Fi signal? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    // Repeat the program if desired
    if (choice == 'y' || choice == 'Y') {
        main();
    } else {
        printf("Thank you for using the Wi-Fi Signal Strength Analyzer program.\n");
    }

    return 0;
}