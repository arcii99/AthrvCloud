//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL));
    int signalStrength = rand() % 101; /* Generate random signal strength between 0 and 100 */
    char strengthBars[20][4] = {"|  ", "|  ", "|  ", "|  ", "|  ", "|  ", "|  ", "|  ", "|  ", "|  ", "|  ", "|  ", "|  ", "|  ", "|  ", "|  ", "|  ", "|  ", "|  ", "|  "}; /* Store signal bars characters */
    int index = 0; /* Index to loop through signal bars */
    int i, j; /* Loop counters */
    
    printf("Analyzing Wi-Fi signal strength...\n");
    printf("Signal Strength: %d%%\n", signalStrength);
    printf("Signal Bars: ");
    
    /* Update signal bars based on signal strength */
    for(i = 0; i < signalStrength; i += 5) {
        strengthBars[index++][1] = '|'; /* Update middle bar character */
        if(i+5 <= signalStrength) {
            for(j = 0; j < 3; j++) {
                strengthBars[index++][j] = '_'; /* Update top and bottom bar characters */
            }
        }
    }
    
    /* Print signal bars */
    for(i = 0; i < 20; i++) {
        for(j = 0; j < 3; j++) {
            printf("%c", strengthBars[i][j]);
        }
    }
    printf("\n");
    
    return 0;
}