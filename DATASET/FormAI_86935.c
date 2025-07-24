//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIGNAL_STRENGTH 100
#define NUM_OF_READINGS 10

int main(){
    int readings[NUM_OF_READINGS];
    int i;
    int current_strength;
    int total_strength;
    srand(time(NULL));

    printf("====================\n");
    printf("Wi-Fi Signal Analyzer\n");
    printf("====================\n");

    for(i=0; i<NUM_OF_READINGS; i++){
        current_strength = rand() % MAX_SIGNAL_STRENGTH; //generate random signal strength
        printf("Reading %d: %d\n", i+1, current_strength);
        readings[i] = current_strength;
        total_strength += current_strength;
    }

    float average_strength = (float)total_strength / NUM_OF_READINGS;
    printf("====================\n");
    printf("Results\n");
    printf("====================\n");
    printf("Average Signal Strength: %.2f\n", average_strength);

    if(average_strength > 75){
        printf("Signal strength is excellent\n");
    } else if(average_strength > 50){
        printf("Signal strength is good\n");
    } else if(average_strength > 25) {
        printf("Signal strength is weak\n");
    } else {
        printf("Signal strength is very weak\n");
    }

    return 0;
}