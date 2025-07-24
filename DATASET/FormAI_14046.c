//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("\nWelcome to Wi-Fi Signal Strength Analyzer Program!\n\n");
    
    int signal_strength;
    printf("Please enter the Wi-Fi signal strength (0-100): ");
    scanf("%d", &signal_strength);
    
    if (signal_strength >= 0 && signal_strength <= 20) {
        printf("Signal Strength: %d [Poor]\n", signal_strength);
    } else if (signal_strength > 20 && signal_strength <= 40) {
        printf("Signal Strength: %d [Fair]\n", signal_strength);
    } else if (signal_strength > 40 && signal_strength <= 60) {
        printf("Signal Strength: %d [Good]\n", signal_strength);
    } else if (signal_strength > 60 && signal_strength <= 80) {
        printf("Signal Strength: %d [Very Good]\n", signal_strength);
    } else if (signal_strength > 80 && signal_strength <= 100) {
        printf("Signal Strength: %d [Excellent]\n", signal_strength);
    } else {
        printf("Invalid signal strength input.\n");
    }
    
    printf("\nThank you for using our Wi-Fi Signal Strength Analyzer!\n");
    
    return 0;
}