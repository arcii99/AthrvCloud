//FormAI DATASET v1.0 Category: Dice Roller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int sides) {
    if (sides == 0) // Base case: if sides is 0, return 0
        return 0;
    // Recursive case: roll a die with the number of sides, and add it to the result of rolling a die with one fewer side
    return rand() % sides + 1 + roll_dice(sides - 1);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int n;
    printf("Enter the number of dice you want to roll: ");
    scanf("%d", &n);
    int sides[n];
    printf("Enter the number of sides for each die, separated by spaces: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sides[i]);
    }
    printf("You rolled: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", roll_dice(sides[i])); // Roll each die and print the result
    }
    printf("\n");
    return 0;
}