//FormAI DATASET v1.0 Category: Temperature monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float temperature = 0.0;
    time_t t;
    srand((unsigned) time(&t));
    int random_num = (rand() % 100) - 50; // generates a random number between -50 and 50
    
    temperature += random_num; // adds the random number to the temperature
    printf("Temperature monitor activated.\n");
    printf("Current temperature: %.2f C.\n", temperature);
    
    if(temperature < 0) {
        printf("Warning: temperature below freezing point.\n");
    } else if(temperature > 100) {
        printf("Warning: temperature exceeds boiling point.\n");
    } else {
        printf("Temperature within normal range.\n");
    }
    
    return 0;
}