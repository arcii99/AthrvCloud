//FormAI DATASET v1.0 Category: Random ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rollDice(int sides) {
    int roll = rand() % sides + 1;
    printf("You rolled a %d on a %d-sided dice!\n", roll, sides);
    printf("Would you like to roll again? (Y/N)");
    char answer;
    scanf("%c", &answer);
    if (answer == 'Y' || answer == 'y') {
        rollDice(sides);
    } else {
        printf("Thanks for playing!\n");
    }
}

int main() {
    int sides;
    printf("Welcome to the recursive dice rolling game!\n");
    printf("Please enter the number of sides on your dice: ");
    scanf("%d", &sides);
    srand(time(NULL));
    rollDice(sides);
    return 0;
}