//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

int main() {
    int signal_strength;
    
    printf("Welcome to the Wi-Fi Signal Strength Analyzer\n");
    printf("--------------------------------------------\n");
    
    while(1) {
        printf("Please enter the signal strength (0-100): ");
        scanf("%d", &signal_strength);
        
        if(signal_strength >= MIN_SIGNAL_STRENGTH && signal_strength <= MAX_SIGNAL_STRENGTH) {
            break;
        } else {
            printf("Invalid signal strength. Please enter again.\n");
        }
    }
    
    // Calculate the signal quality
    double signal_quality = (double)(signal_strength - MIN_SIGNAL_STRENGTH) / (double)(MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH) * 100;
    
    // Determine the signal strength category
    char* category = "";
    
    if(signal_quality <= 20) {
        category = "Very Poor";
    } else if(signal_quality <= 40) {
        category = "Poor";
    } else if(signal_quality <= 60) {
        category = "Fair";
    } else if(signal_quality <= 80) {
        category = "Good";
    } else {
        category = "Excellent";
    }
    
    printf("\n");
    printf("Signal Strength: %d%%\n", signal_strength);
    printf("Signal Quality: %.1f%%\n", signal_quality);
    printf("Category: %s\n", category);
    
    return 0;
}