//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIGNAL 100
#define MIN_SIGNAL 0

int main(void) {
    srand(time(NULL));
    int signalStrength = rand() % (MAX_SIGNAL + 1 - MIN_SIGNAL) + MIN_SIGNAL;
    
    printf("Current Wi-Fi Signal Strength: %d\n", signalStrength);
    
    if(signalStrength >= 70) {
        printf("Signal Strength is Excellent!\n");
    } else if(signalStrength >= 50 && signalStrength < 70) {
        printf("Signal Strength is Good.\n");
    } else if(signalStrength >= 30 && signalStrength < 50) {
        printf("Signal Strength is Fair.\n");
    } else {
        printf("Signal Strength is Poor.\n");
    }
    
    return 0;
}