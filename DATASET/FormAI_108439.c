//FormAI DATASET v1.0 Category: Dice Roller ; Style: shape shifting
// A Dice Rolling program with Shape Shifting feature

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Seed the random number generator

    printf("Welcome to the Shape Shifting Dice Rolling Program!\n");

    int sides = 6;  // Default number of dice sides
    char shape = 'c';  // Default dice shape

    printf("What shape would you like your dice to be? 'c' for cube, 's' for sphere: ");
    scanf("%c", &shape);

    if (shape == 's') {
        printf("You have chosen a spherical dice! How many sides would you like your dice to have? ");
        scanf("%d", &sides);
    } else {
        printf("You have chosen a cubic dice! How many sides would you like your dice to have? ");
        scanf("%d", &sides);
    }

    printf("You have chosen a %c-shaped dice with %d sides. Let's roll!\n", shape, sides);

    int roll = rand() % sides + 1;  // Roll the dice
    printf("You rolled a %d!\n", roll);

    return 0;
}