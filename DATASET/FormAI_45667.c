//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the Wi-Fi Signal Strength Analyzer Program!\n");
    printf("Please make sure your Wi-Fi is turned on and connected\n\n");
    
    int signal_strength = rand() % 101;

    printf("Analyzing signal strength...\n");
    printf("Your current signal strength is %d%%\n", signal_strength);

    if(signal_strength == 100) {
        printf("Wow, your signal strength is perfect!\n");
    } else if(signal_strength >= 80) {
        printf("Your signal strength is pretty strong, keep it up!\n");
    } else if(signal_strength >= 60) {
        printf("Your signal strength is decent, but could be better.\n");
    } else if(signal_strength >= 40) {
        printf("Your signal strength is weak, you may experience some buffering.\n");
    } else {
        printf("Your signal strength is terrible, good luck trying to load anything.\n");
    }

    printf("\nThank you for using the Wi-Fi Signal Strength Analyzer Program!\n");

    return 0;
}