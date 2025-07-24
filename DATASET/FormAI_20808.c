//FormAI DATASET v1.0 Category: Dice Roller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int sides);

int main(void) {
    srand(time(NULL));    // Seed the random number generator with the current time
    int num_rolls;
    int sides;
    int total = 0;
    printf("Enter the number of dice rolls: ");
    scanf("%d", &num_rolls);
    printf("Enter the number of sides on each die: ");
    scanf("%d", &sides);

    for (int i = 1; i <= num_rolls; i++) {
        total += roll_dice(sides);
        printf("%d ", total);
    }

    printf("\nTotal: %d\n", total);
    return 0;
}

// Recursive function to simulate a dice roll
int roll_dice(int sides) {
    int result = rand() % sides + 1;    // Generate a random number between 1 and the number of sides
    printf("%d ", result);              // Display the result of the current roll
    if (result == sides) {
        printf("\nYou rolled a maximum value!\n");
        return result + roll_dice(sides);    // If the maximum value was rolled, roll again and add the result
    } else {
        return result;
    }
}