//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");
    printf("Please enter the signal strength (in dBm): ");
    int signalStrength;
    scanf("%d", &signalStrength);

    if(signalStrength < -70) {
        printf("Signal strength: Strong\n");
    }
    else if (signalStrength >= -70 && signalStrength < -80) {
        printf("Signal strength: Moderate\n");
    }
    else if (signalStrength >= -80 && signalStrength < -90) {
        printf("Signal strength: Weak\n");
    }
    else {
        printf("Signal strength: very weak\n");
    }
    
    printf("Do you want to see the signal strength graph? (y/n)\n");
    char choice;
    scanf(" %c", &choice);

    if(choice == 'y' || choice == 'Y') {
        int numBars = round(abs(signalStrength)/10.0);
        printf("\nSignal Strength Graph:\n");
        for(int i = 1; i <= numBars; i++) {
            printf("|");
            if((i%5) == 0) {
                printf("  %ddBm\n", -1 * i * 10);
            }
        }
    }
    else {
        printf("Okay! Thanks for using the Wi-Fi Signal Strength Analyzer!\n");
    }
    
    return 0;
}