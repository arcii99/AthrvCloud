//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Wi-Fi Signal Strength Analyzer Program!\n");
    int signal_strength = 0;
    int i;
    printf("Please enter the number of times you want to check the signal strength: ");
    scanf("%d", &i);
    printf("Okay, let's get started!\n");
    for (int j = 1; j <= i; j++) {
        printf("Checking signal strength...\n");
        signal_strength = rand() % 101;
        printf("Signal strength: %d%%\n", signal_strength);
        if (signal_strength == 100) {
            printf("Wow, you're connected to NASA!\n");
        }
        else if (signal_strength >= 75) {
            printf("Great signal strength! You can stream Netflix and chill.\n");
        }
        else if (signal_strength >= 50) {
            printf("Not too shabby. You can still browse the internet and check Facebook.\n");
        }
        else if (signal_strength >= 25) {
            printf("Signal strength is weak. You may experience some lag.\n");
        }
        else {
            printf("Connection Lost. Mayday! Mayday!\n");
        }
        printf("------------------\n");
    }
    printf("Thanks for using the Wi-Fi Signal Strength Analyzer Program!\n");
    return 0;
}