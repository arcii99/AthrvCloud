//FormAI DATASET v1.0 Category: Dice Roller ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sum = 0;
    int rolls[5];
    srand(time(NULL));
    
    printf("Rolling the dice...\n");
    for (int i = 0; i < 5; i++) {
        rolls[i] = rand() % 6 + 1;
        sum += rolls[i];
        printf("Die %d: %d\n", i+1, rolls[i]);
    }
    
    printf("Total sum: %d\n", sum);
    
    return 0;
}