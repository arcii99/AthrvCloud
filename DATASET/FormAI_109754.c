//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int signalStrength = 0;
    srand(time(NULL));
    
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n\n");
    
    while (signalStrength < 100) {
        int randomNum = rand() % 10 + 1;
        signalStrength += randomNum;
        
        if (signalStrength < 50) {
            printf("Signal strength is weak: %d\n", signalStrength);
        }
        else if (signalStrength < 80) {
            printf("Signal strength is good: %d\n", signalStrength);
        }
        else {
            printf("Signal strength is excellent: %d\n", signalStrength);
        }
        
        sleep(1);
    }
    
    printf("\nMaximum signal strength reached: %d\n", signalStrength);
    printf("Your Wi-Fi connection is strong and stable.\n");
    
    return 0;
}