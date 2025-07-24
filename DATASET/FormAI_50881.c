//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int signalStrength[10];
    int maxStrength = 0, minStrength = 100;
    int totalStrength = 0;
    float avgStrength;
    srand(time(0));

    // generate random signal strengths
    for(int i=0; i<10; i++){
        signalStrength[i] = (rand() % 70) + 30;
        totalStrength += signalStrength[i];
        if(signalStrength[i] > maxStrength){
            maxStrength = signalStrength[i];
        }
        if(signalStrength[i] < minStrength){
            minStrength = signalStrength[i];
        }
    }
    avgStrength = (float) totalStrength / 10;

    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("------------------------------\n");
    printf("Signal Strengths: ");
    for(int i=0; i<10; i++){
        printf("%d, ", signalStrength[i]);
    }
    printf("\n\n");
    printf("Maximum Strength: %d\n", maxStrength);
    printf("Minimum Strength: %d\n", minStrength);
    printf("Average Strength: %0.2f\n", avgStrength);

    return 0;
}