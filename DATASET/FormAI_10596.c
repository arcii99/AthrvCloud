//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int wifiStrength, i,j;
    srand(time(0));
    
    printf("**** Wi-Fi Signal Strength Analyzer ****\n");
    
    // Generate and print random strengths for 5 different locations
    for(i=0; i<5; i++) {
        wifiStrength = rand()%101; // Generate random strength between 0 and 100
        printf("Location %d: Signal Strength = %d%%\n", i+1, wifiStrength);
        
        // Print Wi-Fi signal bar graph for the strength
        printf("  |");
        for(j=0; j<wifiStrength/10; j++) {
            printf("##");
        }
        printf("\n");
    }
    
    return 0;
}