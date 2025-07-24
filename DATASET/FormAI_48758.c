//FormAI DATASET v1.0 Category: Dice Roller ; Style: interoperable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int rollDice() {
    return (rand() % 6) +1;
}

int main(void) {
    int rolls, i, dice1, dice2;
    printf("Enter the number of rolls: ");
    scanf("%d", &rolls);

    // Seed the random number generator
    srand(time(NULL));

    printf("\nRolling %d dice:\n", rolls);
    for (i = 0; i < rolls; i++) {
        dice1 = rollDice();
        dice2 = rollDice();
        printf("Roll %d: %d + %d = %d\n", i+1, dice1, dice2, dice1+dice2);
    }

    return 0;
}