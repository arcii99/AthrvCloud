//FormAI DATASET v1.0 Category: Dice Roller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(){
    return rand() % 6 + 1; // Returns a random number between 1 and 6
}

int main(){
    srand(time(NULL)); // Seed for the random number generator
    int num_of_rolls;
    printf("Enter the number of times you want to roll the dice:\n");
    scanf("%d", &num_of_rolls);
    printf("Rolling the dice %d times...\n", num_of_rolls);
    printf("Here are the results:\n");
    for(int i = 1; i <= num_of_rolls; i++){
        printf("Roll %d: %d\n", i, roll_dice());
    }
    return 0;
}