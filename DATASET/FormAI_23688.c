//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: visionary
#include<stdio.h>
#include<stdlib.h>

int main(){
    int signals[10] = {-45, -70, -60, -50, -80, -85, -55, -70, -60, -50};
    int i;
    int avg = 0;
    int max_signal = signals[0];
    int min_signal = signals[0];

    // Calculate average signal strength
    for(i=0; i<10; i++){
        avg += signals[i];
        if(signals[i] > max_signal){
            max_signal = signals[i];
        }
        if(signals[i] < min_signal){
            min_signal = signals[i];
        }
    }
    avg /= 10;

    // Print results
    printf("Average signal strength: %d dBm\n", avg);
    printf("Max signal strength: %d dBm\n", max_signal);
    printf("Min signal strength: %d dBm\n", min_signal);

    // Check signal strength quality
    if(max_signal > -50){
        printf("Excellent signal strength\n");
    }
    else if(max_signal > -60){
        printf("Good signal strength\n");
    }
    else if(max_signal > -70){
        printf("Fair signal strength\n");
    }
    else{
        printf("Poor signal strength\n");
    }

    return 0;
}