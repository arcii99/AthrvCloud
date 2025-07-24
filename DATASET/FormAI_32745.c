//FormAI DATASET v1.0 Category: Dice Roller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sides;
    int rolls;

    printf("Enter the number of sides on the dice: ");
    scanf("%d", &sides);

    if (sides <= 0) {
        printf("Invalid number of sides.\n");
        return 1;
    }

    printf("Enter the number of times to roll the dice: ");
    scanf("%d", &rolls);

    if (rolls <= 0) {
        printf("Invalid number of rolls.\n");
        return 1;
    }

    srand((unsigned int) time(NULL));

    printf("\nRolling the %d-sided dice %d times...\n", sides, rolls);

    int i;
    for (i = 0; i < rolls; i++) {
        int result = rand() % sides + 1;
        printf("Roll %d: %d\n", i + 1, result);
    }

    return 0;
}