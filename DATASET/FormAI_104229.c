//FormAI DATASET v1.0 Category: Dice Roller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i = 0, num = 0, rolls = 0, dice = 0;
    srand(time(NULL)); // seed random number generator with current time
    
    // prompt user for number of dice
    printf("How many dice do you want to roll? ");
    scanf("%d", &dice);
    
    // prompt user for number of rolls
    printf("How many times do you want to roll the dice? ");
    scanf("%d", &rolls);

    // roll the dice and print the results
    printf("Rolling %d dice %d times...\n", dice, rolls);
    for (i = 0; i < rolls; i++) {
        printf("Roll %2d: ", i+1);
        num = 0;
        for (int j = 0; j < dice; j++) {
            num += rand() % 6 + 1;
        }
        printf("%d\n", num);
    }
    
    return 0;
}