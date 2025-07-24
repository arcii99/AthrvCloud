//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");
    printf("Please enter the Wi-Fi signal strength (in decibels): ");
    int signal_strength;
    scanf("%d", &signal_strength);
    if (signal_strength >= -50) {
        printf("Wow, your Wi-Fi is super strong! You must be right next to the router!\n");
    } else if (signal_strength >= -70) {
        printf("Your Wi-Fi signal strength is pretty good! You should be able to stream your favorite shows with no problem.\n");
    } else if (signal_strength >= -80) {
        printf("Your Wi-Fi could be stronger, but it's still good enough to browse the web and check email.\n");
    } else if (signal_strength >= -90) {
        printf("Your Wi-Fi is weak! You might have trouble doing anything more than basic web browsing.\n");
    } else {
        printf("Your Wi-Fi signal is very weak! You might not be able to connect at all!\n");
    }
    return 0;
}